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
 		int a,b; cin >> a >> b;
 		int n = (a + b);
 		vector<int>ans;
 		auto check = [&](int n,int k){
 			// n -> zeros at odd
 			int b1 = (n + k - a);
 			if(b1 >= 0 and b1 % 2 == 0){
 				b1 /= 2;
 				int a1 = k - b1;
 				return a1 >= 0 and a1 <= a and b1 <= b;
 			}
 			return false;
 		};
 		for(int i = 0; i <= a + b; i++){
 			if(check(n/2,i) or check(n - n/2,i))ans.push_back(i);
 		}
 		cout << sz(ans) << endl;
 		for(auto i:ans)cout << i << " ";
 			cout << endl;

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