#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<ll> a(n), b(n);
        rep(i, n) {
            cin >> a[i];
            b[(i + a[i] % n + n) % n]++;
        }
        int f = 0;
        rep(i, n)
            if (b[i] > 1)
                f = 1;
        if (f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}