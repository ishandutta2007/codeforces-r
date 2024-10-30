// Problem: CF1638B Odd Swap Sort
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1638B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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
const int N = 1e5+5;

int T, n, a[N];
vector<int> odd, even;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			if(a[i] & 1) odd.push_back(a[i]);
			else even.push_back(a[i]);
		}
		puts(is_sorted(odd.begin(), odd.end()) && is_sorted(even.begin(), even.end())?"Yes":"No");
		odd.clear();
		even.clear();
	}
	return 0;
}