#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=1e4+7,inf=2e9;
    int n,m,tot;
    char s[N],t[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>s>>t;
            n=strlen(s),m=strlen(t);
            bool f0=0,f1=0;
            for(int i=0;i<m;++i)
            {
                if(t[i]=='a') f0=1;
                else f1=1;
            }
            if(m==1&&f0)
            {
                cout<<1<<'\n';
                continue;
            }
            if(f0)
            {
                cout<<"-1\n";
                continue;
            }
            cout<<(1ll<<n)<<'\n';

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