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
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,x[MAX],y,z,res,tmp,sz,m;
string s;
bool st;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,5,n){
    	if(n%i)continue;
    	if(n/i<5)break;
    	m = n/i;
    	s+="aiueo"; rep(j,6,m)s.pb('a');
    	s+="oaiue"; rep(j,6,m)s.pb('i');
    	s+="eoaiu"; rep(j,6,m)s.pb('u');
    	s+="ueoai"; rep(j,6,m)s.pb('e');
    	s+="iueoa"; rep(j,6,m)s.pb('o');
    	rep(j,6,i){
    		s.pb('a');s.pb('i');s.pb('u');s.pb('e');s.pb('o');
    		rep(k,6,m)s.pb('x');
		}
		st = 1;
		break;
	}
	if(!st)cout<<"-1\n";
	else cout<<s<<endl;
	return 0;
}