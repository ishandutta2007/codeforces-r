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
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll q,n,x[MAX],y[MAX],ans,k,a,b,xx,yy,res,id,le,ri,mid;

inline bool cmp(ll aa,ll bb){
	return aa>bb;
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
    	cin>>n;
    	rep(i,1,n)cin>>x[i], x[i]/=100;
		sort(x+1,x+1+n,cmp);
		
    	cin>>xx>>a;
    	cin>>yy>>b;
    	cin>>k;
    	
		le = 1, ri = n, ans = -1;
		while(le<=ri){
			mid = le+ri>>1;
			res = id = 0;
	    	rep(i,1,mid){
	    		if(i%a==0&&i%b==0)y[++id] = xx+yy;
	    		else if(i%a==0)y[++id] = xx;
	    		else if(i%b==0)y[++id] = yy;
			}
			sort(y+1,y+1+id,cmp);
	    	rep(i,1,id)res+=y[i]*x[i];
			
			if(res>=k)ans = mid, ri = mid-1;
			else le = mid+1;
		}
		
		cout<<ans<<endl;
	}
    return 0;
}