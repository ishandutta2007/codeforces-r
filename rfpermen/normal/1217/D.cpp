#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  os << '{';
  bool osu = 1;
  for(auto &i : v) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
template<class T,long long unsigned int size>
ostream& operator<<(ostream& os, const array<T,size> &arr) {
  os << '{';
  bool osu = 1;
  for(auto &i : arr) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
 
#define ll long long
#define ull unsigned long long
#define lll __int128
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
//#define lc (id<<1)
//#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vvll vector<vll>
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
const int MAX = 5e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 5;
inline ll pw(ll x,ll y,ll md){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define N MAX
vector<int> v[N];
bool vis[N], ins[N];
int disc[N], low[N], gr[N];
stack<int> st;
int id, grid;
void scc(int cur, int par) {
  disc[cur] = low[cur] = ++id;
  vis[cur] = ins[cur] = 1;
  st.push(cur);
  for(int to : v[cur]) {
    //if (to==par) continue; // ini untuk SO(scc undirected)
    if(!vis[to])
      scc(to, cur);
    if(ins[to])
      low[cur] = min(low[cur], low[to]);
  }
  if(low[cur] == disc[cur]) {
    grid++; // group id
    while(ins[cur]) {
      gr[st.top()] = grid;
      ins[st.top()] = 0;
      st.pop();
    }
  }
}

int n,m,a,b,ans[MAX],cl=1;
vector<ari(3)> e;
vector<ari(2)> u[MAX];

void dfs(int nw){
	vis[nw] = 1;
	for(auto i:u[nw]){
		if(ans[i[1]])continue;
		if(vis[i[0]])cl = ans[i[1]] = 2;
		else {
			ans[i[1]] = 1;
			dfs(i[0]);
		}
	}
	vis[nw] = 0;
	return;
}

int main(){
//	cout<<fixed<<setprecision(1);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,m){
		cin>>a>>b;
		e.pb({a,b,i});
		v[a].pb(b);
	}
	rep(i,1,n)if(!vis[i])scc(i,0);
	for(auto i:e){
		if(gr[i[0]] != gr[i[1]])ans[i[2]] = 1;
		else {
			u[i[0]].pb({i[1], i[2]});
		}
	}
	mems(vis, 0);
	rep(i,1,n)dfs(i);
	cout<<cl<<endl;
	rep(i,1,m)cout<<ans[i]<<" "; cout<<endl;
	return 0;
}