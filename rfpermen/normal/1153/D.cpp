#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,sz[MAX],z;
bool x[MAX];
vector<int> v[MAX];

int f(int nw){
	if(v[nw].empty()){
		sz[nw] = 1;
		return 1;
	}
	int res,hit;
	if(x[nw]){
		hit = 1e9;
		for(auto i:v[nw]){
			res = f(i);
			hit = min(hit,sz[i]-res);
			sz[nw]+=sz[i];
		}
		return sz[nw]-hit;
	}
	{
		hit = 1;
		for(auto i:v[nw]){
			res = f(i);
			hit+= res-1;
			sz[nw]+=sz[i];
		}
		return hit;
	}
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n)cin>>z, v[z].pb(i);
    cout<<f(1)<<endl;
	return 0;
}