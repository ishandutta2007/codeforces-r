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
#include <complex>

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
#define Pi acos(-1.0)
#define y1 adsfasdgasg
#define x2 asdfagdsasdg
#define x1 twretwret
#define y2 oupoupoupo
#define eps 1e-10

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1024;
const int MAX2 = 7000;
const int BASE = 1000000007;
const int CNT = 300;
const int MOD = 1000000007;

string s[100007][2];

char buf[27];

int p[100007];

int main()
{
        #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        #endif

    //freopen("tetrahedron.in", "r", stdin);
    //freopen("tetrahedron.out", "w", stdout);

   int n;
   cin >> n;

    FOR(i,0,n)
    {
        cin >> s[i][0] >> s[i][1];
    }

    FOR(i,0,n)
    {
        int x;
        scanf("%d" , &x);
        --x;
        p[i] = x;
    }

    string m = "";


    FOR(i,0,n)
    {
        if (s[p[i]][0] < m && s[p[i]][1] < m)
        {
            cout << "NO\n";
            return 0;
        }
        if (s[p[i]][0] > s[p[i]][1])
        {
            swap(s[p[i]][0], s[p[i]][1]);
        }

        if (s[p[i]][0] > m)
        {
            m = s[p[i]][0];
        }
        else
        {
            m = s[p[i]][1];
        }
        //cout << m << endl;
    }

    cout << "YES\n";





    return 0;
}