#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

ll qp(ll c,ll st,ll mod){
	ll r = 1;
	while(st){
		if(st&1) r*=c,r%=mod;			
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,m;
	cin>>n>>m;
	int res = qp(3,n,m)-1;
	if(res<0) res+=m;
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}