#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,p,a,b,d;
vector<pii> v[1111];
vector<pii> inc[1111];
int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("dices.in","r",stdin);
	//freopen("dices.out","w",stdout);
#endif

	cin>>n>>p;
	REP(i,p){
		cin>>a>>b>>d;
		a--,b--;
		v[a].pb(pii(b,d));
		inc[b].pb(pii(a,d));
	}
	vector<pair<int,pii> > vv;
	REP(i,n) if(inc[i].size()==0 && v[i].size()>0){
		int curr = i;
		int res = 1000000000;
		while(v[curr].size())res = min(res, v[curr][0].second),curr = v[curr][0].first;
		vv.pb(make_pair(i,pii(curr,res)));
	}
	SORT(vv);
	cout<<vv.size()<<endl;
	REP(i,vv.size())
		cout<<vv[i].first+1<<' '<<vv[i].second.first+1<<' '<<vv[i].second.second<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}