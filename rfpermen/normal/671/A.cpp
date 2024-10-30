#include <bits/stdc++.h>

#pragma GCC optimize("Os")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n;
double ttl,ans,x[MAX],y[MAX],a1,a2,b1,b2,c1,c2,tmp;
pair<double,int> aa[MAX],bb[MAX];

int main(){
	cout<<fixed<<setprecision(12);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>a1>>a2>>b1>>b2>>c1>>c2;
	cin>>n;
	rep(i,1,n){
		cin>>x[i]>>y[i];
		tmp = hypot(x[i]-c1,y[i]-c2);
		ttl+= 2*tmp;
		aa[i] = {hypot(x[i]-a1,y[i]-a2)-tmp,i};
		bb[i] = {hypot(x[i]-b1,y[i]-b2)-tmp,i};
	}
	sort(aa+1,aa+1+n);
	sort(bb+1,bb+1+n);
	ans = 1e18;
	rep(i,1,n){
		ans = min(ans,ttl+aa[i].fi);
		if(bb[1].se!=aa[i].se)ans = min(ans,ttl+aa[i].fi+bb[1].fi);
		else ans = min(ans,ttl+aa[i].fi+bb[2].fi);
	}
	cout<<min(ans,min(ans,ttl+bb[1].fi))<<endl;
	return 0;
}