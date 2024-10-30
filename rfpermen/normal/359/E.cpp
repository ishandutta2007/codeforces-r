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
#define lc (id<<1)
#define rc ((id<<1)|1)
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
const int MAX = 5e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 444;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,a,b,x[MAX][MAX],vr[MAX],vc[MAX];
string ans;
map<pii,char> dir,dor;

void dfs(int r,int c,int xr,int xc,int k){
	if(!x[r][c])ans+= '1', x[r][c] = 1;
	if(!vr[r])vr[r] = c;
	if(!vc[c])vc[c] = r;
	
	int z;
	if(vr[r]==c){
		z = 0;
		rep(i,c+1,n)if(x[r][i])z = i;
		if(z){
			ans+= 'R';
			dfs(r,c+1,0,1,z-c-1);
			ans+= 'L';
		}
		
		z = 0;
		rep(i,1,c-1)if(x[r][i]){
			z = i;
			break;
		}
		if(z){
			ans+= 'L';
			dfs(r,c-1,0,-1,c-z-1);
			ans+= 'R';
		}
	}
	if(vc[c]==r){
		z = 0;
		rep(i,r+1,n)if(x[i][c])z = i;
		if(z){
			ans+= 'D';
			dfs(r+1,c,1,0,z-r-1);
			ans+= 'U';
		}
		
		z = 0;
		rep(i,1,r-1)if(x[i][c]){
			z = i;
			break;
		}
		if(z){
			ans+= 'U';
			dfs(r-1,c,-1,0,r-z-1);
			ans+= 'D';
		}
	}
	if(k && x[r+xr*k][c+xc*k]){
		ans+= dir[{xr,xc}];
		dfs(r+xr,c+xc,xr,xc,k-1);
		ans+= dor[{xr,xc}];
	}
	ans+= '2', x[r][c] = 0;
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	dir[{0,-1}] = 'L';
	dir[{0,1}] = 'R';
	dir[{-1,0}] = 'U';
	dir[{1,0}] = 'D';
	dor[{0,-1}] = 'R';
	dor[{0,1}] = 'L';
	dor[{-1,0}] = 'D';
	dor[{1,0}] = 'U';
	cin>>n>>a>>b;
	rep(i,1,n)rep(j,1,n)cin>>x[i][j];
	dfs(a,b,0,0,0);
	rep(i,1,n)rep(j,1,n)if(x[i][j])return cout<<"NO\n",0;
	cout<<"YES\n"<<ans<<endl;
	return 0;
}