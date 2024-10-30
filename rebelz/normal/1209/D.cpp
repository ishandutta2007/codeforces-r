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

int n,k;
int f[100005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) f[i]=i;
	int cnt=0,x,y;
	for(int i=1;i<=k;i++){
		x=readint(); y=readint();
		int fx=getf(x),fy=getf(y);
		if(fx==fy) continue;
		f[fx]=fy;
		cnt++;
	}
	printf("%d\n",k-cnt);
	return 0;
}