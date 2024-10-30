#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define pdb pair<double,bool>
#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,x,y,bit[MAX],ret;

inline void upd(int i,int y){
	for(; i<=n ; i+=(i&-i))bit[i] = max(y,bit[i]);
}

inline int que(int i){
	ret = 0;
	for(; i> 0 ; i-=(i&-i))ret = max(ret,bit[i]);
	return ret;
}

int main(){
	//cout<<fixed<<setprecision(10);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x;
    	upd(x,que(x-1)+1);
	}
	cout<<que(n)<<endl;
    return 0;
}