#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
int a[MX];
int n, m, k, x, y;

int solve() {
    int mnOP = MX, mxON = -MX;
    int sum = 0;
    TRAV(x, a) {
        if (x > 0) {
            sum += x;
            if (x & 1)
                tmin(mnOP, x);
        } else if (x < 0) {
            if ((-x)&1)
                tmax(mxON, x);
        }
    }

    if (sum & 1)
        return sum;

    int r = -MX;
    if (sum - mnOP > 0)
        tmax(r, sum - mnOP);
    if (mxON > -MX)
        tmax(r, sum + mxON);

    return r;
}

int main() {
    setIO();
    int t=1; // ; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}