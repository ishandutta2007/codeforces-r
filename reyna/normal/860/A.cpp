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
	string s, res = "";
	cin >> s;
	int cnt = 0, lst0 = 0, lst1 = 0;
	for (char c : s) {
		if (c == 'a' || c == 'i' || c == 'u' || c == 'o' || c == 'e') {
			cnt = 0;
			lst0 = lst1 = 0;
		} else {
			if (cnt >= 2 && (lst0 != lst1 || lst1 != c || lst0 != c)) {
				res += ' ';
				cnt = lst0 = lst1 = 0;
			}
			lst1 = lst0;
			lst0 = c;
			cnt++;
		}
		res += c;
	}
	cout << res << endl;
	
}