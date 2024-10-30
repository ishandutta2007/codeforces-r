


 #include <stdio.h>
 #include <bits/stdc++.h>






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

struct empty_t {};

namespace tuple_access {

  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  typename tuple_element<0,T>::type& operator^(T& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type const& operator^(T const& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type&& operator^(T&& v, xx_t) { return get<0>(v); }

  template<class T>
  typename tuple_element<1,T>::type& operator^(T& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type const& operator^(T const& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type&& operator^(T&& v, yy_t) { return get<1>(v); }

  template<class T>
  typename tuple_element<2,T>::type& operator^(T& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type const& operator^(T const& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type&& operator^(T&& v, zz_t) { return get<2>(v); }

  template<class T>
  typename tuple_element<3,T>::type& operator^(T& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type const& operator^(T const& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type&& operator^(T&& v, ww_t) { return get<3>(v); }
}
using namespace tuple_access;


int ilog2(int x){ return 31 - __builtin_clz(x); }

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


template <class SegmentOp>
struct segment_tree {
  using node = typename SegmentOp::node;
  using value = typename SegmentOp::value;

  int n;
  vector<node> A;

  segment_tree() = default;
  segment_tree(int n_) : n(2 << ilog2(n_)), A(2 * n) {}

  void update(int i) {
    if (i < n) SegmentOp::op(A[i], A[2 * i], A[2 * i + 1]);
  }

  void build() { for(li i = (n - 1); i >= (li)(1); --i) update(i); }

  void push(int i, int a, int b) {
    if(i < n) {
      int c = (a + b) / 2;
      SegmentOp::push(A[i], (c - a + 1), A[2 * i], (b - c), A[2 * i + 1]);
    }
  }

  void set_point_(int i, int a, int b, int x, value const &v) {
    if(a == b) {
      A[i] = node(v);
      return;
    }
    push(i, a, b);
    int c = (a + b) / 2;
    if(x <= c) set_point_(2 * i, a, c, x, v);
    else set_point_(2 * i + 1, c + 1, b, x, v);
    update(i);
  }

  void set_point(int x, value const &v) { set_point_(1, 0, n - 1, x, v); }
  void add_range_(int i, int a, int b, int l, int r, value const &v) {
    if(l <= a && b <= r) {
      SegmentOp::add_range(b - a + 1, A[i], v);
      return;
    }
    push(i, a, b);
    int c = (a + b) / 2;
    if(r <= c) {
      add_range_(2 * i, a, c, l, r, v);
    } else if(l >= c + 1) {
      add_range_(2 * i + 1, c + 1, b, l, r, v);
    } else {
      add_range_(2 * i, a, c, l, r, v);
      add_range_(2 * i + 1, c + 1, b, l, r, v);
    }
    update(i);
  }

  void add_range(int l, int r, value const &v) {
    add_range_(1, 0, n - 1, l, r, v);
  }

  node query_range_(int i, int a, int b, int l, int r) {
    if(l <= a && b <= r) return A[i];
    push(i, a, b);
    int c = (a + b) / 2;
    if(r <= c) {
      return query_range_(2 * i, a, c, l, r);
    } else if(l >= c + 1) {
      return query_range_(2 * i + 1, c + 1, b, l, r);
    } else {
      node nl = query_range_(2 * i, a, c, l, r);
      node nr = query_range_(2 * i + 1, c + 1, b, l, r);
      node ans;
      SegmentOp::op(ans, nl, nr);
      return ans;
    }
  }

  node query_range(int l, int r) { return l <= r ? query_range_(1, 0, n - 1, l, r) : node(); }
};

template <class T, class O = std::plus<T>>
struct sum_segment_op {
  using node = T;
  using value = T;

  static void push(node &, li, node &, li, node &) {}

  static void op(T &ab, T const &a, T const &b) { ab = O()(a, b); }
};

template <class T, class O = std::plus<T>>
struct lazy_sum_segment_op {
  struct node {
    node() = default;
    node(T const &v) : value(v) {}
    T value;
    T delta;
  };
  using value = T;

  static void add_range(li sz, node &a, T const &x) {
    a.value = O()(a.value, T(sz) * x);
    a.delta = x;
  }

  static void push(node &ab, li sza, node &a, li szb, node &b) {
    if(ab.delta != T()) {
      add_range(sza, a, ab.delta);
      add_range(szb, b, ab.delta);
      ab.delta = T();
    }
  }

  static void op(node &ab, node const &a, node const &b) {
    ab.value = O()(a.value, b.value);
    ab.delta = T();
  }
};


template <class T>
struct min_segment_op {
  struct node {
    T value;
    node() { value = numeric_limits<T>::max(); }
    node(T const& v) : value(v) { }
    operator T() const { return value; }
  };
  using value = T;

  static void push(node &, li, node &, li, node &) {}
  static void op(node &ab, node const &a, node const &b) { ab.value = min(a.value, b.value); }
};

template <class T>
struct lazy_min_segment_op {
  struct node {
    T value;
    li idx;
    node() { value = numeric_limits<T>::max(); }
    node(T const& v) : value(v) { }
    operator T() const { return value; }
  };
  using value = T;

  static void push(node & ab, li, node & a, li, node & b) {
    a.value = max(a.value, ab.value);
    b.value = max(b.value, ab.value);
  }

  static void add_range(li, node &a, T const& x) {
    a.value = max(a.value, x);
  }

  static void op(node &ab, node const &a, node const &b) { ab.value = min(a.value, b.value); }
};

template <class T>
struct max_segment_op {
  struct node {
    T value;
    node() { value = numeric_limits<T>::min(); }
    node(T const& v) : value(v) { }
    operator T() const { return value; }
  };
  using value = T;

  static void push(node &, li, node &, li, node &) {}
  static void op(node &ab, node const &a, node const &b) { ab.value = max(a.value, b.value); }
};

const li MOD = 982451653;
const li P = 4643;
const li N = 2e5+1;
li H[N];

struct plop {
  plop() {
    l0=l1=l2=0;
    h=0;
  }
  plop(char c) {
    if(c == '0') {
      l0 = 0; l1 = 1; l2 = 0;
      h = 0;
    }else if(c == '1'){
      l0 = 0; l1 = 0; l2 = 1;
      h = 0;
    }
  }
  li l0, l1, l2;
  li h;

  bool operator==(plop const& o) const {
    return tie(l0,l1,l2,h) == tie(o.l0,o.l1,o.l2,o.h);
  }
};

li comb_hash(li , li h1, li l2, li h2) {
  return (h1 * H[l2] + h2) % MOD;
    }

plop combine(plop const& a, plop const& b) {
  plop c;
  if(b.l1 == 0) {
    c = a;
    c.l2 += b.l2;
    return c;
  }
  if(a.l1 == 0) {
    if((a.l2+b.l0)%2 == 0){
      c.l2 = a.l2+b.l0+b.l2;
      c.l1 = a.l1+b.l1;
      c.l0 = 0;
      c.h = b.h;
    }else{
      c.l2 = a.l2 + b.l0 + b.l2 - 1;
      c.l1 = b.l1;
      c.l0 = 1;
      c.h = b.h;
    }
    return c;
  }
  c.l0 = a.l0;
  if((a.l2+b.l0)%2 == 0) {
    c.l2 = a.l2+b.l0+b.l2;
    c.l1 = a.l1+b.l1;
    c.h = comb_hash(a.l1, a.h, b.l1, b.h);
  }else{
    assert(b.l0 <= 1);
    c.l2 = a.l2 + b.l0 + b.l2 - 1;
    c.l1 = a.l1 + 1 + b.l1;
    c.h = comb_hash(a.l1, a.h, b.l1+1, comb_hash(1, 1, b.l1, b.h));
  }
  return c;
}

struct node_op {
  struct node {
    plop value;
    node() { value = plop(); }
    node(plop const& v) : value(v) { }
    operator plop() const { return value; }
  };
  using value = plop;

  static void push(node &, li, node &, li, node &) {}
  static void op(node &ab, node const &a, node const &b) { ab.value = combine(a.value, b.value); }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  H[0] = 1; for(li i = 0; i < (li)(N-1); ++i) H[i+1] = (H[i]*P)%MOD;

  int n; cin>>n;
  string s; cin>>s;
  segment_tree<node_op> A(n);
  for(li i = 0; i < (li)(n); ++i) A.set_point(i, plop(s[i]));






  int q; cin>>q;
  for(li q_ = 0; q_ < (li)(q); ++q_) {
    li l1,l2,len; cin>>l1>>l2>>len;
    l1--; l2--;
    plop p1 = A.query_range(l1, l1+len-1);
    plop p2 = A.query_range(l2, l2+len-1);


    if(p1 == p2) {
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }

  return 0;
}