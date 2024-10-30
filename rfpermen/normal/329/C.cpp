#include<bits/stdc++.h>
 
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
const int MAX = 1e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,a,b,k,id,rem,x[MAX],st,nw,tmp,cnt;
vii ans;
vi v[MAX];
bool vis[MAX];

inline void relax(){
	tmp = 0;
	For(i,0,id)if(!vis[x[i]])x[tmp++] = x[i];
	id = tmp;
	return;
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,m){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	auto it = v[0].begin();
	bool flag;
	rep(i,1,n)sort(all(v[i]));
	for(clock_t start_time = clock(); double(clock() - start_time) / CLOCKS_PER_SEC < 1.0;)
//	rep(iter,1,100)
	{
		mems(vis,0);
		rep(i,1,n)x[i-1] = i;
		id = n;
		k = m;
		rem = n;
		ans.clear();
		while(rem){
			if(rem*2<=id)relax();
			while(1){
				tmp = x[rng()%id];
				if(!vis[tmp])break;
			}
			nw = st = tmp;
			vis[tmp] = 1;
			--rem;
			cnt = 0;
			while(rem && k){
				if(rem*2<=id)relax();
				flag = 0;
				rep(j,1,20){
					while(1){
						tmp = x[rng()%id];
						if(!vis[tmp])break;
					}
					it = lower_bound(all(v[nw]), tmp);
					if(it==v[nw].end() || (*it)!=tmp){
						++cnt;
						vis[tmp] = 1;
						--rem;
						--k;
						ans.pb({nw,tmp});
						nw = tmp;
						flag = 1;
						break;
					}
				}
				if(k && (!flag || rng()%100==69) && cnt>1){
					tmp = st;
					it = lower_bound(all(v[nw]), tmp);
					if(it==v[nw].end() || (*it)!=tmp){
						flag = 0;
						--k;
						ans.pb({nw,tmp});
					}
				}
				if(!flag)break;
			}
			if(!k)break;
		}
		if(!k){
			for(auto i:ans)cout<<i.fi<<" "<<i.se<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}