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

int tab[200007];

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
        int n,k,a,mx=-inf,mn=inf,mxp,mnp;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++) mx=max(mx,tab[i]);
        for(int i=1;i<=n;i++) tab[i]=mx-tab[i];
        if(k%2==0)
        {
            mx=-inf;
            for(int i=1;i<=n;i++) mx=max(mx,tab[i]);
            for(int i=1;i<=n;i++) tab[i]=mx-tab[i];
        }
        for(int i=1;i<=n;i++) cout<<tab[i]<<" ";
        cout<<endl;
    }

    return 0;
}