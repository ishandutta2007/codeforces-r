//https://codeforces.com/contest/58/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int n;
  cin>>n;
  vector<int> v;
  while(n!=1){
      if(n&1){
          v.pb(n);int k=n/2;
          while(n%k!=0) k--;
          n=k;
      }
      else{v.pb(n);n/=2;}

  }
  v.pb(1);
  for(auto i:v) cout<<i<<" ";
  cout<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}