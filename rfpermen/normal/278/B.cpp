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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n;
string s[35],cek;
bool st;

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>s[i];
    rep(i,0,25){
    	cek = (char)('a'+i);
    	st = 0;
    	rep(k,1,n)if(s[k].find(cek)!=string::npos)st=1;
		if(!st)return cout<<cek,0;
	}
    rep(i,0,25){
    	rep(j,0,25){
    		cek = (char)('a'+i);
			cek+= (char)('a'+j);
	    	st = 0;
	    	rep(k,1,n)if(s[k].find(cek)!=string::npos)st=1;
			if(!st)return cout<<cek,0;
		}
	}
    return 0;
}