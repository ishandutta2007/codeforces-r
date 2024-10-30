#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 2007;
const int MOD = 998244353;
const double Pi = acos(-1.);

int C[MAX][MAX];


int main()
{
    
    int n , m , k;
    cin >> n >> m >> k;

    FOR(i,0,MAX)
    {
        C[i][0] = C[i][i] = 1;
        FOR(j,1,i)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }

    Int res = C[n - 1][k];
    FOR(i,0,k)
    {
        res *= m - 1;
        res %= MOD;
    }
    res *= m;
    res %= MOD;


    cout << res << endl;
    return 0;
}