#include <bits/stdc++.h>

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
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
  std::cin >> res;
  return res;
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto s = scan<string>();
  int n = size(s);
  vector suff(3, vector<int>(n + 1));
  for (int i : Per(n)) {
    suff[0][i] = (s[i] == 'x') + suff[0][i + 1];
    suff[1][i] = (s[i] == 'y') + suff[1][i + 1];
    suff[2][i] = (s[i] == 'z') + suff[2][i + 1];
  }
  for (int q = scan(); q--;) {
    int l = scan() - 1;
    int r = scan();
    int x = suff[0][l] - suff[0][r];
    int y = suff[1][l] - suff[1][r];
    int z = suff[2][l] - suff[2][r];
    auto [mn, mx] = minmax({x, y, z});
    cout << (r - l < 3 or mx - mn <= 1 ? "YES\n" : "NO\n");
  }
}