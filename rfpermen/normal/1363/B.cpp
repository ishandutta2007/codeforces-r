#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,ans,a,b;
string s;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>s;
    	ans = s.size();
    	a = b = 0;
    	for(auto i:s)if(i=='0')++a;
    	ans = min(ans,a);
    	for(auto i:s){
    		if(i=='0')--a;
    		else ++b;
    		ans = min(ans,a+b);
		}
		a = b = 0;
		for(auto i:s)if(i=='1')++a;
    	ans = min(ans,a);
    	for(auto i:s){
    		if(i=='1')--a;
    		else ++b;
    		ans = min(ans,a+b);
		}
		cout<<ans<<endl;
	}
	return 0;
}