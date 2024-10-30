// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 2e5 + 5;

struct node{
    int a=0;
    int b=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
        if(a == n1.a)b = n1.b;
        else b = n2.b;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val+=par.val;
  }
  void apply(node &node){
      node.a+=val;
      val=0;
  }
};
template<typename node,typename update>
struct segtree{
  node t[4*N];
  bool lazy[4*N];
  update zaker[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;
  inline void pushdown(int v){
     if(lazy[v]){    
       apply(zaker[v],v);
       lazy[v]=0;
       zaker[v].apply(t[v]);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end,vector<int>& arr){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
          t[v].b=tl[v];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a+=val.val;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return nul;
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v];
      }
      node a=query(2*v,l,r);
      node b=query(2*v+1,l,r);
      node ans;
      ans.merge(a,b);
      return ans;
  }
public:
  node query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};

segtree<node,update>seg;

int solve(){
 		int n,k; cin >> n >> k;
 		vector<vector<int>>g(n + 1);
 		for(int i = 2; i <= n; i++){
 			int u,v; cin >> u >> v;
 			g[u].push_back(v);
 			g[v].push_back(u);
 		}
 		vector<int> leafs(n + 1),d(n + 1);
 		vector<int> in(n + 1),out(n + 1),par(n + 1);
 		int t = 0;
 		function<void(int,int)> dfs = [&](int u,int p){

 				in[u] = ++t;
 				for(auto i:g[u]){
 					if(i != p){
 						par[i] = u;
 						d[i] = d[u] + 1;
 						dfs(i,u);
 					}
 				}
 				out[u] = t;
 		};
 		d[1] = 1;
 		par[1] = 1;
 		dfs(1,1);
 		vector<int> arr(n + 1),inv(n + 1);
 		for(int i = 1; i <= n; i++){
 			arr[in[i]] = d[i];
 			inv[in[i]] = i;
 		}
 		
 		seg.build(1,1,n,arr);

 		auto get_max = [&](int r,int b){
 			b = min(n/2,b);
 			int val = n*r - r*r + b*b - n*b;
 			return val;
 		};

 		int ans = LLONG_MIN;
 		int b = n;
 		vector<int> vis(n + 1);
 		for(int i = 1; i <= k; i++){
 			auto s = seg.t[1];
 			b -= s.a;
 			int u = inv[s.b];
 			while(!vis[u]){
 				vis[u] = 1;
 				seg.upd(in[u],out[u],-1);
 				u = par[u];
 			}
 			maxs(ans,get_max(i,b));
 		}
 		cout << ans << endl;



 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}