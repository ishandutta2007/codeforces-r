//In the name of God
// (c) Silver soul 49
// What i'll engrave in this place is my soul!!!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw (int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }
int lcm (int x, int y) { return min(x, y)? x / __gcd(x, y) * y: max(x, y); }

/*******************************************************************************************************/

const int maxN = 55;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;


int32_t main () {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int d1, d2, d3; cin >> d1 >> d2 >> d3;
	cout << min(min(min(min((d1 + d2) * 2, (d1 + d2 + d3)), (d1 + d3) * 2), (d2 + d3) * 2), oo);
}