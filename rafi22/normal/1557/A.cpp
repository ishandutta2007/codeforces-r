#include <bits/stdc++.h>

#define int long long
#define ld long double
//#define double long double
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
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        int sum=0;
        for(int i=0;i<n-1;i++) sum+=a[i];
        cout<<fixed<<setprecision(9)<<(ld)sum/(ld)(n-1)+(ld)a.back()<<endl;
    }

    return 0;
}