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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

int n,m,x,y,z,sz,cnt,tmp,res,a,b,k;
string s,t;

int main(){
//	cout<<fixed<<setprecision(0);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;n--;
	cin>>s;
	rep(i,0,n){
		if(s[i]=='G')a=i;
		else if(s[i]=='T')b=i;
	}
	if(abs(a-b)%k)cout<<"NO";
	else {
		if(a>b)swap(a,b);
		for(int i = a; i<=b; i+=k){
			if(s[i]=='#')return cout<<"NO",0;
		}
		cout<<"YES";
	}
    return 0;
}