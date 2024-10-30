#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 4e3+5;
const ll MAX2 = 11;
const ll MOD = 131071;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int r[4],x[10][10],a,b;
bool st;
char c[4];

inline void tehe(){
    rap(i,a-1,1){
    	if(i==r[2]&&b==c[2])break;
    	x[i][b] = 0;
	}
    rep(i,a+1,8){
    	if(i==r[2]&&b==c[2])break;
    	x[i][b] = 0;
	}
    rap(i,b-1,1){
    	if(a==r[2]&&i==c[2])break;
    	x[a][i] = 0;
	}
    rep(i,b+1,8){
    	if(a==r[2]&&i==c[2])break;
    	x[a][i] = 0;
	}
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,8)rep(j,1,8)x[i][j] = 1;
    rep(i,0,3)cin>>c[i]>>r[i], c[i]-='a'-1;
    a = r[0], b = c[0], tehe();
    a = r[1], b = c[1], tehe();
    a = r[2], b = c[2];
    rep(k,0,7)x[a+dr[k]][b+dc[k]] = 0;
    a = r[3], b = c[3];
    rep(i,-1,1)rep(j,-1,1)st|= x[a+i][b+j];
    if(st)cout<<"OTHER\n";
    else cout<<"CHECKMATE\n";
    return 0;
}