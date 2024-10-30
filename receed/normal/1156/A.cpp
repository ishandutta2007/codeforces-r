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
using ld = long double;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	rep(i, n - 1) {
		if (a[i] == a[i + 1] || a[i] + a[i + 1] == 5) {
			cout << "Infinite";
			return 0;
		}
		if (i + 2 < n && a[i] == 3 && a[i + 2] == 2)
			ans--;
		ans += max(a[i], a[i + 1]) + 1;
	}
	cout << "Finite\n" << ans;
}