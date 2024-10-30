#include <bits/stdc++.h>

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  return std::cin >> res, res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

using Real = double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan(), m = scan();
  vector<Real> dp(m + 1);
  dp[0] = 1;
  Real ans = 0;
  while (n--) {
    Real p = scan();
    p /= 100;
    p = 1 - p;
    int t = scan();
    for (int i : Rep(m)) dp[i + 1] += dp[i] * p;
    auto pt = pow(p, t);
    vector<Real> ndp(m + 1);
    for (int i : Rep(m)) {
      ndp[i + 1] += dp[i] * (1 - p);
      if (i + t <= m) ndp[i + t] += dp[i] * pt;
      if (i + t + 1 <= m) ndp[i + t + 1] -= dp[i] * pt;
    }
    dp = move(ndp);
    ans += accumulate(ALL(dp), Real{});
  }
  cout << ans << '\n';
}