#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll du[200005],ans[200005];
pll a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=mp(readint(),i);
		for(int i=1;i<=n;i++) du[i]=0;
		for(int i=1;i<n;i++) du[readint()]++,du[readint()]++;
		ll sum=0;
		for(int i=1;i<=n;i++) sum+=1ll*du[i]*a[i].fi;
		ans[n-1]=sum;
		sort(a+1,a+n+1);
		int now=n-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=du[a[i].se]-1;j++){
				ans[now-1]=ans[now]-a[i].fi;
				now--;
			}
		}
		for(int i=1;i<=n-1;i++) printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}