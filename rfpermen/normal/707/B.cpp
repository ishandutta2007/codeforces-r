#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,k,ans,a,b,c;
vector<pii> v[MAX];
bool vis[MAX];

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    while(m--){
    	cin>>a>>b>>c;
    	v[a].pb({b,c});
    	v[b].pb({a,c});
	}
	ans = 2e9;
	while(k--){
		cin>>a;
		vis[a]=1;
	}
	rep(i,1,n)if(vis[i])for(auto j:v[i])if(!vis[j.fi])ans = min(ans,j.se);
	if(ans<2e9)cout<<ans;
	else cout<<-1;
    return 0;
}