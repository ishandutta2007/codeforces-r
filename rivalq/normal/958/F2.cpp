//https://codeforces.com/contest/958/problem/F2
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
int solve(){
 int n,m;cin>>n>>m;           
 int a[n],b[m];
 rep3(n)cin>>a[i];
 rep3(m)cin>>b[i];
 map<int,int>mp;
 int cnt=0;
 int j=0;
 for(int i=0;i<m;i++){
     while(j<n && b[i]>mp[i+1]){
          mp[a[j]]++;
          j++;
     }
     if(j==n && b[i]>mp[i+1]){
         cout<<-1<<endl;
         ret;
     }
 }
 for(auto i:mp){
     cnt+=(i.y-b[i.x-1]);
 }
 int ans=cnt;
 for(int i=1;i<n;i++){
     mp[a[i-1]]--;
     if(mp[a[i-1]]>=b[a[i-1]-1]){
         cnt--;
         ans=max(0,min(ans,cnt));
         continue;
     }
     cnt--;
     int f=1;
     while(j<n && f){
         if(a[j]==a[i-1])f=0;
         mp[a[j]]++;j++;cnt++;
     }
     if(j==n&&f){
         cout<<ans<<endl;
         ret;
     }
     ans=max(0,min(ans,cnt));
 }
 cout<<ans<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}