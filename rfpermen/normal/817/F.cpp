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
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,tree[1<<19],lz[1<<19],a,b,ty;
bool fl[1<<19];
ll op[MAX],x[MAX],y[MAX],cv[MAX];
map<ll,int> hs;

inline void f(int id,int le,int ri){
	if(lz[id]){
		tree[id] = lz[id]==1 ? ri-le+1 : 0;
		if(le!=ri){
			fl[lc] = fl[rc] = 0;
			lz[lc] = lz[rc] = lz[id];
		}
		lz[id] = 0;
	}
	if(fl[id]){
		tree[id] = (ri-le+1) - tree[id];
		if(le!=ri){
			fl[lc]^= 1;
			fl[rc]^= 1;
		}
		fl[id] = 0;
	}
	return;
}

void upd(int id,int le,int ri){
	if(lz[id] || fl[id])f(id,le,ri);
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){
		lz[id] = ty;
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

void flip(int id,int le,int ri){
	if(lz[id] || fl[id])f(id,le,ri);
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){
		fl[id] = 1;
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	flip(lc,le,mid), flip(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

int que(int id,int le,int ri){
	if(lz[id] || fl[id])f(id,le,ri);
	if(tree[id] == ri-le+1)return 0;
	if(le==ri)return le;
	int mid = le+ri>>1;
	int t1 = que(lc,le,mid);
	if(t1)return t1;
	return que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	int id = 0;
	hs[1];
	rep(i,1,n){
		cin>>op[i]>>x[i]>>y[i];
		hs[x[i]];
		hs[y[i]+1];
	}
	for(auto &i:hs)i.se = ++id, cv[id] = i.fi;
	rep(i,1,n){
		a = hs[x[i]], b = hs[y[i]+1]-1;
		if(op[i]==3){
			flip(1,1,id);
		}
		else {
			ty = op[i];
			upd(1,1,id);
		}
		cout<<cv[que(1,1,id)]<<endl;
	}
	return 0;
}