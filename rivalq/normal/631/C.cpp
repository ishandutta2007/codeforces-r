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
 	int n,m;cin>>n>>m;
 	set<pii>st;
 	vector<int>a(n+1);
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	rep(i,0,m){
 		int t,r;cin>>t>>r;
 		while(!st.empty() && st.begin()->x<=r)st.erase(st.begin());
 		st.insert({r,t});
 	}
 	int mx=st.rbegin()->x;
 	multiset<int>ms;
 	rep(i,1,mx+1){
 		ms.insert(a[i]);
 	}
 	st.insert({0,0});
 	int cur=mx;
 	while(st.size()>1){
 		auto itr=*st.rbegin();
 		st.erase(itr);
 		auto itr2=*st.rbegin();
 		int len=itr.x-itr2.x;
 		if(itr.y==1){
 			// greates len
 			while(len--){
 				int val=*ms.rbegin();ms.erase(ms.find(val));
 				a[cur--]=val;
 			}
 		}
 		else{
 			//smallest len
 			while(len--){
 				int val=*ms.begin();ms.erase(ms.find(val));
 				a[cur--]=val;
 			}

 		}
 	}
 	rep(i,1,n+1)cout<<a[i]<<" ";cout<<endl;
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