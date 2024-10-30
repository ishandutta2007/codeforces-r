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
#define pllll pair<pll,pll>
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
 
ll n,k,y[MAX],z,le,ri,mid,ans,rem,bt,opt[MAX];
pll x[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>z;
    --n;
    rep(i,1,n)cin>>x[i].fi, y[i] = x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
    opt[n+1] = n+1;
    rap(i,n,1)opt[i] = min(x[i].se,opt[i+1]);
    reverse(x+1,x+1+n);
    ans = n+1;
    le = 1, ri = n;
    while(le<=ri){
    	mid = le+ri>>1;
    	rem = z;
    	bt = k-1;
    	rep(i,1,bt){
    		if(x[i].se==opt[mid])++bt;
    		else rem-=x[i].fi;
		}
		if(rem-y[opt[mid]]<0)ans = opt[mid], ri = mid-1;
		else le = mid+1;
	}
	cout<<ans<<endl;
    return 0;
}