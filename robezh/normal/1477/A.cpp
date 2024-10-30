#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
ll k;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        rep(i, 0, n) cin >> a[i];
        k -= a[0];
        ll g = 0;
        rep(i, 1, n) {
            g = __gcd(g, abs(a[i] - a[i - 1]));
        }
        cout << (k % g == 0 ? "YES" : "NO") << '\n';
    }

}