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

int n,x,y,z,sz,cnt,tmp,res,a,b,k;
map<string,int> m;
string s,t;

int main(){
//	cout<<fixed<<setprecision(12);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    m["monday"] = 0,m["tuesday"] = 1,m["wednesday"] = 2,m["thursday"] = 3;
	m["friday"] = 4,m["saturday"] = 5,m["sunday"] = 6;
	cin>>s>>t;
	x = m[s], y = m[t];
	if(x==y||(y-x+7)%7==3||(y-x+7)%7==2)cout<<"YES";
	else cout<<"NO";
    return 0;
}