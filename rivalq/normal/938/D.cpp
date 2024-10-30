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
 int n,m;cin>>n>>m;
 vector<pii>g[n+1];
 rep3(m){
 	int a,w,b;cin>>a>>b>>w;
 	g[a].pb({b,2*w});
 	g[b].pb({a,2*w});
 } 
 vector<int>val(n+1);
 rep(i,1,n+1)cin>>val[i];
 vector<int>v(n+1,0);
 vector<int>d(all(val));
 multiset<pii>ms;
 rep(i,1,n+1)ms.insert({val[i],i});
 while(!ms.empty()){
 	 pii p=*ms.begin();
 	 ms.erase(p);
 	 if(v[p.y])continue;
 	 v[p.y]=1;
 	 int w=p.x;
 	 for(auto i:g[p.y]){
 	 	if(d[i.x]>w+i.y){
 	 		d[i.x]=w+i.y;
 	 		ms.insert({d[i.x],i.x});
 	 	}
 	 }
 }
 for(int i=1;i<=n;i++)cout<<d[i]<<" ";cout<<endl;
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