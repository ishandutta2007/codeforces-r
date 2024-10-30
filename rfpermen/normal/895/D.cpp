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
const int MAX = 1e6+5;
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

ll fc[MAX],pre[MAX];
inline void combin(int n){
	fc[0] = 1;
	rep(i,1,n)fc[i] = fc[i-1]*i%MOD;
	pre[n] = pw(fc[n],MOD-2);
	rap(i,n-1,0)pre[i] = pre[i+1]*(i+1)%MOD;
}
inline ll cb(int n,int k){
	if(k>n || k<0)return 0;
	return fc[n] * pre[k] % MOD * pre[n-k] % MOD;
}
int n;
int dp[2][2][MAX],cnt[26],x[26][MAX],y[26][MAX];
string s,t;

int f(int nw,int a,int b){
	if(nw==n)return 0;
	int &retu = dp[a][b][nw];
	if(retu!=-1)return retu;
	ll tmp = fc[n-nw-1];
	if(a){
		rep(i,0,25)tmp = tmp*pre[x[i][nw]]%MOD;
	}
	else {
		rep(i,0,25){
			if(y[i][nw]<0)return retu = 0;
			tmp = tmp*pre[y[i][nw]]%MOD;
		}
	}
	ll ret = 0;
	if(a){
		if(b){
			rep(i,s[nw],t[nw])if(x[i][nw]){
				if(i!=s[nw] && i!=t[nw]){
					ret+= tmp*x[i][nw] % MOD;
				}
				else {
					ret+= f(nw+1,i==s[nw],i==t[nw]);
				}
			}
		}
		else {
			rep(i,s[nw],25)if(x[i][nw]){
				if(i!=s[nw]){
					ret+= tmp*x[i][nw] % MOD;
				}
				else {
					ret+= f(nw+1,i==s[nw],0);
				}
			}
		}
	}
	else { //if(b)
		rep(i,0,t[nw])if(y[i][nw]){
			if(i!=t[nw]){
				ret+= tmp*y[i][nw] % MOD;
			}
			else {
				ret+= f(nw+1,0,i==t[nw]);
			}
		}
	}
	return retu = ret%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	combin(MAX-5);
	cin>>s>>t;
	for(auto &i:s)i-= 'a', ++cnt[i];
	for(auto &i:t)i-= 'a';
	n = s.size();
	For(i,0,n){
		rep(j,0,25)x[j][i] = cnt[j];
		--cnt[s[i]];
	}
	rep(j,0,25)cnt[j] = x[j][0];
	For(i,0,n){
		rep(j,0,25)y[j][i] = cnt[j];
		--cnt[t[i]];
	}
	mems(dp,-1);
	rap(i,n-1,0){
		f(i,1,0);
		f(i,1,1);
		f(i,0,1);
	}
	cout<<f(0,1,1)<<endl;
	return 0;
}