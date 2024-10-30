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

int a[222222];
int n;
multiset<int> s;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i),s.insert(-(a[i]+i-(n-1)));
	vi v;
	REP(i,n){
		v.pb(-*s.begin());
		s.erase(s.begin());
		v.back()+=i;
		if(v.size()>=2 && v.back()>v[v.size()-2]){
			puts(":(");
			return 0;
		}
	}
	reverse(v.begin(),v.end());
	REP(i,v.size()){
		if(i)printf(" ");
		printf("%d",v[i]);
	}
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}