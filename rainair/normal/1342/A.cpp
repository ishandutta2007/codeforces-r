#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL x,y,a,b;scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		if(x < y) std::swap(x,y);
		printf("%lld\n",std::min(a*(x+y),y*b+(x-y)*a));
	}
	return 0;
}