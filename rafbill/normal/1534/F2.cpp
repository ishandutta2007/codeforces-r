


 #include <stdio.h>
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>






using namespace std;





template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, deque<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}


static inline void debug_impl_seq() {
  cerr << "}";
}

template <class T, class... V>
void debug_impl_seq(T const& t, V const&... v) {
  cerr << t;
  if(sizeof...(v)) { cerr << ", "; }
  debug_impl_seq(v...);
}








using li = long long int;
using lu = long long unsigned;
using ld = long double;


using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

struct uint64_hash {
  static inline uint64_t rotr(uint64_t x, unsigned k) {
    return (x >> k) | (x << (8U * sizeof(uint64_t) - k));
  }

  static inline uint64_t hash_int(uint64_t x) noexcept {
    auto h1 = x * (uint64_t)(0xA24BAED4963EE407);
    auto h2 = rotr(x, 32U) * (uint64_t)(0x9FB21C651E98DF25);
    auto h = rotr(h1 + h2, 32U);
    return h;
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return hash_int(x + FIXED_RANDOM);
  }
};

template <typename K, typename V, typename Hash = uint64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = uint64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

struct empty_t {};

namespace tuple_access {
  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  auto operator&(T&& v, xx_t) -> decltype(get<0>(forward<T>(v))) { return get<0>(forward<T>(v)); }
  template<class T>
  auto operator&(T&& v, yy_t) -> decltype(get<1>(forward<T>(v))) { return get<1>(forward<T>(v)); }
  template<class T>
  auto operator&(T&& v, zz_t) -> decltype(get<2>(forward<T>(v))) { return get<2>(forward<T>(v)); }
  template<class T>
  auto operator&(T&& v, ww_t) -> decltype(get<3>(forward<T>(v))) { return get<3>(forward<T>(v)); }
}
using namespace tuple_access;


template<class Fun>
class letrec_result {
  Fun fun_;
  public:
    template<class T>
    explicit letrec_result(T &&fun): fun_(forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(ref(*this), forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) letrec(Fun &&fun) {
  return letrec_result<decay_t<Fun>>(forward<Fun>(fun));
}

template<class Fun>
class letrec_memo_result {
  Fun fun_;
  public:
    template<class T>
    explicit letrec_memo_result(T &&fun): fun_(forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args const&... args) {
      static map<tuple<Args...>, decltype(fun_(ref(*this), args...))> M;
      auto key = make_tuple(args...);
      auto it = M.find(key);
      if(it != M.end()) return it->second;
      auto r = fun_(ref(*this), args...);
      M[key] = r;
      return r;
    }
};

template<class Fun>
decltype(auto) letrec_memo(Fun &&fun) {
  return letrec_memo_result<decay_t<Fun>>(forward<Fun>(fun));
}

int ilog2(int x){ return 31 - __builtin_clz(x); }

li ilog2(li x){ return 63 - __builtin_clzll(x); }

li ctz(li x) { return __builtin_ctzll(x); }
li clz(li x) { return __builtin_clzll(x); }
li popcount(li x) { return __builtin_popcountll(x); }
li getbit(li x, li i){ return (x>>i)&1; }
li setbit(li x, li i) { return x|(1ll<<i); }
li unsetbit(li x, li i) { return x&~(1ll<<i); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }

template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}

template<typename T>
T icbrt(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}

void scc(vvi const& G, vvi& cs, vi& C, vvi* G_ = 0) {
  int n = G.size();
  vvi G2(n); for(li i = 0; i < (li)(n); ++i) for(int j : G[i]) G2[j].push_back(i);
  cs.clear(); C.assign(n, -1);
  vi A;
  vi E(n);
  function<void(int)> dfs = [&](int i) {
    if(E[i]) return;
    E[i] = 1;
    for(int j : G[i]) dfs(j);
    A.push_back(i);
  };
  for(li i = 0; i < (li)(n); ++i) dfs(i);
  reverse(begin(A), end(A));
  function<void(int, int)> dfs2 = [&](int i, int r) {
    if(C[i] == -1) {
      cs.back().push_back(i); C[i] = r;
      for(int j : G2[i]) dfs2(j, r);
    }
  };
  for(int i : A) if(C[i] == -1) { cs.push_back(vi{}); dfs2(i, cs.size()-1); }
  if(G_) {
    G_->assign(cs.size(), vi{});
    set<pii> M;
    for(li i = 0; i < (li)(n); ++i) for(int j : G[i]) M.insert(make_tuple(C[i], C[j]));
    for(pii p : M) { li a,b; tie(a,b) = p; if(a != b) (*G_)[a].push_back(b); }
  }
}



struct union_find {
  vi A;

  union_find(li n = 0) : A(n) {
    iota(begin(A), end(A), 0);
  }

  li addNode() {
    A.push_back(A.size());
    return A.size()-1;
  }

  li find(li a) {
    return A[a] == a ? a : A[a] = find(A[a]);
  }

  void unite(li a, li b) {
    a = find(a); b = find(b);
    A[a] = b;
  }
};

void process(li n, li m, vector<vector<char>> const& A, vi const& B) {
  vvi G(n*m);
  vi last(m,n);
  vi goal(m,n);
  vi cnt(m,0);

  for(li i = (n-1); i >= (li)(0); --i) {
    for(li j = 0; j < (li)(m); ++j) if(A[i][j] == '#') {
      cnt[j]++;
      if(cnt[j] == B[j]) goal[j] = i;
    }

    for(li j = 0; j < (li)(m); ++j) if(A[i][j] == '#' && last[j] != n) {
      if(last[j] == i+1) { G[i*m+j].emplace_back((i+1)*m+j); G[(i+1)*m+j].emplace_back(i*m+j); }
      else G[i*m+j].emplace_back(last[j]*m+j);
    }

    for(li j = 0; j < (li)(m); ++j) if(A[i][j] == '#') last[j] = i;

    for(li j = 0; j < (li)(m); ++j) if(A[i][j] == '#') {
      if(j>0 && last[j-1] != n) { G[i*m+j].emplace_back(last[j-1]*m+(j-1)); }
      if(j+1<m && last[j+1] != n) { G[i*m+j].emplace_back(last[j+1]*m+(j+1)); }
    }
  }

  vvi cs; vi C;
  vvi H;
  scc(G,cs,C,&H);
  int nh = H.size();
  vi D(nh);
  for(li i = 0; i < (li)(nh); ++i) for(int j : H[i]) D[j]++;
  vi sources;

  for(li i = 0; i < (li)(nh); ++i) if(D[i]==0) {
    bool ok = 0;
    for(int xy : cs[i]) {
      int x = xy/m; int y = xy%m;
      if(A[x][y] == '#') {
        ok=1;
      }
    }
    if(ok) sources.emplace_back(i);
  }

  vi sourceCol(nh,-1);

  for(int i : sources) {
    for(int xy : cs[i]) {
      int x = xy/m; int y = xy%m;
      sourceCol[i] = y;
    }
  }

  sort(begin(sources), end(sources), [&](int i, int j) { return sourceCol[i]<sourceCol[j]; });

  vi isGoal(nh,0);
  vi GL(nh, n*m+1), GR(nh, -1);
  for(li j = 0; j < (li)(m); ++j) if(goal[j] != n) {
    int x = goal[j]*m+j;
    isGoal[C[x]] = 1;
  }

  { vi E(nh,0);
    for(li i = 0; i < (li)(sources.size()); ++i) {
      vi Q;
      Q.push_back(sources[i]); E[i]=1;
      while(!Q.empty()) {
        int y = Q.back(); Q.pop_back();
        if(isGoal[y]) GL[y] = i;
        for(int z : H[y]) if(!E[z]) {
            E[z]=1;
            Q.push_back(z);
        }
      }
    }
  }

  { vi E(nh,0);
    for(li i = ((li)sources.size()-1); i >= (li)(0); --i) {
      vi Q;
      Q.push_back(sources[i]); E[i]=1;
      while(!Q.empty()) {
        int y = Q.back(); Q.pop_back();
        if(isGoal[y]) GR[y] = i;
        for(int z : H[y]) if(!E[z]) {
            E[z]=1;
            Q.push_back(z);
        }
      }
    }
  }

  vii evs;
  for(li i = 0; i < (li)(nh); ++i) if(isGoal[i]) {
    evs.emplace_back(GR[i],GL[i]);
  }
  sort(begin(evs), end(evs));
  li ans = 0;
  li llast = -1;
  for(auto p : evs) {
    li r,l; tie(r,l) = p;
    if(l <= llast) continue;
    llast = r;
    ans++;
  }

  cout << ans << endl;

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,m; cin>>n>>m;
  vector<vector<char>> A(n,vector<char>(m));
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) cin>>A[i][j];

  vi B(m); for(li i = 0; i < (li)(m); ++i) cin>>B[i];

  process(n,m,A,B);
}