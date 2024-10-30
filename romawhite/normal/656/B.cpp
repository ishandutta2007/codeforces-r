#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 2000000;
const int BASE = 10;
const int ST = 1000000007;
const int CNT = 100;

const int MOD = 1000000007;

int M[17];
int R[17];

int main()
{
	//freopen("out.txt" , "w" , stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);

	int n;
	cin >> n;
	FOR(i,0,n)
	{
		cin >> M[i];
	}
	FOR(i,0,n)
	{
		cin >> R[i];
	}

	int X = 16 * 9 * 5 * 7 * 11 * 13;
	int p = 0;
	FOR(i,0,X)
	{
		bool ok = 0;
		FOR(j,0,n)
			if (i % M[j] == R[j]) ok = 1;
		p += ok;
	}

	printf("%.10f\n" , 1.0 * p / X);

	return 0;
}