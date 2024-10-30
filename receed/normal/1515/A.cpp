#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  rep(z, t) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n)
      cin >> a[i];
    int f = 0;
    rep(i, n) {
      x -= a[i];
      if (x == 0) {
        if (i == n - 1) {
          f = 1;
          break;
        } else
          swap(a[i], a[i + 1]);
      }
    }
    if (f)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i : a)
        cout << i << ' ';
      cout << '\n';
    }
  }
}