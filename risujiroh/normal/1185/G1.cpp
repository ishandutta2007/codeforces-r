#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  ModInt(auto x) : v(x >= 0 ? x % P : (P - -x % P) % P) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M r) const { return M(*this) *= r; }
  M operator/(M r) const { return M(*this) /= r; }
  M operator+(M r) const { return M(*this) += r; }
  M operator-(M r) const { return M(*this) -= r; }
  bool operator==(M r) const { return v == r.v; }
  bool operator!=(M r) const { return !(*this == r); }
  M& operator*=(M r) { v = (uint64_t) v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
  M inv() const {
    int a = v, b = P, x = 1, u = 0;
    while (b) {
      int q = a / b;
      swap(a -= q * b, b);
      swap(x -= q * u, u);
    }
    assert(a == 1);
    return x;
  }
  M pow(auto n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  friend M operator*(auto l, M r) { return M(l) *= r; }
  friend M operator/(auto l, M r) { return M(l) /= r; }
  friend M operator+(auto l, M r) { return M(l) += r; }
  friend M operator-(auto l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend istream& operator>>(istream& is, M& r) { lint x; is >> x; r = x; return is; }
  friend bool operator==(auto l, M r) { return M(l) == r; }
  friend bool operator!=(auto l, M r) { return !(l == r); }
};
using Mint = ModInt<(unsigned) 1e9 + 7>;
V<Mint> fact, ifact, inv, powB;
void init(int n, int B = 2) {
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = i * fact[i - 1];
  }
  ifact.resize(n + 1);
  ifact[n] = fact[n].inv();
  for (int i = n; i > 0; --i) {
    ifact[i - 1] = i * ifact[i];
  }
  inv.resize(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    int q = Mint::p() / i;
    inv[i] = -q * inv[Mint::p() - i * q];
  }
  powB.resize(n + 1);
  powB[0] = 1;
  for (int i = 0; i < n; ++i) {
    powB[i + 1] = powB[i] * B;
  }
}
Mint comb(int n, int r) {
  if (r < 0 or r > n) return 0;
  return fact[n] * ifact[r] * ifact[n - r];
}

Mint dp[16][16][16][3];

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  dp[1][0][0][0] = 1;
  dp[0][1][0][1] = 1;
  dp[0][0][1][2] = 1;
  for (int x = 0; x < 15; ++x) for (int y = 0; y < 15; ++y) for (int z = 0; z < 15; ++z) {
    dp[x][y + 1][z][1] += dp[x][y][z][0];
    dp[x][y][z + 1][2] += dp[x][y][z][0];
    dp[x + 1][y][z][0] += dp[x][y][z][1];
    dp[x][y][z + 1][2] += dp[x][y][z][1];
    dp[x + 1][y][z][0] += dp[x][y][z][2];
    dp[x][y + 1][z][1] += dp[x][y][z][2];
  }
  int n, T; cin >> n >> T;
  V<> t(n), g(n); for (int i = 0; i < n; ++i) cin >> t[i] >> g[i];
  init(15);
  Mint res;
  for (int bit = 0; bit < 1 << n; ++bit) {
    int s = 0, x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) if (bit >> i & 1) {
      s += t[i];
      x += g[i] == 1;
      y += g[i] == 2;
      z += g[i] == 3;
    }
    if (s != T) continue;
    Mint curr;
    curr += dp[x][y][z][0];
    curr += dp[x][y][z][1];
    curr += dp[x][y][z][2];
    curr *= fact[x] * fact[y] * fact[z];
    res += curr;
  }
  cout << res << '\n';
}