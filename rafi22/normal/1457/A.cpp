#include <bits/stdc++.h>

#define int long long
#define double long double
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
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        cout<<max(max(abs(1-r)+abs(1-c),abs(n-r)+abs(1-c)),max(abs(1-r)+abs(m-c),abs(n-r)+abs(m-c)))<<endl;
    }

    return 0;
}