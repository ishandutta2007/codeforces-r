#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 1e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int tc,n,x,y,le,ri,mid,res;
vector<int> ans;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    tc = 1;
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	ans.clear();
    	rep(i,1,n){
    		cout<<"? "<<i<<" 1"<<endl;
    		rep(j,1,i)cout<<j<<' '; cout<<endl;
    		cout<<i+1<<endl;
    		cin>>x;
    		if(x){
    			y = i+1;
    			break;
			}
		}
		le = 1,ri = y-1;
		while(le<=ri){
			mid = le+ri>>1;
			cout<<"? "<<mid<<" 1"<<endl;
			rep(j,1,mid)cout<<j<<' '; cout<<endl;
    		cout<<y<<endl;
    		cin>>x;
    		if(x)res = mid, ri = mid-1;
    		else le = mid+1;
		}
		asd(i,1,y)if(i!=res)ans.pb(i);
		rep(i,y+1,n){
			cout<<"? 1 1"<<endl;
			cout<<y<<endl<<i<<endl;
			cin>>x;
			if(!x)ans.pb(i);
		}
		cout<<"! "<<ans.size();
		for(int i:ans)cout<<' '<<i; cout<<endl;
	}
    return 0;
}