#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,m,a,b,c,d,x,y,z,sz,T,mn;
string s,t;
bool v[55][55];

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c>>d>>x>>y;
    rep(i,1,9)rep(j,1,9){
    	if(i+j!=a || i==j)continue;
    	rep(k,1,9){
    		if(i+k!=c || i==k || j==k)continue;
    		rep(o,1,9){
    			if(i==o || j==o || k==o)continue;
    			if(k+o==b && j+o==d && i+o==x && j+k==y)return cout<<i<<" "<<j<<"\n"<<k<<" "<<o,0;
			}
		}
	}
	cout<<-1;
    return 0;
}