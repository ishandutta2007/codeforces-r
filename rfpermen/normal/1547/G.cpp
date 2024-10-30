#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

#define N MAX
vector<int> v[N],mem[N];
bool vis[N], ins[N], lp[N];
int disc[N], low[N], gr[N];
stack<int> st;
int id,grid;
void scc(int cur, int par){
  disc[cur]=low[cur]=++id;
  vis[cur]=ins[cur]=1;
  st.push(cur);
  for(int to : v[cur]){
//    if (to==par) continue; // ini untuk SO(scc undirected)
    if (!vis[to]) scc(to,cur);
    if (ins[to]) low[cur]=min(low[cur],low[to]);	
  }	
  if (low[cur]==disc[cur]){
    grid++; // group id		
    while(ins[cur]){ 		
      gr[st.top()]=grid; ins[st.top()]=0; st.pop();
    }	
  }
}

int n,m,a,b,dp[MAX];


inline void init(int size){
	id = grid = 0;
	rep(i,0,size){
		v[i].clear();
		mem[i].clear();
		vis[i] = lp[i] = 0;
		dp[i] = -1;
	}
	return;
}

int f(int nw){
	if(dp[nw]!=-1)return dp[nw];
	if(nw==gr[1]){
		if(mem[gr[1]].size()>1 || lp[1])return dp[nw] = 10;
		return dp[nw] = 1;
	}
	int ret = 0, tmp;
	for(int i:mem[nw]){
		for(int j:v[i])if(gr[j]!=nw){
			tmp = f(gr[j]);
			if(tmp==10){
				ret = 10;
				break;
			}
			ret = min(2,ret+tmp);
		}
		if(ret==10)break;
	}
	while(mem[nw].empty());
	if(ret && (mem[nw].size()>1 || lp[mem[nw][0]]))ret = 10;
	return dp[nw] = ret;
}

int tc;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n>>m;
		init(n);
		while(m--){
			cin>>a>>b;
			if(a==b){
				lp[a] = 1;
				continue;
			}
			v[b].pb(a);
		}
		rep(i,1,n)if(!vis[i])scc(i,0);
		rep(i,1,n)mem[gr[i]].pb(i);
		int ans;
		rep(i,1,n){
			ans = f(gr[i]);
			if(ans==10)ans = -1;
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}