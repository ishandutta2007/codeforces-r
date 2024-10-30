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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, t = 0;
	cin >> n;
	vector<int> a(n), c(n), d(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = n - 1 - a[i];
		if (!c[a[i]])
			d[a[i]] = t++;
		c[a[i]]++;
		b[i] = d[a[i]];
		c[a[i]] %= (a[i] + 1);
	}
	for (int i = 0; i < n; i++)
		if (c[i]) {
			cout << "Impossible";
			return 0;
		}
	cout << "Possible\n";
	for (int i : b)
		cout << i + 1 << ' ';
}