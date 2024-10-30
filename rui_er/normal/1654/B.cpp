//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, pos[26];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		memset(pos, 0, sizeof(pos));
		scanf("%s", s+1);
		n = strlen(s+1);
		int qwq = 0;
		rep(i, 1, n) pos[s[i]-'a'] = i;
		rep(i, 1, n) if(i == pos[s[i]-'a']) {qwq = i; break;}
		printf("%s\n", s+qwq);
	}
	return 0;
}