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

const int MOD = 31607;

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

const int N = 23;

int n;
mi a[N][N];
mi tot[1 << N];
mi s[1 << N];
int lb[1 << N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) rep(j, 0, n) {
        int x;
        cin >> x;
        a[i][j] = mi(x) / 10000;
    }

    rep(i, 1, 1 << N) while(!(i >> lb[i] & 1)) lb[i]++;

    fill(tot, tot + (1 << (n + 2)), 1);

    rep(i, 0, n) {
        s[0] = 1;
        rep(j, 1, 1 << n) {
            int b = lb[j];
            s[j] = s[j ^ (1 << b)] * a[i][b];
        }
        mi c = s[(1 << n) - 1];
        rep(j, 0, 1 << n) s[j] -= c;
        rep(j, 0, 1 << (n + 2)) {
            int mask = j & ((1 << n) - 1);
            if(j >> n & 1) mask |= (1 << i);
            if(j >> (n + 1) & 1) mask |= (1 << (n - 1 - i));
            tot[j]  *= s[mask];
        }
    }
    rep(i, 0, (n + 2)) {
        rep(mask, 0, (1 << (n + 2))) {
            if(mask >> i & 1) tot[mask ^ (1 << i)] -= tot[mask];
        }
    }
    cout << int(1 - tot[0]) << endl;


}