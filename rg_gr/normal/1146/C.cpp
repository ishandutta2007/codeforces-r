#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <bitset>
#include <map>
#include <algorithm>
#include <vector>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int pri[100005],a[100005];
inline int isp(int x)
{
    if(x<4)return x-1;
    int u=x%6;
    if(u!=1&&u!=5)return 0;
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
int cnt=0;
inline int si(int n)
{
    for(int i=1;i<=n;i++)if(isp(i))pri[cnt++]=i;
    return cnt;
}
inline int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
inline int qbb(int x,int n)
{
    int a=0;
    for(int i=1;i<=n;i++)if((1<<x)&i)a++;
    printf("%lld %lld ",a,n-a);
    for(int i=1;i<=n;i++)if((1<<x)&i)printf("%lld ",i);
    for(int i=1;i<=n;i++)if((1<<x)&i);else printf("%lld ",i);
    puts("");fflush(stdout);
    int xx=read();
    return xx;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),ans=0;
        int i=0,qwq=n;
        while(qwq)
        {
            qwq>>=1;
            ans=max(ans,qbb(i,n));
            i++;
        }
        printf("-1 %lld\n",ans);
        fflush(stdout);
    }
    return 0;
}
//baabbaaB