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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[200005],val[600000],ans[200005];

void build(int id,int l,int r){
	if(l==r) return (void)(val[id]=l);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	val[id]=val[id<<1]+val[id<<1|1];
}

void change(int id,int l,int r,int x){
	if(l==r) return (void)(val[id]=0);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x);
	else change(id<<1|1,mid+1,r,x);
	val[id]=val[id<<1]+val[id<<1|1];
}

int query(int id,int l,int r,ll x){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(x<val[id<<1]) return query(id<<1,l,mid,x);
	else return query(id<<1|1,mid+1,r,x-val[id<<1]);
}

int main(){
	n=readint();
	build(1,1,n);
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=n;i>=1;i--){
		int tmp=query(1,1,n,a[i]);
		change(1,1,n,tmp);
		ans[i]=tmp;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}