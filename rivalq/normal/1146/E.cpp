#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int N=100005;
struct node{
    int a=0;
    int real=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
    	 if(n1.real)this->a=n1.a;
    	 else this->a=n2.a;
    	 this->real=1;
    }
}nul;
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      if(par.val==1 || par.val==0)val^=par.val;
      else val=par.val;
  }
  void apply(node &node){
      if(val==1 || val==0)node.a^=val;
      else node.a=val;
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
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=0;
          t[v].real=1;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
  	  if(l>r)return;
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            if(val.val==1)t[v].a^=1;
            else t[v].a=val.val;
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
 int n,m;cin>>n>>m;
 vector<int>vec(n+1);
 rep3(n)cin>>vec[i+1];
 update upd;
 seg.build(1,1,N);
 rep3(m){
 	char c;int x;cin>>c>>x;
 	if(c=='>'){
 		if(x>=0){
           upd.val=3;
           seg.upd(x+1,N,upd);
 		}
 		else{
 			x=abs(x);
 			upd.val=1;
 			seg.upd(1,x-1,upd);
 			upd.val=3;
 			seg.upd(x,N,upd);
 		}
 	}
 	else{
 		if(x>0){
           upd.val=2;
           seg.upd(x,N,upd);
           upd.val=1;
           seg.upd(1,x-1,upd);   
 		}
 		else{
 		    x=abs(x);
 			upd.val=2;
 			seg.upd(x+1,N,upd);
 		}
 	}
 }
 for(int i=1;i<=n;i++){
 	if(vec[i]==0)cout<<vec[i]<<" ";
 	else{
 		auto s=seg.query(abs(vec[i]),abs(vec[i]));
        if(s.a==0)cout<<vec[i]<<" ";
        if(s.a==1)cout<<-1*vec[i]<<" ";
        if(s.a==2)cout<<abs(vec[i])<<" "; 
        if(s.a==3)cout<<-abs(vec[i])<<" "; 
 	}
 }
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    nul.real=0;
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