#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int id,ans;
string s,nm[MAX];
vector<int> v[MAX];
stack<int> par;

void dfs(int pos){
	if(nm[pos]==s)++ans;
	for(auto i:v[pos])dfs(i);
	return;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("class_treasurer.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    par.push(0);
    id = 1;
	for(auto i:s){
   		if(i>='A'&&i<='Z')nm[id].pb(i);
   		else {
			if(!nm[id].empty())v[par.top()].pb(id), par.push(id), ++id;
			if(i=='.')par.pop();
		}
	}
	--id;
	rep(i,1,id){
		s = nm[i];
		for(auto j:v[i])dfs(j);
	}
	cout<<ans<<endl;
	return 0;
}