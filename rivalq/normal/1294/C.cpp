//https://codeforces.com/contest/1294/problem/C
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
 int n;cin>>n;
 int m=n;
 int cnt=0;
 map<int,int> mp;
 for(int i=2;i<=sqrt(n);i++){
     if(n%i==0){
         while(n%i==0)n/=i,mp[i]++;
         cnt++;
     }
 }
 if(n>2)mp[n]++,cnt++;
 if(cnt==0){
     cout<<"NO"<<endl;
     ret;
 }
 auto itr=mp.begin();
 int k=itr->fr;
 itr++;
 int k2;
 if(itr!=mp.end())k2=itr->fr;
 if(cnt>2){
     
     m/=k;
     m/=k2;
     cout<<"YES"<<endl;
     cout<<k<<" "<<k2<<" "<<m<<endl;
}
else if(cnt==2){
    if(mp[k]+mp[k2]>3){
         m/=k;
         m/=k2;
         cout<<"YES"<<endl;
        cout<<k<<" "<<k2<<" "<<m<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
else{
    m/=k;
    m/=k;
    m/=k;
   if(mp[k]>5)cout<<"YES\n"<<k<<" "<<k*k<<" "<<m<<endl;
   else cout<<"NO"<<endl;
}
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}