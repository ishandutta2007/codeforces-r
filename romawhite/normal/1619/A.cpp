#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1 << 20;
const int MOD = 1000000007;


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));
	int t;
	cin >> t;
	FOR(tt,0,t) {
		string s;
		cin >> s;
		if (SZ(s) % 2) {
			cout << "NO" << endl;
			continue;
		}
		string t = s.substr(0, SZ(s) / 2);
		if (s.substr(SZ(s) / 2) == t) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}	

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}