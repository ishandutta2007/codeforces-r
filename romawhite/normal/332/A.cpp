#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef long double LD;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/
    //freopen("out.txt" , "w" , stdout); 
    
    int n;
    string s;
    cin >> n >> s;

    int c = 0;
    FOR(i,0,s.size())
        if (i % n == 0 && i >= 3 && s[i - 1] == s[i - 2] && s[i - 1] == s[i - 3])
            ++c;
    cout << c << endl;

    return 0;
}