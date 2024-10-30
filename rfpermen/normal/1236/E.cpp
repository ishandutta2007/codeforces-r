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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,m,x[MAX],y[MAX<<1],ans;

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n==1)return cout<<"0\n",0;
    rep(i,1,n)y[i+m] = 1;
    rep(i,1,m){
    	cin>>x[i];
    	y[x[i]+m-i-1]+=y[x[i]+m-i];
    	y[x[i]+m-i] = 0;
    	x[i] = n-x[i]+1;
	}
	db(y[1]);
	rep(i,1,n+m)ans+=(min(n+m,i+m+1)-m)*y[i];
	memset(y,0,sizeof y);
    rep(i,1,n)y[i+m] = 1;
    rep(i,1,m){
    	y[x[i]+m-i-1]+=y[x[i]+m-i];
    	y[x[i]+m-i] = 0;
	}
	rep(i,1,n+m)ans+=(min(n+m,i+m+1)-m)*y[i];
	
	cout<<ans-n*n<<endl;
    return 0;
}