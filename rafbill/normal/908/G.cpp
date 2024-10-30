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

const int N = 801;
lli sp[N+1];
lli cnk[2*N][2*N];

int A[N];
array<int,10> forced;

// lli dp[10][N];

lli pre[10][N+1];
lli p10[2*N+1];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  p10[0] = 1;
  FOR(i,2*N) p10[i+1] = (10*p10[i])%MOD;

  FOR(i,2*N) {
    cnk[i][0]=cnk[i][i] = 1;
    FORU(j,1,i-1) cnk[i][j] = (cnk[i-1][j]+cnk[i-1][j-1])%MOD;
  }

  FOR(d,10) FOR(size, N+1) {
    FOR(l,size+1) {
      pre[d][size] += cnk[size][l] * fexp(d,l) % MOD * fexp(9-d,size-l) % MOD * p10[size-l] % MOD;
      pre[d][size] %= MOD;
    }
  }

  //
  string s;
  cin>>s;
  int n = s.size();

  lli ans=0;
  FOR(i,n) A[i] = s[i]-'0';
  A[n-1] += 1;


  auto f = [&](lli d, lli nbelow, lli nd, lli size) {
    {
      lli cur = 0;
      lli sm = 0;
      lli p = 1;
      auto incSm = [&](){ sm=(sm+p)%MOD; p*=10; p%=MOD; };
      FOR(k,nd) incSm();
      FOR(l,size+1) {
        lli v = cnk[size][l] * pre[d][size-l] % MOD * sm % MOD;
        cur += v;
        cur %= MOD;
        incSm();
      }
      cur *= p10[nbelow];
      cur %= MOD;
      cur *= d;
      cur %= MOD;
      return cur;
    }
  };


  // lli ans2=0;
  // FORU(i,1,atoi(s.c_str())) {
  //   auto t = to_string(i);
  //   sort(all(t));
  //   for(char& c : t) if(c != '0'+D) c='0';
  //   ans2 += atoi(t.c_str());
  // }

  FORU(d,1,9) {
    int nup = 0;
    int nd = 0;
    FOR(i,n) {
      int n1=0,n2=0,n3=0;
      FORU(d2,0,A[i]-1) {
        if(d2 > d) n1++;
        if(d2 == d) n2++;
        if(d2 < d) n3++;
      }
      if(n1) ans += n1*f(d,nup+1,nd,n-1-i)%MOD;
      if(n2) ans += n2*f(d,nup,nd+1,n-1-i)%MOD;
      if(n3) ans += n3*f(d,nup,nd,n-1-i)%MOD;

      ans %= MOD;
      if(A[i] > d) nup += 1;
      if(A[i] == d) nd += 1;
    }
  }

  // FOR(i,n+1) {
  //   FOR(d,10) forced[d]=0;
  //   FOR(j,i) forced[A[j]]++;
  //   if(i != n) {
  //     FOR(d,A[i]) {
  //       forced[d]++;
  //       ans += calc(n-1-i);
  //       forced[d]--;
  //     }
  //   }else{
  //     ans += calc(0);
  //   }
  // }
  cout << ans << endl;
  return 0;
}