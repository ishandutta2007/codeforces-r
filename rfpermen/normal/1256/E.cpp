#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,dp[MAX][6],ans[MAX],k;
pll x[MAX];

ll f(int pos,int st){
	if(pos==n){
		if(st<2)return 1e18;
		return x[pos].fi - x[pos-st].fi;
	}
	if(dp[pos][st]!=-1)return dp[pos][st];
	if(st<2)return dp[pos][st] = f(pos+1,st+1);
	if(st==5)return dp[pos][st] = f(pos+1,0)+x[pos].fi - x[pos-st].fi;
	return dp[pos][st] = min(f(pos+1,st+1),f(pos+1,0)+x[pos].fi - x[pos-st].fi);
}
void bt(int pos,int st){
	ans[x[pos].se] = k;
	if(pos==n)return;
	if(st<2)bt(pos+1,st+1);
	else if(st==5)++k, bt(pos+1,0); 
	else if(dp[pos][st]==f(pos+1,st+1))bt(pos+1,st+1);
	else ++k, bt(pos+1,0);
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
    memset(dp,-1,sizeof dp);
    cout<<f(1,0)<<' ';
    k = 1;
    bt(1,0);
    cout<<k<<endl;
    rep(i,1,n)cout<<ans[i]<<' ';
    return 0;
}