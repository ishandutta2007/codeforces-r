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

int n;
int a[333333];
int c[333333];
int now;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)scanf("%d",a+i);
		REP(i,n+1)c[i]=0;
		bool s=0;
		REP(i,n){
			c[a[i]]++;
			if(c[a[i]]>1)s=1;
		}
		if(s)printf("0");
		else printf("1");

		int cc = 1;
		int from = 0;
		int to = n-1;
		REP(i,n){
			if(c[cc-1]>1)break;
			if(a[from]==cc){
				from++;
				cc++;
			}else if(a[to]==cc){
				to--;
				cc++;
			}else{
				if(from<=to){
					int w = a[from];
					FOR(j,from,to+1)w=min(w,a[j]);
					if(w==cc)cc++;
				}
				break;
			}
		}
		cc--;
		//cout<<"!"<<from<<' '<<to<<' '<<c<<endl;
		FOR(i,1,n){
			if(i+cc>=n)printf("1");
			else printf("0");
		}

		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}