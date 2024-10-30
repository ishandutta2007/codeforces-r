#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  static constexpr unsigned mod = M;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

using mint = modular<power(10, 9) + 7>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? fact[i - 1] * i : 1;
  inv_fact[n] = power(fact[n], mint::mod - 2);
  for (int i = n; i--; ) inv_fact[i] = (i + 1) * inv_fact[i + 1];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template <> mint& mint::operator/=(mint b) {
  return *this *= b.v < minv.size() ? minv[b.v] : power(b, mod - 2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  prepare(2 * n);
  mint res;
  if (n % 4 == 1) {
    for (int i = 0; i < n; i += 2) {
      res += a[i] * binom(n / 2, i / 2);
    }
  } else if (n % 4 == 2) {
    for (int i = 0; i < n; ++i) {
      res += a[i] * binom(n / 2 - 1, i / 2);
    }
  } else if (n % 4 == 3) {
    for (int i = 1; i < n; i += 2) {
      res += a[i] * binom(n / 2 - 1, i / 2) * 2;
    }
    for (int i = 0; i <= n / 4; ++i) {
      int m = n / 4 * 2;
      auto c = binom(m, i) * (m - 2 * i + 1) / (m - i + 1);
      res += (a[2 * i] - a[n - 2 * i - 1]) * c;
    }
  } else {
    for (int i = 0; i < n; i += 2) {
      res += (a[i] - a[i + 1]) * binom(n / 2 - 1, i / 2);
    }
  }
  cout << res.v << '\n';
}