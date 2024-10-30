#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,n,m,p[MAX],cnt,nw,tmp,a,b;
bool st[MAX];
vector<int> v[MAX],ans;
stack<int> cnd;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

inline void ins(int x){
	st[x] = 1, ans.pb(x);
	for(int i:v[x])if(!st[i])cnd.push(i), st[i] = 1;
	return;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	rep(i,1,n)p[i] = i, v[i].clear();
    	cnt = 0;
    	rep(i,1,m){
    		cin>>a>>b;
    		v[a].pb(b);
    		v[b].pb(a);
    		a = par(a), b = par(b);
    		if(a!=b)p[a] = b, ++cnt;
		}
		if(cnt!=n-1){
			cout<<"NO\n";
			continue;
		}
		ans.clear();
		rep(i,1,n)st[i] = 0;
		ins(1);
		while(!cnd.empty()){
			nw = cnd.top(), cnd.pop();
			for(int i:v[nw])if(!st[i])ins(i);
		}
		cout<<"YES\n";
		cout<<ans.size()<<endl;
		for(int i:ans)cout<<i<<' '; cout<<endl;
	}
    return 0;
}