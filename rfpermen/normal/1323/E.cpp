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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,-1,0,1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll x[MAX],y[MAX],z[MAX],c,d,ans;
int tc,n,m,a,b;
vector<int> v[MAX];
map<pll,ll> hs;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n>>m;
    	rep(i,1,n)v[i].clear(), cin>>x[i], y[i] = z[i] = 0;
    	while(m--){
    		cin>>a>>b;
    		v[a].pb(b);
		}
		c = d = 1;
		rep(i,1,n){
			for(auto j:v[i])y[j]+= c, z[j]+= d;
			c*= 13, d*= 101;
		}
		hs.clear();
		ans = 0;
		rep(i,1,n)if(y[i]&&z[i])hs[{y[i],z[i]}]+= x[i];
		for(auto i:hs)ans = __gcd(ans,i.se);
		cout<<ans<<endl;
	}
    return 0;
}