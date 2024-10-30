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
#define vlll vector<pll>
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
const int MAX = 1e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 20;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,r,b[35],p[35];
ll z[35],ans=-INF,nw;
vi a;

void f(vi a, int rem){
	if(!rem){
		nw = 0;
		For(i,0,n)nw+= z[i]*a[i];
		ans = max(ans, nw);
		return;
	}
	For(j,0,n)a[j]^= b[j];
	--rem;
	if(!rem){
		nw = 0;
		For(i,0,n)nw+= z[i]*a[i];
		ans = max(ans, nw);
		return;
	}
	vi c(n);
	rep(i,1,rem){
		For(j,0,n)c[j] = a[p[j]] + r;
//		cout<<a<<" => "<<c<<endl;
		a = c;
		f(a, rem-i);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	n = 30;
//	rep(i,1,30)a.pb(i);
//	shuffle(all(a), rng);
//	rep(i,1,n)cout<<(rng()%10000)+1<<" "; cout<<endl;
//	rep(i,1,n)cout<<(rng()%10000)+1<<" "; cout<<endl;
//	rep(i,1,n){
//		k = rng()%20000;
//		cout<<10000-k<<" "; 
//	}cout<<endl;
//	for(int i:a)cout<<i<<" "; cout<<endl;
//	return 0;
	cin>>n>>k>>r;
	a.resize(n);
	For(i,0,n)cin>>a[i];
	For(i,0,n)cin>>b[i];
	For(i,0,n)cin>>z[i];
	For(i,0,n)cin>>p[i], --p[i];
	for(int i = k; i>=0; i-= 2){
		f(a,i);
		For(j,0,n)a[j]^= b[j];
		f(a,i+1);
		For(j,0,n)a[j]^= b[j];
	}
	cout<<ans<<endl;
	return 0;
}