#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)
#define W(A) get<3>(A)

#define mp make_pair
#define mt make_tuple
#define pb push_back

//------------------------------------------------------------------------------

using namespace std;
using lli = long long int;
using llu = long long unsigned;

using pii   = tuple<lli, lli>;
using ppii  = tuple<pii, pii>;
using piii  = tuple<lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;
using pt    = complex<lli>;

//------------------------------------------------------------------------------

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B>
ostream& operator<<(ostream& s, tuple<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B, class C>
ostream& operator<<(ostream& s, tuple<A, B, C> const& a){
  return s << "(" << X(a) << "," << Y(a) << "," << Z(a) << ")";
}

template<class T>
ostream& operator<<(ostream& s, vector<T> const& a){
  s << '[';
  FOR(i, a.size()){
    s << a[i];
    if(i != (lli)a.size()-1) s << " ";
  }
  return s << ']';
}

//------------------------------------------------------------------------------

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n, m; cin >> n >> m;
  vi A, B; A.pb(-1); B.pb(-1);
  { lli i = 0; while(1) { i += 1; if(i%2==0&&i%3!=0) { A.pb(i); n -= 1; } if(n == 0) break; } }
  { lli i = 0; while(1) { i += 1; if(i%3==0&&i%2!=0) { B.pb(i); m -= 1; } if(m == 0) break; } }
  lli i = 0;
  while(6*(i+1) < max(A.back(), B.back())){
    i += 1;
    if(A.back() > B.back()) A.pop_back();
    else B.pop_back();
  }
  cout << max(A.back(), max(B.back(), 6*i)) << endl;
  return 0;
}