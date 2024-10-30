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
const int MAX = 20+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,z,l,r,dp[30][2][2][2][2],ans;

ll f(int pos,bool x,bool y,bool a,bool b){
	if(pos<0)return 1;
	ll &ret = dp[pos][x][y][a][b];
	if(ret!=-1)return ret;
	ret = 0;
	if(r&(1<<pos)){
		if(l&(1<<pos)){
			//0 0
			if(a&b)ret+= f(pos-1,1,1,a,b);
			//1 0
			if(b)ret+= f(pos-1,x,1,a,b);
			//0 1
			if(a)ret+= f(pos-1,1,y,a,b);
		}
		else {
			//0 0
			ret+= f(pos-1,1,1,a,b);
			//1 0
			ret+= f(pos-1,x,1,1,b);
			//0 1
			ret+= f(pos-1,1,y,a,1);
		}
	}
	else {
		if(l&(1<<pos)){
			//0 0
			if(a&b)ret+= f(pos-1,x,y,a,b);
			//1 0
			if(b&x)ret+= f(pos-1,x,y,a,b);
			//0 1
			if(a&y)ret+= f(pos-1,x,y,a,b);
		}
		else {
			//0 0
			ret+= f(pos-1,x,y,a,b);
			//1 0
			if(x)ret+= f(pos-1,x,y,1,b);
			//0 1
			if(y)ret+= f(pos-1,x,y,a,1);	
		}
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>l>>r;
    	memset(dp,-1,sizeof dp);
    	cout<<f(29,0,0,0,0)<<endl;
	}
    return 0;
}