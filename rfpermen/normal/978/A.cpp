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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=200005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,x[1001],cnt;
bool vis[1001];
vector<int> v;
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i];
	rap(i,n,1){
		if(vis[x[i]])continue;
		vis[x[i]]=1;
		v.pb(x[i]);
	}
	cnt=v.size();
	cout<<cnt<<endl;
	rap(i,cnt-1,0)cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}