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

ll n,m,a,b,c,x,y,z,sz,cnt,ans,tmp;
string s,t;
bool r[MAX],mt[100][100];
int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>a>>b;
    while(--n){
    	cin>>x>>y;
    	if(y-x==1)mt[x][y] = 1;
    	x++, y--;
    	rep(i,x,y)r[i] = 1;
	}
	b++;
	r[b]=1;
	rep(i,a,b){
		if(r[i]==1 && cnt==0)continue;
		else if(r[i]==1){
			ans+=cnt-1;
			cnt = 0;
		}
		else if(cnt && mt[i-1][i]){
			ans+=cnt-1;
			cnt = 1;
		}
		else cnt++;
	}
	cout<<ans<<endl;
    return 0;
}