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
        string s;
        cin>>n>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L') cout<<'L';
            if(s[i]=='R') cout<<'R';
            if(s[i]=='D') cout<<'U';
            if(s[i]=='U') cout<<'D';
        }
        cout<<endl;
    }

    return 0;
}