//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int T, n; 

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 2, n) printf("%d ", i);
		printf("%d\n", 1);
	}
	return 0;
}