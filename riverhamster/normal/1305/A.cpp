#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

template<class T> inline void gi(T &x){
	char ch; x = 0;int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> inline void wi(T x){
	static char stk[128]; int top = 0;
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 105;
int a[N], ra[N], b[N], rb[N];
bool cmpa(int x, int y){return a[x] < a[y];}
bool cmpb(int x, int y){return b[x] < b[y];}

int main(){
	// File("a");
	int T;
	gi(T);
	while(T--){
		int n;
		gi(n);
		for(int i=1; i<=n; i++) gi(a[i]), ra[i] = i;
		for(int i=1; i<=n; i++) gi(b[i]), rb[i] = i;
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		for(int i=1; i<=n; i++) wi(a[i]), SP;
		EL;
		for(int i=1; i<=n; i++) wi(b[i]), SP;
		EL;
	}
	return 0;
}