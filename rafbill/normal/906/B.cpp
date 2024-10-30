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

pii r(pii a){
  if(a.x() > a.y()) swap(a.x(),a.y());
  return a;
}

bool solve2(int n, int m, vvi& C) {
  vi I(n*m); iota(all(I),0);
  vvi A(n,vi(m));
  FOR(i,n) FOR(j,m) A[i][j] = i*m+j;
  do {
    C.assign(n,vi(m));
    FOR(i,n) FOR(j,m) C[i][j] = I[i*m+j];

    set<pii> Q;
    FOR(i,n) FOR(j,m) {
      if(i+1<n) Q.insert(r(mt(A[i][j],A[i+1][j])));
      if(j+1<m) Q.insert(r(mt(A[i][j],A[i][j+1])));
    }
    set<pii> Q2;
    FOR(i,n) FOR(j,m) {
      if(i+1<n) Q2.insert(r(mt(C[i][j],C[i+1][j])));
      if(j+1<m) Q2.insert(r(mt(C[i][j],C[i][j+1])));
    }
    for(auto p : Q2) if(Q.count(p)) goto l1;
    return 1;
  l1:;
  } while(next_permutation(all(I)));
  return 0;
}

bool solve(int n, int m, vvi& C) {
  if(n == 1) {
    if(m == 2 || m == 3) return 0;
    C.assign(n,vi(m));
    FOR(i,(m+1)/2) C[0][(m+1)/2-1-i] = 2*i;
    FOR(i,(m)/2) C[0][m-1-i] = 2*i+1;
    return 1;
  }
  if(m == 1) {
    if(n == 2 || n == 3) return 0;
    C.assign(n,vi(m));
    FOR(i,(n+1)/2) C[(n+1)/2-1-i][0] = 2*i;
    FOR(i,(n)/2) C[n-1-i][0] = 2*i+1;
    return 1;
  }
  if(n*m<=10) return solve2(n,m,C);
  vvi A(n,vi(m));
  FOR(i,n) FOR(j,m) A[i][j] = i*m+j;
  auto B = A;
  int dn = 1, dm = 2;
  if(n <= 3) swap(dn,dm);
  FOR(i,n) {
    FOR(j,m) {
      B[i][j] = A[i][(j+dn*i)%m];
    }
  }
  C = A;
  FOR(i,n) {
    FOR(j,m) {
      C[i][j] = B[(i+dm*j)%n][j];
    }
  }

  set<pii> Q;
  FOR(i,n) FOR(j,m) {
    if(i+1<n) Q.insert(r(mt(A[i][j],A[i+1][j])));
    if(j+1<m) Q.insert(r(mt(A[i][j],A[i][j+1])));
  }
  set<pii> Q2;
  FOR(i,n) FOR(j,m) {
    if(i+1<n) Q2.insert(r(mt(C[i][j],C[i+1][j])));
    if(j+1<m) Q2.insert(r(mt(C[i][j],C[i][j+1])));
  }
  for(auto p : Q2) if(Q.count(p)) return 0;
  return 1;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // vvi C;
  // FORU(i,1,10) FORU(j,1,10) if(!solve(i,j,C)) {
  //   cout << mt(i,j) << endl;
  // }

  int n,m; cin>>n>>m;
  vvi C;
  bool ok = solve(n,m,C);
  if(ok) {
    cout << "YES" << endl;
    FOR(i,n) {
      FOR(j,m) {
        cout << C[i][j]+1 << ' ';
      }
      cout << endl;
    }
  }else{
    cout << "NO" << endl;
  }
  return 0;
}