// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], mask[N];
int32_t main() {
	int n;
	cin >> n;
	int res = 0;
	for (int j = 0; j < n; ++j) cin >> a[j] >> mask[j], res += a[j];
	if (res < 0) for (int j = 0; j < n; ++j) a[j] *= -1;
	res = 0;
	for (int b = 0; b < 62; ++b) {
		int sum = 0;
		for (int j = 0; j < n; ++j)
			if (mask[j] == (1ll << b)) {
				sum += a[j];
			}
		if (sum > 0) {
			res |= 1ll << b;
			for (int j = 0; j < n; ++j)
				if (mask[j] >> b & 1) {
					mask[j] ^= 1ll << b;
					a[j] *= -1;	
				}
		} else {
			for (int j = 0; j < n; ++j)
				if (mask[j] >> b & 1)
					mask[j] ^= 1ll << b;
		}
	}
	cout << res << '\n';
}