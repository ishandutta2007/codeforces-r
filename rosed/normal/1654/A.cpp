#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=1e15,mod=1e9+7;
    int n;
    int a[N];
    int maxn,ans;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            maxn=ans=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                ans=max(ans,maxn+a[i]);
                maxn=max(maxn,a[i]);
            }
            cout<<ans<<'\n';

        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*

*/