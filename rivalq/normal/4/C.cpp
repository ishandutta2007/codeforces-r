//https://codeforces.com/contest/4/problem/C
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
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
#define mod 1000000007
using namespace std;
int solve(){
  int n;cin>>n;
  map<string,int>mp;
  lop(i,n,1){
      string t;cin>>t;
      if(mp.count(t)){
          cout<<t<<mp[t]<<endl;
          mp.insert({t+to_string(mp[t]),1});
          mp[t]++;
      }
      else{
          mp.insert({t,1});
          cout<<"OK"<<endl;
      }
  }

}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}