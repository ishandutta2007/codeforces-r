#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,k,x,y,ans,nw,nw2,mx,le,id;
pii z[MAX];
map<int,int> cnt;
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n>>k;
    	cnt.clear();
    	id = 0;
    	rep(i,1,n)cin>>x, ++cnt[x];
    	rep(i,1,n)cin>>y;
    	for(auto i:cnt)z[++id] = i;
    	ans = mx = nw = nw2 = 0, le = 1;
    	rep(i,1,id){
    		nw-= z[i-1].se;
    		pq.push(z[i-1]);
    		nw2+= z[i-1].se;
    		while(!pq.empty() && z[i-1].fi-pq.top().fi>k)nw2-= pq.top().se, pq.pop();
    		mx = max(mx,nw2);
    		while(le<=id && z[le].fi-z[i].fi<=k)nw+= z[le].se, ++le;
    		ans = max(ans,nw+mx);
		}
		cout<<ans<<endl;
		while(!pq.empty())pq.pop();
	}
	return 0;
}