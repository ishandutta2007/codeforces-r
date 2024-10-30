#ifndef LOCAL
#define DUMP(...) void()
#define NDEBUG
#include <bits/stdc++.h>
#include <unistd.h>
#include <x86intrin.h>
#endif

using namespace std;
using i64 = long long;

#define ALL(r) ::begin(r), ::end(r)

#define TGT(s) __attribute__((target(#s)))
TGT(bmi) int bsf(i64 x) { return int(_tzcnt_u64(x)); }
TGT(lzcnt) int bsr(i64 x) { return 63 - int(_lzcnt_u64(x)); }
TGT(popcnt) int popcnt(i64 x) { return int(_mm_popcnt_u64(x)); }
TGT(bmi2) i64 bzhi(i64 x, int n) { return _bzhi_u64(x, n); }
TGT(bmi2) i64 pdep(i64 x, i64 mask) { return _pdep_u64(x, mask); }
TGT(bmi2) i64 pext(i64 x, i64 mask) { return _pext_u64(x, mask); }
#undef TGT

template <class T> bool is_pow2(T x) { return x >= 1 && (x & (x - 1)) == 0; }
template <class T> T floor_pow2(T x) { return assert(x >= 1), T(1) << bsr(x); }
template <class T> T ceil_pow2(T x) { return x <= 1 ? 1 : T(2) << bsr(x - 1); }
template <class T> T floor_div(T a, T b) { return assert(b), a / b - ((a ^ b) < 0 && a % b); }
template <class T> T ceil_div(T a, T b) { return assert(b), a / b + ((a ^ b) >= 0 && a % b); }

template <class T> constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class U = T> bool chmin(T& a, U&& b) { return b < a ? a = forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T& a, U&& b) { return a < b ? a = forward<U>(b), true : false; }

template <class T, class N, class Op> constexpr T power(T x, N n, Op op) {
  for (assert(n >= 1); ~n & 1; n >>= 1) x = op(x, x);
  T res = x;
  while (n >>= 1) x = op(x, x), n & 1 && (res = op(move(res), x), 0);
  return res;
}
template <class T, class N> constexpr T power(T x, N n) {
  return n ? power(n < 0 ? T(1) / x : x, abs(n), multiplies{}) : 1;
}

template <class F> struct Fix {
  F f_;
  Fix(F f) : f_(move(f)) {}
  template <class... Ts> decltype(auto) operator()(Ts&&... xs) const { return f_(ref(*this), forward<Ts>(xs)...); }
};

template <class T> struct rep {
  struct I : iterator<bidirectional_iterator_tag, T, T, void, T> {
    T i_, d_;
    operator T() const { return i_; }
    T operator*() const { return i_; }
    I& operator++() { return i_ += d_, *this; }
    I& operator--() { return i_ -= d_, *this; }
  } b_, e_;
  rep(T l, T r, T d = 1) : b_{{}, l, d}, e_{{}, l + max<T>(ceil_div(r - l, d), 0) * d, d} {}
  explicit rep(T n) : rep(0, n) {}
  I begin() const { return b_; }
  I end() const { return e_; }
};
struct Rev {
  template <class R> struct V {
    R r_;
    auto begin() const { return reverse_iterator(::end(r_)); }
    auto end() const { return reverse_iterator(::begin(r_)); }
  };
  template <class R> friend V<R> operator|(R&& r, Rev) { return {forward<R>(r)}; }
} rev;

template <class R> int sz(R&& r) { return int(size(forward<R>(r))); }
template <class I> int sz(I b, I e) { return int(distance(b, e)); }

template <class, class = void> struct IsRange : false_type {};
template <class T>
struct IsRange<T, enable_if_t<!__is_char<decay_t<decltype(*begin(declval<T&>()))>>::__value>> : true_type {};

#define UNARY_OP(op) \
  template <class A> enable_if_t<IsRange<A>{}, decay_t<A>> std::operator op(A&& a) { \
    auto res = forward<A>(a); \
    for (auto&& e : res) e = op move(e); \
    return res; \
  }
UNARY_OP(+)
UNARY_OP(-)
UNARY_OP(~)
#undef UNARY_OP
#define BINARY_OP(op) \
  template <class A, class B> enable_if_t<IsRange<A>{}, A&> operator op##=(A&& a, const B& b) { \
    if constexpr (IsRange<B>{}) { \
      assert(sz(a) == sz(b)); \
      auto it = begin(b); \
      for (auto&& e : a) e op## = *it++; \
    } else { \
      for (auto&& e : a) e op## = b; \
    } \
    return a; \
  } \
  template <class A, class B, class = enable_if_t<IsRange<A>{} || IsRange<B>{}>> auto std::operator op(A&& a, B&& b) { \
    if constexpr (!IsRange<A>{} || (is_lvalue_reference_v<A> && !is_lvalue_reference_v<B>)) { \
      auto res = forward<B>(b); \
      if constexpr (IsRange<A>{}) { \
        assert(sz(a) == sz(b)); \
        auto it = begin(a); \
        for (auto&& e : res) e = *it++ op move(e); \
      } else { \
        for (auto&& e : res) e = a op move(e); \
      } \
      return res; \
    } else { \
      auto res = forward<A>(a); \
      res op## = b; \
      return res; \
    } \
  }
BINARY_OP(+)
BINARY_OP(-)
BINARY_OP(*)
BINARY_OP(/)
BINARY_OP(%)
BINARY_OP(&)
BINARY_OP(|)
BINARY_OP(^)
BINARY_OP(<<)
BINARY_OP(>>)
#undef BINARY_OP

struct Scan {
  char b_[1 << 15], c_;
  int l_ = sz(b_), r_ = l_;
  bool go(char& c) {
    for (;; ++l_) {
      if (r_ - l_ < 64) r_ = (r_ - l_) + read(STDIN_FILENO, move(b_ + l_, b_ + r_, b_), sz(b_) - (r_ - l_)), l_ = 0;
      if (l_ == r_) return c = {}, false;
      if (b_[l_] > ' ') return c = b_[l_++], true;
    }
  }
  bool go(string& s) {
    if (!go(c_)) return s = {}, false;
    for (s = c_; b_[l_] > ' '; s += c_) go(c_);
    return true;
  }
  template <class T> enable_if_t<is_integral_v<T>, bool> go(T& x) {
    if (!go(c_)) return x = {}, false;
    make_unsigned_t<T> u = (c_ == '-' ? b_[l_++] : c_) & 15;
    for (; b_[l_] > ' '; ++l_) (u *= 10) += b_[l_] & 15;
    return x = c_ == '-' ? -u : u, true;
  }
  template <class T> enable_if_t<is_floating_point_v<T>, bool> go(T& x) {
    if (!go(c_)) return x = {}, false;
    char* p;
    if constexpr (is_same_v<T, float>) x = strtof(b_ + (l_ - 1), &p);
    if constexpr (is_same_v<T, double>) x = strtod(b_ + (l_ - 1), &p);
    if constexpr (is_same_v<T, long double>) x = strtold(b_ + (l_ - 1), &p);
    return l_ = sz(b_, p), true;
  }
  template <class C> enable_if_t<IsRange<C>{}, bool> go(C& c) {
    for (auto&& e : c)
      if (!go(e)) return c = {}, false;
    return true;
  }
  template <class... Ts> bool operator()(Ts&... xs) { return (... && go(xs)); }
} scan;
template <class T = int, class... Args> T input(Args&&... args) {
  T res(forward<Args>(args)...);
  scan(res);
  return res;
}
template <class... Ts> enable_if_t<sizeof...(Ts) >= 2, tuple<Ts...>> input() {
  tuple<Ts...> res;
  apply([](auto&... e) { (..., scan(e)); }, res);
  return res;
}
struct Print {
  char b_[1 << 15];
  int i_ = 0;
  void go(char c = '\0') {
    if (sz(b_) - i_ < 64 || c == -1) write(STDOUT_FILENO, b_, i_), i_ = 0;
    if (c > 0) b_[i_++] = c;
  }
  void go(string_view s) {
    for (char c : s) go(c);
  }
  template <class T> enable_if_t<is_integral_v<T>> go(T x) { go(), i_ = sz(b_, to_chars(b_ + i_, end(b_), x).ptr); }
  template <class T> enable_if_t<is_floating_point_v<T>> go(T x) {
    go(), i_ += snprintf(b_ + i_, sz(b_) - i_, "%.20Lf", (long double)x);
  }
  template <class R> enable_if_t<IsRange<R>{}> go(R&& r) {
    char c = '\0';
    for (auto&& e : r) go(exchange(c, ' ')), go(e);
  }
  template <class... Ts> void operator()(Ts&&... xs) {
    char c = '\0';
    (..., (go(exchange(c, ' ')), go(forward<Ts>(xs)))), go('\n');
  }
  ~Print() { go(char(-1)); }
} print;

struct Graph {
  std::vector<std::array<int, 2>> edges;
  struct Pair_ : std::pair<int, int> {
    using std::pair<int, int>::pair;
    operator int() const { return first; }
  };
  std::vector<Pair_> adj_;
  std::vector<int> pos_;
  Graph() {}
  Graph(int n, int m) : pos_(n + 1) { edges.reserve(m); }
  int n() const { return pos_.size() - 1; }
  int m() const { return edges.size(); }
  void build() {
    for (auto&& [u, v] : edges) ++pos_[u], ++pos_[v];
    std::partial_sum(pos_.begin(), pos_.end(), pos_.begin()), adj_.resize(pos_[n()]);
    for (int e = m(); e--;) adj_[--pos_[edges[e][0]]] = {edges[e][1], e}, adj_[--pos_[edges[e][1]]] = {edges[e][0], e};
  }
  template <class T> struct View_ {
    T *first, *last;
    int size() const { return last - first; }
    T& operator[](int i) const { return *(first + i); }
    T* begin() const { return first; }
    T* end() const { return last; }
  };
  View_<Pair_> operator[](int v) { return {adj_.data() + pos_[v], adj_.data() + pos_[v + 1]}; }
  View_<const Pair_> operator[](int v) const { return {adj_.data() + pos_[v], adj_.data() + pos_[v + 1]}; }
};

struct DfsForest : Graph {
  std::vector<int> was, pe, d, low, sub, deg, in, seq;
  int num_dfs = 0;
  DfsForest() {}
  DfsForest(int n, int m) : Graph(n, m), was(n, -1), pe(n), d(n), low(n), sub(n), deg(n), in(n) { seq.reserve(n); }
  void dfs(int r, bool clear_seq = true) {
    if (clear_seq) seq.clear();
    was[r] = num_dfs, pe[r] = -1, d[r] = 0;
    dfs_impl_(r), ++num_dfs;
  }
  void dfs_all() {
    for (int v = 0, t = num_dfs; v < n(); ++v)
      if (was[v] < t) dfs(v, v == 0);
  }
  int p(int v) const { return ~pe[v] ? edges[pe[v]][0] : -1; }
  View_<Pair_> ch(int v) { return {(*this)[v].begin(), (*this)[v].begin() + deg[v]}; }
  View_<const Pair_> ch(int v) const { return {(*this)[v].begin(), (*this)[v].begin() + deg[v]}; }
  void dfs_impl_(int v) {
    std::stable_partition((*this)[v].begin(), (*this)[v].end(), [&](int u) { return was[u] < num_dfs; });
    low[v] = d[v], sub[v] = 1, deg[v] = 0, in[v] = seq.size(), seq.push_back(v);
    for (auto&& [u, e] : (*this)[v])
      if (was[u] < num_dfs) {
        edges[e] = {v, u};
        was[u] = num_dfs, pe[u] = e, d[u] = d[v] + 1;
        dfs_impl_(u);
        low[v] = std::min(low[v], low[u]), sub[v] += sub[u], ++deg[v];
      } else if (e != pe[v] && d[u] < d[v]) {
        edges[e] = {v, u};
        low[v] = std::min(low[v], d[u]);
      }
  }
};

int main() {
  for (int tt = input(); tt--;) {
    auto [n, k] = input<int, int>();
    auto a = input<vector<int>>(n);
    DfsForest g(n, n - 1);
    g.edges = input<vector<array<int, 2>>>(n - 1) - 1;
    g.build();
    g.dfs(0);
    int x = accumulate(ALL(a), 0, bit_xor{});
    for (int v : g.seq | rev)
      if (v) a[g.p(v)] ^= a[v];
    if (x) {
      if (k == 2) {
        print("NO");
      } else {
        vector<bool> f(n);
        for (int v : g.seq | rev) {
          if (v == 0) break;
          if (a[v] == x) {
            f[v] = true;
          }
          if (f[v]) {
            f[g.p(v)] = true;
          }
        }
        bool ok = false;
        for (int v : rep(n)) {
          int c = 0;
          for (int u : g.ch(v)) c += f[u];
          if (c >= 2 || (a[v] == 0 && c)) {
            ok = true;
            break;
          }
        }
        print(ok ? "YES" : "NO");
      }
    } else {
      print("YES");
    }
  }
}