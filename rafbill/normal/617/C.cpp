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

template<lli M>
struct plus_mod : binary_function<lli, lli, lli> {
  lli operator()(lli const& a, lli const& b) const {
    return (a+b)%M;
  }
};

//------------------------------------------------------------------------------

namespace segmenttree {
  template<typename T, typename O>
  struct tree {
    using F = function<T(lli, lli, T const&)>;
    struct node {
      node(T const& v) : value(v){ };
      T value; bool dirty = false; F delta = [](lli, lli, T const& x){ return x; };
    };
    lli n; vector<node> A;
    tree(lli n_, T const& v = T()) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n, node{ v }) { }

    void push(lli i, lli a, lli b) {
      if(A[i].dirty) {
        A[i].value = A[i].delta(a, b, A[i].value);
        if(i < n){
          lli c = (a+b)/2;
          update__(2*i  , a  , c, A[i].delta);
          update__(2*i+1, c+1, b, A[i].delta);
        }
        A[i].dirty = false;
      }
    }

    void update__(lli i, lli a, lli b, F const& f){
      push(i, a, b); A[i].dirty = true; A[i].delta = f;
    }

    void update_(lli i, lli a, lli b, lli l, lli r, F const& f){
      push(i, a, b);
      if(l > b) return;
      if(r < a) return;
      if(l <= a && b <= r){
        update__(i, a, b, f); push(i, a, b);
        return;
      }
      lli c = (a+b)/2;
      update_(2*i  , a  , c, l, r, f);
      update_(2*i+1, c+1, b, l, r, f);
      A[i].value = O()(A[2*i].value, A[2*i+1].value);
    }

    void update(lli l, lli r, F const& f) {
      update_(1, 0, n-1, l, r, f);
    }

    void add(lli l, lli r, T v){ update(l, r, [&](lli a, lli b, lli x) { return x + (b-a+1) * v; }); }
    void mult(lli l, lli r, T v){ update(l, r, [&](lli, lli, lli x) { return x * v; }); }
    void addmod(lli l, lli r, T v, lli M){ update(l, r, [&](lli a, lli b, lli x) { return (x + (b-a+1) * v) % M; }); }
    void multmod(lli l, lli r, T v, lli M){ update(l, r, [&](lli, lli, lli x) { return (x * v) % M; }); }


    T query_(lli i, lli a, lli b, lli l, lli r){
      if(l > b) return T();
      if(r < a) return T();
      push(i, a, b);
      if(l <= a && b <= r){ return A[i].value; }
      lli c = (a+b)/2;
      return O()(query_(2*i  , a  , c, l, r),
                 query_(2*i+1, c+1, b, l, r));
    }

    T query(lli l, lli r) {
      return query_(1, 0, n-1, l, r);
    }
  };
}

//------------------------------------------------------------------------------

#define SQ(x) ((x)*(x))
lli dist2(pii const& a, pii const& b){
  return SQ(X(a)-X(b))+SQ(Y(a)-Y(b));
}

int main(int, char**){
  ios::sync_with_stdio(false);

  lli n; cin >> n;
  pii p1, p2; cin >> X(p1) >> Y(p1) >> X(p2) >> Y(p2);

  vii A;
  FOR(i, n) {
    lli x, y; cin >> x >> y;
    A.pb(mt(x, y));
  }

  vi I(n); FOR(i, n) I[i] = i;
  vi J(n); FOR(i, n) J[i] = i;

  sort(begin(I), end(I), [&](lli const& a, lli const& b){ return dist2(p1, A[a]) < dist2(p1, A[b]); });
  sort(begin(J), end(J), [&](lli const& a, lli const& b){ return dist2(p2, A[a]) < dist2(p2, A[b]); });

  lli best = min(dist2(p1, A[I[n-1]]), dist2(p2, A[J[n-1]]));

  lli j = n-1;
  vi E(n);
  FOR(i, n) {
    E[I[i]] = 1;
    while(j >= 0 && E[J[j]]) j -= 1;
    lli val = dist2(p1, A[I[i]]);
    if(j >= 0) val += dist2(p2, A[J[j]]);
    best = min(best, val);
  }

  cout << best << endl;

  return 0;
}