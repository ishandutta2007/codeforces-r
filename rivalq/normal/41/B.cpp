//https://codeforces.com/contest/41/problem/B
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
  int n,b;cin>>n>>b;
  int arr[n];lop(i,n,1)cin>>arr[i];
  int ma=b;
  for(int i=0;i<n;i++){
      if(b>=arr[i]){
          int k=b;
          int d=k/arr[i];
          k%=arr[i];
          for(int j=i+1;j<n;j++){
              if(arr[j]>arr[i]){
                 
                  ma=max(ma,k+d*arr[j]);
              }
          }
      }
  }
  cout<<ma<<endl;
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