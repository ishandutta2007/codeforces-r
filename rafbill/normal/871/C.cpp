#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;

template<typename... As>
struct tpl : public std::tuple<As...> {
  using std::tuple<As...>::tuple;
  tpl(){}
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type const&
  x() const { return get<0>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type&
  x() { return get<0>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type const&
  y() const { return get<1>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type&
  y() { return get<1>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type const&
  z() const { return get<2>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type&
  z() { return get<2>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type const&
  w() const { return get<3>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type&
  w() { return get<3>(*this); }
};

using lli   = long long int;
using llu   = long long unsigned;

using pii   = tpl<lli, lli>;
using piii  = tpl<lli, lli, lli>;
using piiii = tpl<lli, lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

template<size_t... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<size_t, sizeof...(I)> value = { {I...} };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<size_t N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a);
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
ostream& operator<<(ostream& s, tpl<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET UNION FIND ---

struct union_find {
  vi A;

  union_find(lli n = 0) : A(n) {
    iota(all(A), 0);
  }

  lli addNode() {
    A.pb(A.size());
    return A.size()-1;
  }

  lli find(lli a) {
    return A[a] == a ? a : A[a] = find(A[a]);
  }

  void unite(lli a, lli b) {
    a = find(a); b = find(b);
    A[a] = b;
  }
};

// --- END SNIPPET UNION FIND ---

// --- BEGIN SNIPPET MODULAR ---

const lli MOD = 1e9+7;

inline lli fexp(lli a, lli b, lli m=MOD) {
  lli r = 1;
  while(b){
    if(b&1) r = (r*a)%m;
    a = (a*a)%m;
    b /= 2;
  }
  return r;
}

inline lli invmod(lli a, lli m=MOD) {
  return fexp(a, m-2, m);
}

pii egcd(lli a, lli b) {
  if(a%b==0) {
    return mt(0,1);
  }else{
    pii p = egcd(b,a%b);
    int u=p.x(), v=p.y();
    return mt(v, u-(a/b)*v);
  }
}

// solve x*a = b [mod m]
int solveInv(lli a, lli b, lli m) {
  if(b==0) return 0;
  pii p = egcd(a,m);
  lli g=__gcd(m,a);
  return (((b/g)*p.x())%m+m)%m;
}

// --- END SNIPPET MODULAR ---

const int N=120000;
lli F[2*N+1];
lli IF[2*N+1];
lli cnk(lli n, lli k) {
  if(k>n) return 0;
  return F[n]*IF[k]%MOD*IF[n-k]%MOD;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  F[0] = 1; FOR(i,2*N) F[i+1] = F[i]*(i+1)%MOD;
  FOR(i,2*N+1) IF[i] = invmod(F[i]);
  int n; cin>>n;
  vii A;
  union_find uf(n);
  unordered_map<lli,vi> L,R;
  FOR(i,n) {
    lli x,y; cin>>x>>y;
    A.pb(mt(x,y));
    L[x].pb(i);
    R[y].pb(i);
  }
  for(auto const& p : L) for(int i : p.second) {
        uf.unite(p.second[0],i);
      }
  for(auto const& p : R) for(int i : p.second) {
        uf.unite(i,p.second[0]);
      }
  lli ans = 1;
  vvi B(n);
  FOR(i,n) B[uf.find(i)].pb(i);
  FOR(i,n) if(uf.find(i) == i) {
    unordered_set<lli> X,Y;
    for(int j : B[i]) { X.insert(A[j].x()); Y.insert(A[j].y()); }
    lli cur=0;
    FOR(j,B[i].size()+1) {
      cur += cnk(X.size()+Y.size(),j);
      cur %= MOD;
    }
    ans *= cur;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}