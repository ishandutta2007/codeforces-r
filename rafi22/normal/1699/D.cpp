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

const bool multi=1;

const int N=5007;

int a[N];
int DP[N];
int cnt[N];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n+1;i++) DP[i]=-inf;
            a[n+1]=k;
            for(int i=1;i<=n+1;i++)
            {
                if(a[i]!=k) continue;
                for(int j=0;j<=n;j++) cnt[j]=0;
                int mx=0;
                for(int j=i-1;j>=0;j--)
                {
                    if((i-j-1)%2==0&&(a[j]==k||j==0)&&mx<=(i-j-1)/2) DP[i]=max(DP[i],DP[j]+1);
                    cnt[a[j]]++;
                    mx=max(mx,cnt[a[j]]);
                }
            }
            ans=max(ans,DP[n+1]-1);
        }
        cout<<ans<<endl;
    }

    return 0;
}