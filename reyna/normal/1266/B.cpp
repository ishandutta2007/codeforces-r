
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

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 0, mod = (int) 0;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		long long x;
		cin >> x;
		int flag = 0, sum = 1 + 2 + 3 + 4 + 5 + 6;
		for (int top = 1; top <= 6; ++top) {
			if ((x - top) % (sum - 7) == 0) {
				flag = 1;
			}
		}
		if (x <= (sum - 7)) flag = 0;
		cout << (flag ? "YES\n" : "NO\n");
	}
}