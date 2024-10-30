#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
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

int n;
ll x[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	ll prev = 0;
	for(int i=1;i<n;i+=2){
		int t;
		scanf("%d",&t);
		x[i]=t;
		
		int sb=-1,sa=-1;
		for(int bma=1;bma*bma<=t;bma++)if(t%bma==0){
			int bpa=t/bma;

			int b = (bma + bpa)/2;
			int a = bpa - b;
			if(a+b==bpa && b-a==bma && a>prev){
				if(sb==-1 || sb>b){
					sb=b;
					sa=a;
				}
			}
		}
		if(sb==-1){	
			puts("No");
			return 0;
		}
		x[i-1]=sa*ll(sa)-prev*prev;
		prev=sb;
	}

	puts("Yes");
	REP(i,n)cout<<x[i]<<' ';
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}