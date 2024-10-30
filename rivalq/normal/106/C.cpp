#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 int n,m,c0,d0;cin>>n>>m>>c0>>d0;
 vector<int>a(m+2),b(m+2),c(m+2),d(m+2);
 vector<vector<int>>dp(m+2,vector<int>(n+2));
 rep(i,1,m+1){
 	cin>>a[i]>>b[i]>>c[i]>>d[i];
 }
 a[m+1]=0,b[m+1]=0,c[m+1]=c0,d[m+1]=d0;
 m++;
 for(int i=1;i<=m;i++){
 	for(int j=1;j<=n;j++){
 		for(int t=0;;t++){
 			if(t*b[i]>a[i] || t*c[i]>j)break;
 			int req=t*c[i];
 		    int cost=t*d[i];
 		    maxs(dp[i][j],dp[i-1][j-req]+cost);
 		}
 	}
 }
 int ma=0;
 for(int i=1;i<=n;i++)maxs(ma,dp[m][i]);
 cout<<ma<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}