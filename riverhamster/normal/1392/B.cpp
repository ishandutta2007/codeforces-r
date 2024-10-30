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

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

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

int a[200005];

int main(){
	// File("b");
  int T;
  gi(T);
  while(T--){
    int n;
    ll k;
    gi(n); gi(k);
    k &= 1;
    int mx = -1000000001, mn = 1000000001;
    for(int i=1; i<=n; i++){
      gi(a[i]);
      upmax(mx, a[i]);
      upmin(mn, a[i]);
    }
    if(k)
      for(int i=1; i<=n; i++) wi(mx - a[i]), SP;
    else
      for(int i=1; i<=n; i++) wi(a[i] - mn), SP;
    EL;
  }
	return 0;
}