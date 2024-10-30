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
  for (int tt = scan(); tt--;) {
    int n = scan();
    int m = scan();
    vector b(n, vector<int>(m));
    vector<tuple<int, int, int>> v;
    for (int i : Rep(n)) {
      generate(ALL(b[i]), scan<>);
      for (int j : Rep(m)) v.emplace_back(b[i][j], i, j);
    }
    sort(ALL(v));
    vector f(n, vector<bool>(m));
    for (int z : Rep(m)) {
      auto [val, i, j] = v[z];
      f[i][j] = true;
    }
    int sum = 0;
    for (int i : Rep(n)) {
      int c = 0;
      for (int j : Rep(m))
        if (f[i][j]) swap(b[i][c++], b[i][j]);
      if (sum < m) rotate(begin(b[i]), end(b[i]) - sum, end(b[i]));
      for (int j : Rep(m)) cout << b[i][j] << " \n"[j + 1 == m];
      sum += c;
    }
  }
}