#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=5e4+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,x,y,z,a,b,ans,ls;
char c[MAX];

int main(){
	//cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    rep(i,1,n)cin>>c[i];
    sort(c+1,c+1+n);
    ls = c[1];
    y=1;
    ans = c[1]  -'a';
    rep(i,2,n){
    	if(c[i]<ls+2)continue;
    	if(y==x)break;
    	//cout<<(char)ls<<" "<<c[i]<<endl;
    	y++;
    	ls = c[i];
    	ans += c[i]-'a';
	}
    if(y==x)cout<<ans+x<<endl;
    else cout<<-1<<endl;
    return 0;
}