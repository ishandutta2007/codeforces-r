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
 
ll n,x[MAX],dp[MAX][2],vis[MAX][2],gb,ans;

ll f(int pos,bool st){
	if(pos<=0||pos>n)return 0;
	if(vis[pos][st]){
		if(vis[pos][st]==gb)dp[pos][st] = -1e18;
		return dp[pos][st];
	}
	vis[pos][st] = gb;
	if(st)return dp[pos][st] = f(pos-x[pos],st^1)+x[pos];
	return dp[pos][st] = f(pos+x[pos],st^1)+x[pos];
}
 
int main(){
//	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n)cin>>x[i];
    rep(i,1,n-1){
    	gb = i;
    	vis[1][0] = vis[1][1] = 0, x[1] = i;
    	ans = f(i+1,1)+i;
    	if(ans<0)ans = -1;
    	cout<<ans<<endl;
	}
    return 0;
}