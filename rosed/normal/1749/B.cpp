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
    vector<int> a(n+1),b(n+1);
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;++i) cin>>b[i];
    int l=1,r=n;
    while(l<r)
    {
        if(b[l]<b[r]) sum+=b[l++];
        else sum+=b[r--];
    }
    cout<<sum<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/