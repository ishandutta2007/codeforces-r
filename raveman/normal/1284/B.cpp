#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int l[111111];
int f[111111];
int e[111111];
bool d[111111];
int cnt[1<<20];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n){
		scanf("%d",l+i);
		scanf("%d",f+i);
		e[i]=f[i];
		d[i]=true;
		FOR(j,1,l[i]){
			int t;
			scanf("%d",&t);
			if(e[i]<t)d[i]=false;
			e[i]=t;
		}
		if(d[i]){
			cnt[f[i]]++;
		}else cnt[1000000+1]++;
	}
	for(int i=1000000;i>=0;i--)cnt[i]+=cnt[i+1];
	ll res = 0;
	REP(i,n)if(!d[i]){
		res += n;
	}else{
		res += cnt[e[i]+1];
		//f[i]..e[i];
		
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}