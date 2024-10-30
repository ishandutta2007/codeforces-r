#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,a,b,p[MAX],st[MAX],ans,mf[MAX],num[MAX],cnt,id,cur;
vector<int> v[MAX],mem[MAX];//,scc[MAX];
stack<int> s;
bool vis[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}
void dfs(int nw){
	s.push(nw);
	vis[nw] = 1;
	num[nw] = mf[nw] = ++cnt;
	for(auto i:v[nw]){
		if(!num[i]){
			dfs(i);
		}
		if(vis[i])mf[nw] = min(mf[nw],mf[i]);
	}
	if(num[nw]==mf[nw]){
		id++;
		while(!s.empty()){
			cur = s.top(); s.pop();
			vis[cur] = 0;
			mf[cur] = mf[nw];
//			scc[id].pb(cur);
			if(cur==nw)break;
		}
	}
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)p[i] = i;
    while(m--){
    	cin>>a>>b;
    	v[a].pb(b);
    	a = par(a), b = par(b);
    	p[b] = a;
	}
	rep(i,1,n)mem[par(i)].pb(i);
	rep(i,1,n){
		if(mem[i].empty())continue;
		id = 0;
		for(auto j:mem[i]){
			if(num[j])continue;
			dfs(j);
		}
		ans+= mem[i].size()-(id==mem[i].size());
	}
	cout<<ans<<endl;
    return 0;
}