#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;


int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    cin >> n;
    vector<pair<int,int> > a;
    FOR(i,0,n)
    {
        int x;
        cin >> x;
        a.push_back(MP(x + i, i));
    }

    sort(ALL(a));

    FOR(i,0,n)
    {
        a[i].first -= i;
    }

    bool ok = 1;
    FOR(i,0,n - 1)
    {
        if (a[i].first > a[i + 1].first)
        {
            ok = 0;
        }
    }

    /*FOR(i,0,n)
    {
        if (a[i].first < 0)
        {
            ok = 0;
        }
    }*/

    if (!ok)
    {
        cout << ":(" << endl;
        return 0;
    }

    FOR(i,0,n)
    {
        cout << a[i].first << ' ';
    }
    cout << endl;

    return 0;
}