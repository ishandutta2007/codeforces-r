//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N], pos[N];

int main() {
	mulT0 {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), pos[a[i]] = i;
		int now = n + 1;
		per(i, n, 1) {
			if(pos[i] < now) {
				rep(j, pos[i], now-1) printf("%d ", a[j]);
				now = pos[i];
			}
		}
		puts("");
	}
	return 0;
}