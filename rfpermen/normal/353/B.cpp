#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,x[205],cnt,z[205],st;
vector<int> y[105];
set<int> s[2];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    n*=2;
    rep(i,1,n){
    	cin>>x[i];
    	y[x[i]].pb(i);
	}
	rep(i,1,100){
		if(!y[i].empty()){
			z[y[i].back()] = 1+st;
			s[st].insert(i);
			st^=1;
			y[i].pob();
		}
		if(!y[i].empty()){
			z[y[i].back()] = 1+st;
			s[st].insert(i);
			st^=1;
			y[i].pob();
		}
	}
	rep(i,1,100){
		while(!y[i].empty()){
			z[y[i].back()] = 1+st;
			s[st].insert(i);
			st^=1;
			y[i].pob();
		}
	}
	cout<<s[0].size()*s[1].size()<<endl;
	rep(i,1,n)cout<<z[i]<<' ';
	return 0;
}