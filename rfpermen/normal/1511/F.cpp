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
//#define lll __int128
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
const int MAX = 3e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define SZ 233333
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
namespace linear_seq {
inline vector<int> BM(vector<int> x)
{
	//ls: (shortest) relation sequence (after filling zeroes) so far
	//cur: current relation sequence
	vector<int> ls,cur;
	//lf: the position of ls (t')
	//ld: delta of ls (v')
	int lf,ld;
	for(int i=0;i<int(x.size());++i)
	{
		ll t=0;
		//evaluate at position i
		for(int j=0;j<int(cur.size());++j)
			t=(t+x[i-j-1]*(ll)cur[j])%MOD;
		if((t-x[i])%MOD==0) continue; //good so far
		//first non-zero position
		if(!cur.size())
		{
			cur.resize(i+1);
			lf=i; ld=(t-x[i])%MOD;
			continue;
		}
		//cur=cur-c/ld*(x[i]-t)
		ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
		vector<int> c(i-lf-1); //add zeroes in front
		c.pb(k);
		for(int j=0;j<int(ls.size());++j)
			c.pb(-ls[j]*k%MOD);
		if(c.size()<cur.size()) c.resize(cur.size());
		for(int j=0;j<int(cur.size());++j)
			c[j]=(c[j]+cur[j])%MOD;
		//if cur is better than ls, change ls to cur
		if(i-lf+(int)ls.size()>=(int)cur.size())
			ls=cur,lf=i,ld=(t-x[i])%MOD;
		cur=c;
	}
	for(int i=0;i<int(cur.size());++i)
		cur[i]=(cur[i]%MOD+MOD)%MOD;
	return cur;
}
int m; //length of recurrence
//a: first terms
//h: relation
ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];
//calculate p*q mod f
inline void mull(ll*p,ll*q)
{
	for(int i=0;i<m+m;++i) t_[i]=0;
	for(int i=0;i<m;++i) if(p[i])
		for(int j=0;j<m;++j)
			t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
	for(int i=m+m-1;i>=m;--i) if(t_[i])
		//miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
		for(int j=m-1;~j;--j)
			t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
	for(int i=0;i<m;++i) p[i]=t_[i];
}
inline ll calc(ll K)
{
	for(int i=m;~i;--i)
		s[i]=t[i]=0;
	//init
	s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
	//binary-exponentiation
	while(K)
	{
		if(K&1) mull(s,t);
		mull(t,t); K>>=1;
	}
	ll su=0;
	for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
	return (su%MOD+MOD)%MOD;
}
inline int work(vector<int> x,ll n)
{
	if(n<int(x.size())) return x[n];
	vector<int> v=BM(x); m=v.size(); if(!m) return 0;
	
	for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
	return calc(n);
}
}
using linear_seq::work;

int n,k,dp[10005][9][6][9][6];
string s[10];
vi v;

int f(int nw,int x,int a,int y,int b){
	if(a==s[x].size())x = a = 0;
	if(b==s[y].size())y = b = 0;
	if(!nw)return !x && !y;
	int &ret = dp[nw][x][a][y][b];
	if(ret!=-1)return ret;
	ll res = 0;
	if(!x){
		rep(i,1,n)res+= f(nw,i,0,y,b);
		return ret = res%MOD;
	}
	if(!y){
		rep(i,1,n)res+= f(nw,x,a,i,0);
		return ret = res%MOD;
	}
	if(s[x][a]!=s[y][b])return ret = 0;
	return ret = f(nw-1,x,a+1,y,b+1);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	rep(i,1,n)cin>>s[i];
	mems(dp, -1);
	rep(i,0,10000)v.pb(f(i,0,0,0,0));
	cout<<work(v,k)<<endl;
	return 0;
}