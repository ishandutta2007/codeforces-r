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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int p[111111];

int main(){	
#ifdef LocalHost
	//	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		FOR(i,1,n+1)p[i]=-1;
		FOR(i,1,n+1)if(p[i]==-1){
			vi v;
			while(1){
				cout<<"? "<<i<<endl;
				cout.flush();
				int x;
				cin>>x;
				if(!v.empty() && v[0]==x)break;
				v.pb(x);
			}
			REP(j,v.size())if(v[j]==i){
				int prev=i;
				REP(k,v.size()){
					int c = v[(j+1+k)%v.size()];
					p[prev]=c;
					prev=c;
				}
				break;
			}
		}
		cout<<"!";
		FOR(i,1,n+1)printf(" %d", p[i]);
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}