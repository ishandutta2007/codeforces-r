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
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  int arr1[26]={0};
  int arr2[26]={0};
  for(int i=0;s1[i]!='\0';i++)arr1[s1[i]-65]++;
  for(int i=0;s2[i]!='\0';i++)arr1[s2[i]-65]++;
  for(int i=0;s3[i]!='\0';i++)arr2[s3[i]-65]++;
  for(int i=0;i<26;i++){
  	if(arr1[i]!=arr2[i]){
  		cout<<"NO"<<endl;
  		ret;
  	}
  }	
  cout<<"YES"<<endl;
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