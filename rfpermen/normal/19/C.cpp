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
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int k,n,sa[18][MAX<<1],cnt[MAX],stp,jmp,id,z[MAX],ans,x,y[MAX];
int snw[MAX],snx[MAX];
vector<int> v[MAX];
map<int,int> hs;

int nx,ret;
inline int getlcp(int x,int y){
	ret = 0, nx = jmp;
	rap(i,stp,0){
		if(y+nx<=n+1 && sa[i][x]==sa[i][y]){
			ret+= nx;
			x+= nx, y+=nx;
		}
		nx>>=1;
	}
	return ret;
}
vector<pii> u;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x; y[i] = x;
    	if(!hs.count(x))hs[x] = ++id;
    	x = hs[x];
    	v[x].pb(i), sa[0][i] = x;
	}
    
    jmp = 1;
    while(jmp<n){
    	mems(cnt,0);
    	rep(i,1,n)++cnt[sa[stp][i+jmp]];
    	rep(i,1,n)cnt[i]+= cnt[i-1];
    	rap(i,n,1)snx[cnt[sa[stp][i+jmp]]--] = i;
    	
    	mems(cnt,0);
    	rep(i,1,n)++cnt[sa[stp][i]];
    	rep(i,1,n)cnt[i]+= cnt[i-1];
    	rap(i,n,1)snw[cnt[sa[stp][snx[i]]]--] = snx[i];
    	
    	++stp;
    	sa[stp][snw[1]] = 1;
    	rep(i,2,n)sa[stp][snw[i]] = sa[stp][snw[i-1]] + !(sa[stp-1][snw[i]] == sa[stp-1][snw[i-1]]
		&& sa[stp-1][snw[i]+jmp] == sa[stp-1][snw[i-1]+jmp]);
		jmp<<=1;
	}
	
//	rep(i,1,n)z[sa[stp][i]] = i;
//	rep(i,1,n){
//		printf("%-3d",z[i]);
//		rep(j,z[i],n)printf("%d ",sa[0][j]); puts("");
//	}
//	db(getlcp(3,6));
	
	ans = 1;
	rep(i,1,id){
		k = v[i].size()-1;
		rap(j,k,0){
			rap(o,j-1,0)if(getlcp(v[i][o],v[i][j])>=v[i][j]-v[i][o]){
				u.pb({v[i][j]-v[i][o],v[i][j]});
			}
		}
	}
	sort(all(u));
	for(pii i:u)if(i.se-i.fi>=ans)ans = i.se;
	
	cout<<n-ans+1<<endl;
	rep(i,ans,n)cout<<y[i]<<' '; cout<<endl;
	return 0;
}