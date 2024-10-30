// Problem: E2. Cats on the Upgrade (hard version)
// Contest: Codeforces - Codeforces Round #765 (Div. 2)
// URL: https://codeforces.com/contest/1625/problem/E2
// Memory Limit: 256 MB
// Time Limit: 6000 ms
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
#include <map>
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
#include <vector>
#define int long long
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3fll
#else 
#define inf 0x3f3f3f3f
#endif
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
    while(c<'('||c>')')c=getchar();
    return c==')';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[1000005],s[1000005],cc,mat[1000005],dd;
struct qwq{
	int l,r,id,sum,sid;
}t[1000005];
struct comp{
	bool operator()(int x,int y)
	{
		return t[x].l<t[y].l;
	}
};
std::set<int,comp>G[1000005];
int idl[1000005],idr[1000005];
struct BIT{
	std::vector<int>a;
	int n;
	void init(int x)
	{
		a.resize(x+1);
		rg(x)a[i]=0;gr
		n=x;
	}
	void add(int x,int p)
	{
		while(x<=n)a[x]+=p,x+=x&-x;
	}
	int operator[](int l)
	{
		int res=0;while(l)res+=a[l],l-=l&-l;
		return res;
	}
	int operator()(int l,int r)
	{
		return (*this)[r]-(*this)[l-1];
	}
}b[1000005];
int fa[1000005];
void build(int l,int r,int k=0)
{
	// odp(l,r);dflush(stdout);
	// odl(dd);
	// t[dd].l=l;
	// t[dd].r=r;
	int ee=0;int c=dd;
	t[c].sum=k;
	for(int i=l+k;i<=r-k;i++)
	{
		if(mat[i]>i)
		{
			++ee;
			dd++;
			int son=dd;
			fa[son]=c;
			t[dd]=(qwq){i,mat[i],dd,0,ee};
			build(i,mat[i],1);
			t[c].sum+=t[son].sum;
			i=mat[i];
			G[c].insert(son);
			// odp(c,son);
		}
	}
	t[c].sum+=(ee)*(ee-1)/2;
	if(k)idl[t[c].l]=t[c].id,
	idr[t[c].r]=t[c].id;
	b[c].init(ee);
	int pp=0;
	// assert(ee==G[c].size());
	for(auto x:G[c])
	{
		b[c].add(++pp,t[x].sum);
		// debug(c,' ',pp,' ',t[x].sum,'\n');
	}
}
void deb(int u,int k=0)
{
	rg(k)putchar('-');gr
	printf("%d (%d %d) : %d :: %d\n",u,t[u].l,t[u].r,t[u].sum,G[u].size());
	for(auto x:G[u])deb(x,k+1);
}
signed main()
{
	int n=read(),m=read();
	rg(n)a[i]=!re1d();gr
	rg(n)if(a[i])s[++cc]=i;else if(cc)mat[s[cc]]=i,mat[i]=s[cc],cc--;gr
	for(int i=1;i<=n;i++)
	{
		if(mat[i]<=i)continue;
		int l=i;
		while(mat[i]&&i<=n)i=mat[i]+1;
		i--;
		// odp(l,i);
		dflush(stdout);
		dd++;int f=dd;
		t[f].l=l;
		t[f].r=i;
		build(l,i);
		// deb(f);
		// puts("");
	}
	// return 0;
	dflush(stdout);
	rg(m)
	int op=read(),x=read(),y=read();
	if(op==2)
	{
		int pl=idl[x],pr=idr[y];
		// return 0;
		int f=fa[pl];
		// odb(f),odp(t[f].l,t[f].r);odp(pl,pr);dflush(stdout);
		if(t[f].l==x&&t[f].r==y)
		{
			// debug("!");dflush(stdout);return 0;
			oldl(t[fa[idl[x]]].sum);
			continue;
		}
		int p=t[pr].sid-t[pl].sid+1;
		// odl(f);
		int q=b[f](t[pl].sid,t[pr].sid);
		// debug(f,' ',p,' ',q,' ',t[pl].sid,' ',t[pr].sid,'\n');
		oldl(q+p*(p-1)/2);
	}else{
		
	}
	dflush(stdout);
	gr
	return 0;
}