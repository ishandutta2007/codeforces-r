#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e6 + 5;
const int MOD = (int)1e9 + 7;

int dp[N][2], sdp[N][2];
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

mi fac[N], facinv[N];


mi C(int n, int k) {
    if(k < 0 || n < k) return 0;
    return fac[n] * facinv[k] * facinv[n - k];
}

mi place_empty(int a, int e) {
    if(e == 0) return 1;
    return C(a - 1, e - 1) + C(a, e);
}

int n;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);
    assert(fac[0] * facinv[0] == 1);

    cin >> n;
    mi res;
    for (int i = 0; i <= n; i += 2) {
        int rem = n - i;
        if(i < rem) continue;
        res += place_empty(i, rem) * 2 * fac[i];
    }
    cout << int(res) << endl;

}