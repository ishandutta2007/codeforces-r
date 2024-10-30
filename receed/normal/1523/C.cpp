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
  int t, n;
  cin >> t;
  rep(z, t) {
    cin >> n;
    vector<int> a(n);
    vector<int> cl;
    rep(i, n) {
      cin >> a[i];
      if (a[i] == 1)
        cl.push_back(1);
      else {
        while (cl.back() + 1 != a[i])
          cl.pop_back();
        cl.back()++;
      }
      int f = 0;
      for (int j : cl) {
        if (f)
          cout << '.';
        cout << j;
        f = 1;
      }
      cout << '\n';
    }
  }
}