//https://codeforces.com/problemset/problem/282/E
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
struct node{
   node* sons[2]={NULL,NULL};
   int cnt=0;
};
template<typename node>
struct trie{
   node* root=new node();
   node* create(){
       node* temp=new node();
       temp->sons[0]=NULL;
       temp->sons[1]=NULL;
       temp->cnt=0;
       return temp;
   } 
   void insert(ll p){
       node* temp=root;
       for(int j=40;j>=0;j--){
           temp->cnt++;
           ll k=(((1LL<<j)&p)!=0);
           if(temp->sons[k]==NULL){
               temp->sons[k]=create();
               temp=temp->sons[k];
           }
           else{
               temp=temp->sons[k];
           } 
       }
       temp->cnt++;
   }
   void erase(ll p){
       node* temp=root;
       for(int j=40;j>=0;j--){
           temp->cnt--;
           if(p&(1LL<<j))temp=temp->sons[1];
           else temp=temp->sons[0];
       }
       temp->cnt--;
   }
   ll query(ll a){
      node* temp=root; 
      ll val=0;
      for(int j=40;j>=0;j--){
          ll bit=((1LL<<j)&a);
          if(bit){
              if(temp->sons[0] && temp->sons[0]->cnt>0)val+=(1LL<<j),temp=temp->sons[0];
              else temp=temp->sons[1];
          }
          else{
              if(temp->sons[1] && temp->sons[1]->cnt>0)val+=(1LL<<j),temp=temp->sons[1];
              else temp=temp->sons[0]; 
          }
      }
      return val;
   }
};
trie<node>tree;
int solve(){
 int n;cin>>n;           
 ll a[n];rep3(n)cin>>a[i];
 tree.insert(0);
 tree.insert(a[0]);
 ll g=a[0];
 for(int i=1;i<n;i++){
     g^=a[i];
     tree.insert(g);
 }        
 ll ans=tree.query(0);
 g=0;
 for(int i=n-1;i>=0;i--){
   g^=a[i];
   ans=max(ans,tree.query(g));
 }   
 cout<<ans<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}