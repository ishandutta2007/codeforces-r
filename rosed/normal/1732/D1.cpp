#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
void solve()
{
    int n;
    cin>>n;
    map<int,int> q,v;
    for(int i=1;i<=n;++i)
    {
        char ch;
        cin>>ch;
        int x;cin>>x;
        if(ch=='+') v[x]=1;
        else
        {
            int t=q[x];
            if(!t) t=x;
            while(v[t]) t+=x;
            q[x]=t;
            cout<<t<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/