// Problem: CF139A Petr and Book
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF139A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int n, a[8];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, 7) scanf("%d", &a[i]);
	while(true) {
		rep(i, 1, 7) {
			n -= a[i];
			if(n <= 0) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	return 0;
}