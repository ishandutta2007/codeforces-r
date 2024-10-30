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
        int n;
        cin>>n;
        string s;
        cin>>s;
        s='#'+s+'#';
        vector<pair<int,int>>V;
        int last=0;
        for(int i=1;i<=n+1;i++)
        {
            if(s[i]!='?')
            {
                if(last!=i-1) V.pb({last,i});
                last=i;
            }
        }
        for(auto x:V)
        {
            char c[2]={'B','R'};
            if(x.st>0)
            {
                if(s[x.st]=='R') swap(c[0],c[1]);
                for(int i=x.st+1;i<x.nd;i++) s[i]=c[(i-x.st)%2];
            }
            else if(x.nd<=n)
            {
                if(s[x.nd]=='R') swap(c[0],c[1]);
                for(int i=x.nd-1;i>x.st;i--) s[i]=c[(x.nd-i)%2];
            }
            else for(int i=x.st+1;i<x.nd;i++) s[i]=c[(i-x.st)%2];
        }
        for(int i=1;i<=n;i++) cout<<s[i];
        cout<<endl;
    }

    return 0;
}