#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define fail return (void)puts("-1")
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=3e5+10;
	int haku,n;
	int b[N],a[N],c[N];
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) b[i]=read();
		a[1]=c[2]=b[1];
		for(int i=2;i<=n;++i)
		{
			a[i]=b[i]+c[i];
			c[i+1]=max(c[i],a[i]);
		}
		for(int i=1;i<=n;++i) printf("%lld ",a[i]);
	}
}
signed main()
{
	red::main();
	return 0;
}