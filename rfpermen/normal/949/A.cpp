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
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
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
#define mems(x,y) memset(x,y,sizeof x)
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
const int MAX = 2e5+5;
const ll MOD = 2010408371;
const ll MOD2 = 2010405347;
const ll INF = 6e13;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}
//ll fc[MAX],pre[MAX];
//inline ll cb(int n,int k){
//	if(k>n)return 0;
//	return fc[n] * pre[k] % MOD * pre[n-k] % MOD;
//}
//inline void combin(int N){
//	fc[0] = 1;
//	For(i,1,N)fc[i] = fc[i-1]*i%MOD;
//	pre[N-1] = pw(fc[N-1],MOD-2);
//	rap(i,N-2,0)pre[i] = pre[i+1]*(i+1)%MOD;
//}

int nw;
string s;
set<int> a,b;
vector<vi> ans;
vi tmp;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s;
	For(i,0,s.size())s[i]=='0' ? a.insert(i+1) : b.insert(i+1);
	while(a.size() || b.size()){
		if(b.size()){
			if(!a.size() || (*b.begin())<(*a.begin()) || (*b.rbegin())>(*a.rbegin()))return cout<<"-1\n",0;
		}
		nw = st = 0;
		tmp.clear();
		while(1){
			if(st){
				if(!b.size() || nw>(*b.rbegin()))break;
				nw = *b.lower_bound(nw);
				b.erase(nw);
			}
			else {
				nw = *a.lower_bound(nw);
				a.erase(nw);
			}
			tmp.pb(nw);
			st^=1;
		}
		ans.pb(tmp);
	}
	cout<<ans.size()<<endl;
	for(vi i:ans){
		cout<<i.size();
		for(int j:i)cout<<' '<<j;
		cout<<endl;
	}
	return 0;
}