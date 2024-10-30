#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  lint res = 0;
  res += (lint) a[0] * (n - a[0] + 1);
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] < a[i]) {
      res += (lint) (a[i] - a[i - 1]) * (n - a[i] + 1);
    } else if (a[i - 1] > a[i]) {
      res += (lint) a[i] * (a[i - 1] - a[i]);
    }
  }
  cout << res << '\n';
}