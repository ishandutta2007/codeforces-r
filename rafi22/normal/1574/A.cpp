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
        int n;
        cin>>n;
        string s;
        for(int i=0;i<n;i++) s.pb('(');
        for(int i=0;i<n;i++) s.pb(')');
        cout<<s<<endl;
        for(int i=1;i<n;i++)
        {
            swap(s[i],s[n]);
            cout<<s<<endl;
            swap(s[i],s[n]);
        }
    }

    return 0;
}