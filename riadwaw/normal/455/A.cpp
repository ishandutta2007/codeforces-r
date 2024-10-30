//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

double dist(pi l, pi r);

#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0);
    cout.precision(20);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
#ifdef DEBUG
    cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}

#define int li


map<int, int> cnt;
map<int, li> res;

li dp(int v) {
    auto it = cnt.lower_bound(v);
    if(it == cnt.end()) {
        return 0;
    }
    v = it->first;
    if(res.count(v)) {
        return res[v];
    }
    res[v] = max(dp(v + 1), dp(v + 2) + it->second * v);
    return res[v];

}


void solve(){


    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }

    cout << dp(0);
}