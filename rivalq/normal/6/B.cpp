#include<bits/stdc++.h>
#define rep1(i,n,a)    for(int i=0;i<n;i+=a)
#define rep2(i,n,a)    for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep1(i,n,1)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define trav(a,x)      for(auto x:a)
#define endl           "\n"
#define eb             emplace_back
#define fr             first
#define sc             second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)         (int)a.size()
#define pii            pair<int,int>
#define psi            pair<string,int>
#define pss            pair<string,string>
#define pll            pair<ll,ll>
#define vec            vector<int>
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
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
 int n,m;cin>>n>>m;
 char c;cin>>c;
 char arr[n+1][m+1];
 map<char,int>vi;
 vi['.']=1;
 for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
         cin>>arr[i][j];
     }
 }
 int cnt=0;
 vi[c]=1;
 for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
        if(arr[i][j]==c){
          for(int k=0;k<=3;k++){
              int x=i+dirs[k][0];
              int y=j+dirs[k][1];
              if(x<1 || x>n || y<1 || y>m)continue;
              if(arr[x][y]!='.' && !vi[arr[x][y]]){
                  cnt++;
                  vi[arr[x][y]]=1;
                  //cout<<arr[x][y]<<" ";
                  //cout<<x<<" "<<y<<endl;
              }
 
          }
        }
     }
 }   
 cout<<cnt<<endl;   
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