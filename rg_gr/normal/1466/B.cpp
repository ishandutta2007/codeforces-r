#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[100005],b[55];
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),ans=0;
        for(int i=1;i<=n;i++)a[i]=read(),a[i]+=a[i]<=a[i-1],ans+=a[i]!=a[i-1];
        printf("%lld\n",ans);
    }
}
//425316