// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 		int n,m; cin >> n >> m;
 		vector<vector<int>>a(m+1,vector<int>(n));
 		vector<int>mx(m+1);
 		rep(i,0,n){
 			rep(j,1,m+1){
 				cin >> a[j][i];
 				maxs(mx[j],a[j][i]);
 			}
 		}


 		vector<int>order(m+1);
 		iota(all(order),0);

 		sort(order.begin()+1,order.end(),[&](int x,int y){
 			return mx[x] > mx[y];
 		});
 		m = min(m,n);

 		vector<vector<int>>dp(m + 1,vector<int>(1 << n));

 		vector<vector<int>>best(m + 1,vector<int>(1 << n));

 		for(int i = 1; i <= m; i++){
 			for(int mask = 0; mask < (1 << n); mask++){
 				for(int rot = 0; rot < n; rot++){
 					int val = 0;
 					for(int j = 0; j < n; j++){
 						if((1 << j)&mask)val += a[order[i]][(rot + j)%n];
 					}
 					maxs(best[i][mask],val);
 				}
 			}
 		}


 		for(int i = 1; i <= m; i++){
 			for(int mask = 0; mask < (1 << n); mask++){
 				maxs(dp[i][mask],dp[i-1][mask]);
 				for(int s = mask; s; s = (s-1)&mask){
 					maxs(dp[i][mask],dp[i-1][mask^s] + best[i][s]);
 				}
 			}
 		}
 		cout << dp[min(m,n)].back() << endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}