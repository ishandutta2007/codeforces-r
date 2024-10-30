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
 		int n; cin >> n;
 		vector<pair<pii,int>> vec(n);
 		for(int i = 0; i < n; i++){
 			cin >> vec[i].x.x;
 			vec[i].y = i;
 		}
 		for(int i = 0; i < n; i++){
 			cin >> vec[i].x.y;
 		}
 		string ans(n,'0');
 		sort(all(vec));
 		ans[vec.back().y] = '1';
 		int mn = vec.back().x.y;
 		vector<int> pre(n);
 		pre[0] = vec[0].x.y;
 		for(int i = 1; i < n; i++){
 			maxs(pre[i],pre[i - 1]);
 			maxs(pre[i],vec[i].x.y);
 		}
 		for(int i = n - 2; i >= 0; i--){
 			if(mn < pre[i]){
 				ans[vec[i].y] = '1';
 				mins(mn,vec[i].x.y);
 			}
 		}

 		cout << ans << endl;
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