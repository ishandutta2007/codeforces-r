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
 	int n;cin>>n;
 	vector<vector<int>>a(n+1,vector<int>(20));
 	rep(i,1,n+1){
 		int t;cin>>t;
 		for(int j=19;j>=0;j--){
 				if(t&(1<<j)){
 					a[i][j]=1;
 				}
 		}
 	}
 	for(int i=0;i<20;i++){
 		int cnt=0;
 		for(int j=1;j<=n;j++){
 			if(a[j][i])cnt++;
 		}
 		for(int j=1;j<=cnt;j++)a[j][i]=1;
 		for(int j=cnt+1;j<=n;j++)a[j][i]=0;	
 	}
 	int ans=0;
 	for(int i=1;i<=n;i++){
 		int k=0;
 		for(int j=0;j<20;j++){
 			if(a[i][j])k+=(1<<j);
 		}
 		ans+=k*k;
 	}
 	cout<<ans<<endl;
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