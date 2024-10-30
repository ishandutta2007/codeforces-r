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

const int N = (int) 0, mod = (int) 0;

int main() {
	int n, k;
	cin >> n >> k;
	int res = (n - 1) / k * 2;
	if ((n - 1) % k > 0) ++res;
	if ((n - 1) % k > 1) ++res;
	int cnt = 1;
	cout << res << '\n';
	for (int g = 0; g < k; ++g) {
		int cur = 0;
		for (int j = 0; j < (n - 1) / k + ((n - 1) % k > g); ++j) {
			cout << cur + 1 << ' ' << cnt + 1 << '\n';
			cur = cnt;
			++cnt;
		}
	}
}