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
#include <time.h>
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
#define Pi 3.14159265358979
#define y1 adsfadsfadfs

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 15000000;

int a[MAX];
int b[MAX];


int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    int n , m, k;
    cin >> n >> m >> k;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
        --a[i];
        b[a[i]] = i;
    }
    Int res = 0;
    FOR(i,0,m)
    {
        int x;
        scanf("%d" , &x);
        --x;
        int ind = b[x];
        res += ind / k + 1;
        if (ind)
        {
            int prev = a[ind - 1];
            swap(a[ind - 1] , a[ind]);
            b[prev]++;
            b[x]--;
        }
    }
    cout << res << endl;
    return 0;
}