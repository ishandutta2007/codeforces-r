#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

double x,y,r,x1,y1,r1,py,mn,mx;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>r;
    cin>>x1>>y1>>r1;
    py = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
    //cout<<py<<endl;
	mn = min(r1,r);
	mx = max(r1,r);
    if(py>=r+r1)cout<<(py-r-r1)/2.0<<endl;
	else if(py>=mx-mn)cout<<0.0<<endl;
	else {
		py = (py-r-r1)/2.0;
		py+=mn;
		cout<<-py<<endl;
	}
    return 0;
}