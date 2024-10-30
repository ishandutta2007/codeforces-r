#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  V<lint> s(m);
  lint res = 0;
  for (int k = 0; k < n; ++k) {
    s[k % m] += a[k];
    res += s[k % m];
    cout << res << " \n"[k == n - 1];
  }
}