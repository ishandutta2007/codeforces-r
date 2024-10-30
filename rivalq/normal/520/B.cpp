//https://codeforces.com/problemset/problem/520/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n,m;cin>>n>>m;
  vector<int> g[10001];
  for(int i=1;i<10000;i++){
      g[i+1].pb(i);

      if(2*i<=10000)g[i].pb(2*i);
  }
  if(n>m)cout<<n-m<<endl;
  else{
      int visit[2*10000+1]={0};
      int level[2*10000+1]={0};
      queue<int> q;
      q.push(n);
      while(!q.empty()){
          int v=q.front();
          q.pop();
          for(auto i:g[v]){
              if(!visit[i]){
                  visit[i]=1;
                  level[i]=level[i]+level[v]+1;
                  if(i==m)goto abc;
                  else q.push(i);
              }
          }
      }
       abc:
       cout<<level[m]<<endl;
  }

  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}