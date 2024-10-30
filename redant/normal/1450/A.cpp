#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;

string solve() {
    string r = "";
    for (char c : s) {
        if (c == 'b')
            r = c + r;
        else
            r = r + c;
    }
    return r; 
}

int main() {
    setIO();
    int t, n; cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}