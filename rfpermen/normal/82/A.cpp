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
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pll>
#define endl "\n"
const ll MAX=1e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,x,y,sz,cnt,tmp,res;
string s,t;
deque<pair<string,int> > dq;

int main(){
    cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dq.pb({"Sheldon\n",1});
    dq.pb({"Leonard\n",1});
    dq.pb({"Penny\n",1});
    dq.pb({"Rajesh\n",1});
    dq.pb({"Howard\n",1});
    cin>>n;
    while(n>0){
    	s = dq.front().fi, x = dq.front().se;
    	dq.pof();
    	n-=x;
    	dq.pb({s,x*2});
	}
	cout<<s;
    return 0;
}