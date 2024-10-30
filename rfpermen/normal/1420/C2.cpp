#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,x[MAX],ans,a,b,l,r,q;

inline void upd(int i){
	if(!i||i>n)return;
	if(x[i+1]>x[i]){
		if(x[i]<=x[i-1])ans-= x[i];
	}
	else if(x[i+1]<x[i]){
		if(x[i]>=x[i-1])ans+= x[i];
	}
	return;
}

inline void del(int i){
	if(!i||i>n)return;
	if(x[i+1]>x[i]){
		if(x[i]<=x[i-1])ans+= x[i];
	}
	else if(x[i+1]<x[i]){
		if(x[i]>=x[i-1])ans-= x[i];
	}
	return;
}

int main(){
// cout<<fixed<<setprecision(2);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>q;
    	rep(i,1,n)cin>>x[i]; x[n+1] = 0;
    	ans = 0;
    	rep(i,1,n)upd(i);
    	cout<<ans<<endl;
		while(q--){
			cin>>l>>r;
			a = x[l], b = x[r];
			rep(i,-1,1)del(l+i);
			x[l] = b;
			rep(i,-1,1)upd(l+i);
			
			rep(i,-1,1)del(r+i);
			x[r] = a;
			rep(i,-1,1)upd(r+i);
			cout<<ans<<endl;
		}
	}
    return 0;
}