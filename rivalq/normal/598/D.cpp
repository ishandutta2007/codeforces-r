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
const int maxn=1000005;
int p[maxn];
int sz[maxn];
int cnt[maxn];
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
        cnt[p1]+=cnt[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
        cnt[p2]+=cnt[p1];
    }
}

int solve(){
 	int n,m,k;cin>>n>>m>>k;
 	vector<vector<char>>a(n+1,vector<char>(m+1));
 	rep(i,1,n+1){
 		rep(j,1,m+1){
 			cin>>a[i][j];
 		}
 	}
 	auto f=[&](int i,int j){
              return (i-1)*m+j; 
 	};
 	rep(i,1,n+1){
 		rep(j,1,m+1){
 			if(a[i][j]=='*')continue;
 			if(i>0 && a[i-1][j]=='*')cnt[f(i,j)]++;
 			if(j>0 && a[i][j-1]=='*')cnt[f(i,j)]++;
                        if(i<n && a[i+1][j]=='*')cnt[f(i,j)]++;
 			if(j<m && a[i][j+1]=='*')cnt[f(i,j)]++;
 		}
 	}
 	rep(i,1,n+1){
 		rep(j,1,m+1){
 			if(a[i][j]=='*')continue;
 			if(i>0 && a[i-1][j]=='.')merge(f(i,j),f(i-1,j));
 			if(j>0 && a[i][j-1]=='.')merge(f(i,j),f(i,j-1));
                        if(i<n && a[i+1][j]=='.')merge(f(i,j),f(i+1,j));
 			if(j<m && a[i][j+1]=='.')merge(f(i,j),f(i,j+1));
 		}
 	}
        rep3(k){
        	int x,y;cin>>x>>y;
        	cout<<cnt[root(f(x,y))]<<endl;
        } 
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
    clear();
    while(t--){
        solve();
    }
    return 0;
}