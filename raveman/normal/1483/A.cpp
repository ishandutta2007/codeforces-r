//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
vi v[111111];
int c[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;
		REP(i,m){
			int x;
			scanf("%d",&x);
			v[i].resize(x);
			REP(j,x)scanf("%d",&v[i][j]),v[i][j]--;
		}
		REP(i,n)c[i]=0;
		REP(i,m){
			if(v[i].size()==1){
				c[v[i][0]]++;
			}
		}
		REP(i,m){
			if(v[i].size()>1){
				int c1 = c[v[i][0]];
				int c2 = c[v[i][1]];
				if(c1<c2){
					c[v[i][0]]++;
				}else{
					c[v[i][1]]++;
					swap(v[i][0],v[i][1]);
				}
			}
		}
		int g=1;
		REP(i,n)if(c[i]>(m+1)/2)g=0;
		if(g){
			puts("YES");
			REP(i,m)printf("%d ",v[i][0]+1);puts("");
		}else{
			puts("NO");
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}