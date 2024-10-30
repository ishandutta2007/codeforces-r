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
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>X,Y;
        for(int i=1;i<=n;i++)
        {
            int x,ile=1;
            cin>>x;
            while(x%m==0)
            {
                ile*=m;
                x/=m;
            }
            if(sz(X)>0&&X.back().nd==x) X.back().st+=ile;
            else X.pb({ile,x});
        }
        int k;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            int x,ile=1;
            cin>>x;
            while(x%m==0)
            {
                ile*=m;
                x/=m;
            }
            if(sz(Y)>0&&Y.back().nd==x) Y.back().st+=ile;
            else Y.pb({ile,x});
        }
        if(X==Y) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}