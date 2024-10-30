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


const int MOD = (int)1e9 + 7;

struct mi {
    typedef decay<decltype(MOD)>::type T;
    /// don't silently convert to T
    T v; explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) {
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) {
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) {
        return a.v < b.v; }
//    friend void re(mi& a) { ll x; re(x); a = mi(x); }
//    friend str ts(mi a) { return ts(a.v); }

    mi& operator+=(const mi& m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this; }
    mi& operator*=(const mi& m) {
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0);
        return pow(a,MOD-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

const int N = (int)3e6 + 50;
mi fac[N], facinv[N];

mi C(int n, int k) {
    if(n < k) return 0;
    return fac[n] * facinv[n - k] * facinv[k];
}

int n, q;

mi dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);


    cin >> n;
    dp[0] = n;
    rep(i, 1, 4) {
        for (int x = i / 3 * 3; x <= 3 * n; x += 3) {
            dp[i] += C(x, i);
        }
//        cout << i << " " << int(dp[i]) << endl;

    }
    mi inv3 = inv(mi(3));
    rep(i, 5, 3 * n + 2) {

//        dp[i] = 3 * (dp[i - 1] - C(3 * n, i - 1));
//        if(i >= 2) dp[i] += 3 * (dp[i - 2] - C(3 * n, i - 2));
//        if(i >= 3) dp[i] += (dp[i - 3] - C(3 * n, i - 3));


//         = 3 * (dp[i - 1] - C(3 * n, i - 1));
        mi rs = C(3 * n, i) - (dp[i - 3] - C(3 * n, i - 3));
//        cout << (int)rs << endl;
        rs -= 3 * (dp[i - 2] - C(3 * n, i - 2));
//        cout << (int)rs << endl;
        rs = (rs * inv3 + C(3 * n, i - 1));
//        cout <<(int) rs << endl;
//
        dp[i - 1] = rs;
//        cout << i - 1 << ": " << int(dp[i - 1]) << endl;
    }
    cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << int(dp[x]) << '\n';
    }

}