// Problem: F. Strange Addition
// Contest: Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1380/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  - /

/*
+
++
+++
++++
+++++
++++++
+++++++
++++++++
+++++++++
++++++++++
+++++++++++
++++++++++++
+++++++++++++
++++++++++++++
+++++++++++++++
++++++++++++++++
+++++++++++++++++
++++++++++++++++++
+ +++++++++++++++++
+  ++++++++++++++ ++
+   +++++++++++++  ++
+    ++++++++++++   ++
+     +++++++++++    ++
+      ++++++++++     ++
+       +++++++++      ++
+        ++++++++       ++
+         +++++++++++++++++
+          +++++++++++++++++
+           ++++++++++++++
+            +++++++++++
+             ++++++++
+              +++++
+               ++
+               +
+               +
+              ++
+             +++
+            ++++
+           +++++
+           +++++
+           +++++
+           +++++
+     +     +++++
+    +++    +++++
+   ++ ++   +++++
+  ++   ++  +++++
+ ++  +  ++ +++++
+++  +++  +++++++
++  ++ ++  ++++++
 
 
 ++++++++      +++++++++++     +++      +++        ++++++++        ++++++++
+++++++++     +++++++++++++    +++      +++       +++    +++      +++    +++
+++          +++   +++   +++   +++      +++      +++   ++++++    +++      +++
+++          +++   +++   +++   +++      +++      +++ +++  +++           +++
+++          +++   +++   +++   +++ ++   +++ ++   ++++++   +++         +++
+++++++++    +++   +++   +++   +++ ++   +++ ++    +++    +++        +++    ++
 ++++++++    +++   +++   +++   +++++    +++++      ++++++++       +++++++++++
*/
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <set>
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
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
template<typename T>
void print(T x){}
template<>
void print<int>(int x){od(x);}
template<>
void print<const int>(const int x){od(x);}
template<>
void print<long long>(long long x){old(x);}
template<>
void print<const long long>(const long long x){old(x);}
template<>
void print<char>(char x){putchar(x);}
template<>
void print<const char>(const char x){putchar(x);}
template<>
void print<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void print(T x,qwq ...args)
{
	print(x);
	print(args...);
}
#ifdef DEBUG
template<typename T>
void debug(T x){}
template<>
void debug<int>(int x){od(x);}
template<>
void debug<const int>(const int x){od(x);}
template<>
void debug<long long>(long long x){old(x);}
template<>
void debug<const long long>(const long long x){old(x);}
template<>
void debug<char>(char x){putchar(x);}
template<>
void debug<const char>(const char x){putchar(x);}
template<>
void debug<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	debug(x);
	debug(args...);
}
#define dflush fflush
#else
#define dflush(...) 0
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	
}
#endif
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
{\
    int fx=f(x),fy=f(y);\
    if(fx==fy)return 0;\
    if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    return 1;\
}
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
    while(c<48||c>57)c=getchar();
    return c-48;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct Bird{
	int a[2][2]={};
	Bird operator*(const Bird& b)const
	{
		auto d=b.a;
		Bird c;
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					c.a[i][j]=(c.a[i][j]+a[i][k]*d[k][j])%998244353;
		return c;
		// return *this;
	}
	// Bird(){}
	Bird(int A=0,int B=0,int C=0,int D=0){
		a[0][0]=A;
		a[0][1]=B;
		a[1][0]=C;
		a[1][1]=D;
	}
	Bird operator^(int p)
	{
		Bird res(1,0,0,1),x=*this;
		while(p)
		{
			if(p&1)res=res*x;
			x=x*x;
			p>>=1;
		}
		return res;
	}
};
int a[1000005];
Bird fix(int i)
{
	return Bird(a[i]+1,(a[i-1]==1?9-a[i]:0),1);
}
struct L{
	Bird a[2000005];
	void build(int o,int l,int r)
	{
		if(l==r)
		{
			a[o]=fix(l);
			return;
		}
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		a[o]=a[o<<1|1]*a[o<<1];
	}
	void update(int o,int l,int r,int p)
	{
		if(l==r)
		{
			a[o]=fix(l);
			return;
		}
		int m=l+r>>1;
		if(p<=m)update(o<<1,l,m,p);
		else update(o<<1|1,m+1,r,p);
		a[o]=a[o<<1|1]*a[o<<1];
	}
	// int 
}Gold;
signed main()
{
	int n=read(),q=read();;
	rg(n)a[i]=re1d();gr
	Gold.build(1,1,n);
	rg(q)
	int l=read(),r=read();
	a[l]=r;
	Gold.update(1,1,n,l);
	if(l<n)Gold.update(1,1,n,l+1);
	Bird res(1,0,1,0);
	odl((Gold.a[1]*res).a[0][0]);
	gr
	return 0;
}