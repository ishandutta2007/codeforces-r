#include <bits/stdc++.h>
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
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
int n, m;
int a[SZ], l[SZ];

void solve() {
    VI b;
    REP(i, n) {
        if (l[i] == 0)
            b.PB(a[i]);
    }
    sort(ALL(b));
    int p = SZ(b)-1;
    REP(i, n) {
        if (l[i] == 0)
            a[i] = b[p--];
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        REP(i, n) {
            cin>>l[i];
        }
        
        solve();
        REP(i, n) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}