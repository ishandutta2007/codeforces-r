#pragma comment(linker, "/STACK:268435456")
 
#include<iostream>
#include<cstdio>
 
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
 
#include<iomanip>
#include<memory.h>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cassert>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define sz(v) (int)(v.size())
#define hash archash
#define next arcnext
#define link arclink
#define y0 arcy0
#define y1 arcy1
#define log2 arclog2
 
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { return a / gcd (a, b) * b; }
template<class T> T sign(T a) { return a > 0 ? 1 : (a < 0 ? -1 : 0); }
 
typedef long long li;
typedef unsigned long long uli;
typedef long double ld;
typedef pair <int, int> pt;
typedef vector <int> vi; 
typedef vector <vector <int> > vvi;
typedef vector <pair <int, int> > vpt; 
 
const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};
const int dxK[] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int dyK[] = { 0,  1, 1, 1, 0, -1, -1, -1};
const int dxKn[] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int dyKn[] = { 1,  2, 2, 1, -1, -2, -2, -1};
 
const int N = int(1e6) + 9;
const int M = int(1.5e2) + 9;
const int LOGN = 22;
const int SQN = 350;
const int MOD = int(1e9) + 7;
const int INF = 1e9 + 100;
const li INF64 = 2e18;
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

int n, m;
li len[2];
bool swp;
int b[2][N];
int res[N];

void solve(){
	scanf("%d %d", &n, &m);
	forn(i, n / 2)
		b[0][i] = i * 2, b[1][i] = i * 2 + 1;
	forn(i, m){
		int t;
		scanf("%d", &t);
		int d;
		if(t == 1){
			scanf("%d", &d);
			if(d < 0)
				d += n;
			forn(i, 2)
				len[i] += d / 2;
			if(d & 1){
				swp ^= true;
				swap(len[0], len[1]);
				len[0] += 1;
			}
		}
		else{
			swp ^= true;
			swap(len[0], len[1]);
		}
	}


	int  n2 = n / 2;
	forn(i, 2) 
		len[i] %= n2;
	forn(i, 2)
		len[i] = (n2 - len[i]) % n2;
	if(!swp){
		for(int i = 0; i < n; i += 2)
			res[i] = b[0][(i / 2 + len[0]) % n2];
		for(int i = 1; i < n; i += 2)
			res[i] = b[1][(i / 2 + len[1]) % n2];		
	}
	else{
		for(int i = 0; i < n; i += 2)
			res[i] = b[1][(i / 2 + len[0]) % n2];
		for(int i = 1; i < n; i += 2)
			res[i] = b[0][(i / 2 + len[1]) % n2];		
	}

	forn(i, n)
		printf("%d ", res[i] + 1);
}
 
int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	srand(time(NULL));
 
	srand(time(NULL));
	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;   
 
	solve();
 
	return 0;
}