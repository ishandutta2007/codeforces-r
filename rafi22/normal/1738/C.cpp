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

const int N=107;

bool DP[N][N][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    DP[0][0][0]=1;
    for(int i=1;i<=100;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j>0&&!DP[i-1][j-1][!(j%2)]) DP[i][j][0]=1;
            if(j!=i&&!DP[i-1][j][!(j%2)]) DP[i][j][0]=1;
            if(j>0&&!DP[i-1][j-1][(j%2)]) DP[i][j][1]=1;
            if(j!=i&&!DP[i-1][j][(j%2)]) DP[i][j][1]=1;
        }
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,x,c=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            x=abs(x);
            if(x%2==1) c++;
        }
        if(DP[n][c][0]) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}