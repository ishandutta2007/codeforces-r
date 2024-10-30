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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

ll n,m,k,x[MAX],pf[55],sf[55],sm[55],mx[55],z,nw,ans,res[55],cek;
bool neg[55],st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
    	cin>>k;
    	mx[i] = -1e9;
    	st = 1;
    	nw = 0;
    	rep(j,1,k){
    		cin>>x[j], sm[i]+=x[j], pf[i] = max(pf[i],sm[i]);
    		nw+=x[j];
    		if(nw<0)nw = 0;
    		res[i] = max(res[i],nw);
    		if(x[j]>=0)st = 0;
    		mx[i] = max(mx[i],x[j]);
		}
		neg[i] = st;
    	nw = 0;
    	rap(j,k,1)nw+= x[j], sf[i] = max(sf[i],nw);
	}
	cek = -1e9;
	st = 1;
	nw = 0;
	rep(i,1,m){
		cin>>z;
		cek = max(cek,mx[z]);
		st&= neg[z];
		ans = max(ans,nw+pf[z]);
		ans = max(ans,res[z]);
		if(nw+sm[z]<sf[z])nw = sf[z];
		else nw+= sm[z];
	}
	if(st)ans = cek;
	cout<<ans<<endl;
    return 0;
}