//https://codeforces.com/contest/1256/problem/F
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int count(string &s){
  ordered_set s1;
  int a=0;
  for(auto i:s){
     s1.insert(i);
     a+=s1.order_of_key(i);
  }
  return a;
}
int solve(){
  int n;cin>>n;  
  string s,t;cin>>s>>t;
  set<int>s1,s2;
  int a[26]={0},b[26]={0};
  for(auto i:s)s1.insert(i),a[i-97]++;
  for(auto j:t)s2.insert(j),b[j-97]++;
  for(int i=0;i<26;i++){
      if(a[i]!=b[i]){
          cout<<"NO"<<endl;ret;
      }
  }
  if(sz(s1)!=s.length() || sz(s2)!=t.length()){
      cout<<"YES"<<endl;
  }          
  else if(count(s)%2==count(t)%2){
      cout<<"YES"<<endl;
  }          
  else{
      cout<<"NO"<<endl;
  }
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