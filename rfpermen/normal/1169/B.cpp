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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,x[MAX],y[MAX],a,b;
bool st;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>n;
    rep(i,1,n)cin>>x[i]>>y[i];
    a = b = -1;
    a = x[1];
    st = 1;
    rep(i,2,n){
    	if(x[i]==a||y[i]==a)continue;
    	b = x[i];
    	rep(j,i+1,n){
    		if(x[j]==a||y[j]==a)continue;
    		if(x[j]==b||y[j]==b)continue;
    		st = 0;
    		break;
		}
		if(st)break;
		st = 1;
    	b = y[i];
    	rep(j,i+1,n){
    		if(x[j]==a||y[j]==a)continue;
    		if(x[j]==b||y[j]==b)continue;
    		st = 0;
    		break;
		}
		break;
	}
	if(st)return cout<<"YES\n",0;
    a = b = -1;
    a = y[1];
    st = 1;
    rep(i,2,n){
    	if(x[i]==a||y[i]==a)continue;
    	b = x[i];
    	rep(j,i+1,n){
    		if(x[j]==a||y[j]==a)continue;
    		if(x[j]==b||y[j]==b)continue;
    		st = 0;
    		break;
		}
		if(st)break;
		st = 1;
    	b = y[i];
    	rep(j,i+1,n){
    		if(x[j]==a||y[j]==a)continue;
    		if(x[j]==b||y[j]==b)continue;
    		st = 0;
    		break;
		}
		break;
	}
	if(st)return cout<<"YES\n",0;
	cout<<"NO\n";
	return 0;
}