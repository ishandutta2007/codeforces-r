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
        if(n>6+10+14)
        {
            if(n-(6+10+14)==6||n-(6+10+14)==10||n-(6+10+14)==14)
            {
                if(n>(6+10+15)) cout<<"YES"<<endl<<6<<" "<<10<<" "<<15<<" "<<n-(6+10+15)<<endl;
                else cout<<"NO"<<endl;
            }
            else cout<<"YES"<<endl<<6<<" "<<10<<" "<<14<<" "<<n-(6+10+14)<<endl;

        }
        else cout<<"NO"<<endl;
    }
    return 0;
}