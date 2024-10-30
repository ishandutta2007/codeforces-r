#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    sort(begin(a), end(a));
    int res = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] <= i + 1 - l) {
        ++res;
        l = i + 1;
      }
    }
    cout << res << '\n';
  }
}