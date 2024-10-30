#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1010205047;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;

int n,k,x[MAX],le,ri,mid,ans,dp[MAX][2];
bool st;

int f(int nw,bool st){
	if(nw>n)return 0;
	if(dp[nw][st]!=-1)return dp[nw][st];
	
	if(st)return dp[nw][st] = max(f(nw+1,st^1)+1, f(nw+1,st));
	if(x[nw]<=mid)return dp[nw][st] = max(f(nw+1,st^1)+1, f(nw+1,st));
	return dp[nw][st] = f(nw+1,st);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i];
    le = 1, ri = MOD;
    while(le<=ri){
    	mid = le+ri>>1;
    	memset(dp,-1,sizeof dp);
    	if(f(1,0)>=k || f(1,1)>=k)ans = mid, ri = mid-1;
    	else le = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}