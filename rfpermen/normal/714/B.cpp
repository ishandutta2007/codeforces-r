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
#define kn fi.fi
#define ki fi.se
#define ttl se.fi
#define mx se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=5e4+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,x,a[3],c;
set<int> s;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>x;
    	if(s.count(x))continue;
    	s.insert(x);
    	if(s.size()>3)return cout<<"NO",0;
	}
	if(s.size()<3)cout<<"YES";
	else {
		for(auto i:s)a[c++] = i;
		if((a[2]-a[0])&1)cout<<"NO";
		else {
			a[0] = (a[0]+a[2])/2;
			if(a[0]==a[1])cout<<"YES";
			else cout<<"NO";
		}
	}
    return 0;
}