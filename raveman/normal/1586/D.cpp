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

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int r[111];


int main(){	
#ifdef LocalHost
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	int num=0;
	for(int i=2;i<=n;i++){
		cout<<"?";
		for(int j=2;j<=n;j++){
			cout<<" "<<i;
		}
		puts(" 1");
		cout.flush();
		int k;
		cin>>k;
		if(k!=0)num++;
	}
	CL(r,-1);
	r[n-1]=num+1;

	for(int i=1;i<=num;i++){
		cout<<"?";
		REP(j,n-1){
			cout<<" "<<num+1-i+1;
		}
		cout<<" "<<1;
		puts("");
		cout.flush();
		int k;
		cin>>k;
		r[k-1]=i;
	}

	for(int i=num+2;i<=n;i++){
		cout<<"?";
		REP(j,n-1){
			cout<<" "<<1;
		}
		cout<<" "<<i-num;
		puts("");
		cout.flush();
		int k;
		cin>>k;
		r[k-1]=i;
	}

	cout<<"!";
	REP(i,n)cout<<" "<<r[i];
	puts("");
	cout.flush();


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}