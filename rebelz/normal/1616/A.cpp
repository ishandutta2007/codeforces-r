// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int vis[105];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=0;i<=100;i++) vis[i]=0;
		for(int i=1;i<=n;i++) vis[abs(readint())]++;
		int ans=min(1,vis[0]);
		for(int i=1;i<=100;i++) ans+=min(2,vis[i]);
		printf("%d\n",ans);
	}
	return 0;
}