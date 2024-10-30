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
 	int n,m;cin>>n>>m;
 	vector<int>a(n+1);
 	vector<pii>t;
 	int mx=0;
 	int sum=0;
 	rep(i,1,n+1){
 		cin>>a[i];
 		sum+=a[i];
 		if(mx<sum){
 			t.push_back({sum,i});
 			mx=sum;
 		}
 	}
 	auto get=[&](int x){
 		auto itr=lower_bound(all(t),make_pair(x,0LL));
 		return itr->y-1;
 	};
 	rep(i,1,m+1){
 		int x;cin>>x;
 		if(sum<=0){
 			if(t.empty() || mx<x){
 				cout<<-1<<" ";continue;
 			}
 			cout<<get(x)<<" ";
 		}
 		else{
 			if(mx>=x){
 				cout<<get(x)<<" ";
 			}
 			else{
 				int val = (x-mx)/sum + ((x-mx)%sum!=0);
 				int rem = x - val*sum;
 				cout<<val*n + get(rem)<<" ";
 			}

 		}
 	}cout<<endl;
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