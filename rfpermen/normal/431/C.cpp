#include <bits/stdc++.h>

#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,k,a,b,c,x,y,z,sz,cnt,ans,ttl,nw;
ll dp[MAX][2];
string s,t;

ll f(int rem,bool st){
	if(rem==0)return st;
	if(rem<0)return 0;
	if(dp[rem][st]!=-1)return dp[rem][st];
	ll tmp = 0;
	int lim = min(k,rem);
	rep(i,1,lim){
		if(i>=x)tmp+= f(rem-i,1);
		else tmp+= f(rem-i,st);
	}
	return dp[rem][st] = tmp%MOD;
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>x;
    memset(dp,-1,sizeof dp);
    cout<<f(n,0);
    return 0;
}