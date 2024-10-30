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
	ll n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector<ll> a(n), b(m);
	rep(i, n)
		cin >> a[i];
	rep(i, m)
		cin >> b[i];
	ll pos = 0;
	ll ans = 0;
	if (k >= n) {
		cout << -1;
		return 0;
	}
	rep(i, n) {
		while (pos < m && b[pos] < a[i] + ta)
			pos++;
		if (i > k)
			break;
		ll d = pos + k - i;
		if (d >= m) {
			ans = -1;
			break;
		}
		ans = max(ans, b[d] + tb);
	}		
	cout << ans;
}