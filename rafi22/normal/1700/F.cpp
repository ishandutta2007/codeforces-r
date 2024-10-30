#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=200007;

int a[N][2];

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
        int n,x;
        cin>>n;
        for(int j=0;j<2;j++)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>x;
                a[i][j]-=x;
            }
        }
        for(int j=0;j<2;j++)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>x;
                a[i][j]+=x;
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i][0]>0&&a[i][1]<0)
            {
                int x=min(a[i][0],-a[i][1]);
                ans+=x;
                a[i][0]-=x;
                a[i][1]+=x;
            }
            if(a[i][0]<0&&a[i][1]>0)
            {
                int x=min(-a[i][0],a[i][1]);
                ans+=x;
                a[i][0]+=x;
                a[i][1]-=x;
            }
            ans+=abs(a[i][0])+abs(a[i][1]);
            a[i+1][0]+=a[i][0];
            a[i+1][1]+=a[i][1];
        }
        if(a[n+1][0]==0&&a[n+1][1]==0) cout<<ans;
        else cout<<-1;
    }

    return 0;
}