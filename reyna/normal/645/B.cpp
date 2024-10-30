//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 0;

int read() { int x; cin >> x; return x; }


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	long long res = 0;
	int cur = n - 1;
	rep(i, k) {
		if (cur != 0) {
			res += cur;
			cur--;
		}
		if (cur != 0) {
			res += cur;
			cur--;
		}
	}
	cout << res << endl;
}