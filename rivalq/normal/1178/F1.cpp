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
#define hell           998244353
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
template<int mod>
struct mint {
  int x;
  mint():x(0){}
  mint(int x):x((x%mod+mod)%mod){}
  // mint(int x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}

  friend istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
  friend ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
  mint<mod> expo(mint<mod> x,int y){
       mint<mod> a=1;
       while(y){
       	 if(y&1)a=a*x;
       	 x=x*x;
       	 y/=2;
       }
       return a;
  }
};
template<int mod>
int operator+=(int& b,mint<mod> a){return b=b+a.x;};
mint<hell>dp[501][501];
bool  vis[501][501];
int pos[501];
int c[501];
mint<hell>zeno(int l,int r){
	if(l>r)return 1;
	if(l==r)return dp[l][l]=1;
	if(l+1==r)return dp[l][l+1]=2;
	if(vis[l][r])return dp[l][r];
	vis[l][r]=1; 
	dp[l][r]=1;
    int mi=hell;
    for(int i=l;i<=r;i++)mins(mi,c[i]);
    int idx=pos[mi];
    if(idx==l){
    	dp[l][r]=zeno(l+1,r)+zeno(l+1,r);
    	for(int i=l+1;i<r;i++)dp[l][r]=dp[l][r]+zeno(l+1,i)*zeno(i+1,r);
    	return dp[l][r];	
    }
    if(idx==r){
       dp[l][r]=zeno(l,r-1)+zeno(l,r-1);
       for(int i=l;i<r-1;i++)dp[l][r]=dp[l][r]+zeno(l,i)*zeno(i+1,r-1);	
       return dp[l][r];	
    }
    mint<hell> val1=zeno(l,idx-1)+zeno(l,idx-1);
    mint<hell> val2=zeno(idx+1,r)+zeno(idx+1,r);
    for(int i=l;i<idx-1;i++){
    	val1=val1+zeno(l,i)*zeno(i+1,idx-1);
    }
    for(int i=idx+1;i<r;i++){
    	val2=val2+zeno(idx+1,i)*zeno(i+1,r);
    }
    return dp[l][r]=val1*val2;
}
int solve(){
 int n,m;cin>>n>>m;
 rep(i,1,n+1)cin>>c[i],pos[c[i]]=i;
 cout<<zeno(1,n)<<endl;
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