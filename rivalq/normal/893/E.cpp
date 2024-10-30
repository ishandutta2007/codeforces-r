//https://codeforces.com/contest/893/problem/E
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
#define cat
ll fact[10000000],infact[10000000];
ll xymodp(ll x,ll y,ll p){
    ll a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
void init(){
    fact[0]=1;
    rep(i,1,1000025)fact[i]=(i*fact[i-1])%hell;
    rep(i,1,1000025)infact[i]=xymodp(fact[i],hell-2,hell);
    infact[0]=1;infact[1]=1;
}

int solve(){
 int x,y;cin>>x>>y;            
 ll ans=xymodp(2,y-1,hell);
 for(int i=2;i<=sqrt(x);i++){
     if(x%i==0){
         int cnt=0;
         while(x%i==0){
             cnt++;x/=i;
         }
         ans=(((ans*fact[cnt+y-1])%hell*infact[cnt])%hell*infact[y-1])%hell;
     }
 }  
 if(x>1){
     ans=(ans*y)%hell;
 }
 cout<<ans<<endl;         
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}