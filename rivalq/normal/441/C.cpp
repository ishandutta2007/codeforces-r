//https://codeforces.com/problemset/problem/441/C
#include<bits/stdc++.h>
#define rep1(i,n,a) for(int i=0;i<n;i+=a)
#define rep2(i,n,a) for(int i=a;i<n;i++)
#define rep3(n)     for(int i=0;i<n;i++)
#define inarr(arr,n) rep1(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define trav(a,x) for(auto x:a)
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define gcd(a,b) __gcd(a,b)
#define pres(a,x) a.find(x)!=a.end()
#define sz(a) (int)a.size()
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<ll,ll>
#define vec vector<int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
#define narak 998244353
const int inf1=1e9;
const ll inf2=1e18;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n,m,k;cin>>n>>m>>k;
  vector<pii> v;
  for(int i=1;i<=n;i++){
      int j,c=0;
      if(i&1){
          j=1;c++;
      }
      else {
          j=m;c--;
      }
      for(j;(c>0)?(j<=m):(j>=1);j+=c){
          v.pb({i,j});
          //cout<<i<<" "<<j<<endl;
      }
  }
  vector<vector<pii>>v2;
  int p=1;
  int i=0;
  while(p<k){
      vector<pii> v3;
      v3.pb(v[i]);
      v3.pb(v[i+1]);
      v2.pb(v3);
      i+=2;
      p++;
  }
  vector<pii> v3;
  for(int j=i;j<v.size();j++){
    v3.pb(v[j]);
  }
  if(v3.size())v2.pb(v3);
  for(int i=0;i<k;i++){
      cout<<v2[i].size()<<" ";
      for(auto j:v2[i])cout<<j.fr<<" "<<j.sc<<" ";cout<<endl;
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