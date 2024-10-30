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
//#define sf se.fi
//#define ss se.se
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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,dp[10][MAX],x[MAX],fc[MAX],pre[MAX],ans;
bool st;

inline pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll f(int nw,int rem){
	if(nw==10)return rem==0;
	if(dp[nw][rem]!=-1)return dp[nw][rem];
	ll ret = 0;
	rep(i,x[nw],rem)ret = (ret + f(nw+1,rem-i)*pre[i])%MOD;
	return dp[nw][rem] = ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fc[0] = pre[0] = 1;
    rep(i,1,100)fc[i] = fc[i-1] * i % MOD, pre[i] = pw(fc[i],MOD-2);
    cin>>n;
    rep(i,0,9)cin>>x[i];
    rep(i,1,9){
    	if(x[i])st = 1, --x[i];
    	else st = 0;
    	memset(dp,-1,sizeof dp);
    	rap(j,n-1,0)ans = (ans + f(0,j)*fc[j])%MOD;
    	if(st)x[i]++;
	}
	cout<<ans<<endl;
    return 0;
}