//https://codeforces.com/contest/1328/problem/D
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
  int n;cin>>n;          
  int a[n];rep3(n)cin>>a[i];
  int b[n];
  b[0]=1;
  for(int i=1;i<n;i++){
    if(a[i]!=a[i-1]){
        if(b[i-1]==1)b[i]=2;
        else b[i]=1;
    }
    else{
        b[i]=b[i-1];
    }
  }          
  if(b[0]==b[n-1] && a[0]!=a[n-1]){
     b[n-1]=3; 
     for(int i=0;i<n-1;i++){
         if(a[i]==a[i+1]){
             for(int j=i+1;j<n;j++){
                 if(b[j]==2)b[j]=1;
                 else b[j]=2;
             }
             break;
         }
     }
  }
  set<int> s;
  rep3(n)s.insert(b[i]);
  cout<<sz(s)<<endl;
  rep3(n)cout<<b[i]<<" ";cout<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}