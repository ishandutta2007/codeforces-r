#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

bool DP[1007];
int take[1007];

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
        int n,k,a;
        cin>>n>>k;
        vector <int> v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.pb(a);
        }
        sort(v.begin(),v.end(),greater<int>());
        int sum=v[0];
        for(int i=1;i<=k;i++)
        {
            sum+=v[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}