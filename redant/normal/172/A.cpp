/*AnilKishore*India*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 25

char s[MX], t[MX];

int get()
{
	int r = 0;
	for(;r<strlen(s) && s[r]==t[r];) r++;
	return r;
}

int main()
{
	int n = SI;
	scanf(" %s",s);
	int ans = strlen(s);
	while(--n){ scanf(" %s",t); ans=min(ans,get()); }
	printf("%d\n",ans);
	return 0;
}