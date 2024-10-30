#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  lint k; cin >> k;
  string s, t; cin >> s >> t;
  lint res = 0;
  bool over = false;
  lint w = 1;
  for (int i = 0; i < n; ++i) {
    w *= 2;
    w -= s[i] == 'b';
    w -= t[i] == 'a';
    if (w >= k) over = true;
    if (!over) {
      res += w;
    } else res += k;
  }
  cout << res << '\n';
}