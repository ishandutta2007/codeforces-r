#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int a[100007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        int c[2]={0,0};
        int ans0=0,ans1=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]%=2;
            c[a[i]]++;
            if(a[i]==0) ans0+=abs(i-(2*c[0]-1));
            else ans1+=abs(i-(2*c[1]-1));
        }
        if(abs(c[0]-c[1])>1) cout<<-1<<endl;
        else
        {
            if(c[0]==c[1]) cout<<min(ans0,ans1)<<endl;
            else if(c[0]==c[1]+1) cout<<ans0<<endl;
            else cout<<ans1<<endl;
        }
    }

    return 0;
}