// Problem: CF986C AND Graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF986C
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}

inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
{\
	int fx=f(x),fy=f(y);\
	if(fx==fy)return 0;\
	if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
	fa[fx]=fy,sz[fy]+=sz[fx];\
	return 1;\
}
int a[1<<23],v[1<<23],w[1<<23];
int rev;
void dfs(int u)
{
	if(v[u])return;
	v[u]=1;
	if(w[u])dfs(rev^u);
	for(int i=1;i<rev;i<<=1)if(i&u)dfs(i^u);
}
signed main()
{
	int n=read(),m=read(),ans=0;rev=1<<n;rev--;
	rg(m)a[i]=read();w[a[i]]=1;gr
	rg(m)if(v[a[i]]==0)dfs(rev^a[i]),ans++;gr
	odl(ans);
	return 0;
}