#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-9)
void solve()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if(a[1]==1) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}