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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll tc,n,x[MAX],y,z,a,b,c,k,sz,tmp,res,id;
string s,t;
vector<int> v;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n>>c>>k;
    	rep(i,1,n)cin>>x[i];
    	sort(x+1,x+1+n);
    	res = 0;
    	tmp = c;
    	v.clear();
    	for(int i = k; i<=n; i+=k){
    		if(tmp<x[i])break;
    		tmp-= x[i];
    		v.pb(i);
		}
		if(v.empty()){
			rep(i,1,n){
    			if(c<x[i])break;
    			++res;
    			c-=x[i];
			}
		}
		else {
			res = v.back();
			rep(i,1,n){
	    		if(i+v.back()>n)break;
	    		tmp = 0;
	    		c-= x[i];
	    		for(auto j:v)tmp+= x[i+j];
	    		if(c<tmp)break;
	    		++res;
			}	
		}
		cout<<res<<endl;
	}
    return 0;
}