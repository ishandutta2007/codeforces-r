#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define all(n) n.begin(),n.end()
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

ll n,x,y,z,sz,cnt,tmp,res,a,b,k,m,mn;
//bool v[MAX];
char c;
//set<int> s;
string s,t;
//map<ll,ll> s;

int main(){
//	cout<<fixed<<setprecision(12);
    freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>x;
    if(s.back()=='t'){
    	if(x&1)cout<<'L';
    	else cout<<'R';
	}
	else {
		if(x&1)cout<<'R';
    	else cout<<'L';
	}
    return 0;
}