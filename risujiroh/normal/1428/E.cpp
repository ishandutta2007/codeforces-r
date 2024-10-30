// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  int64_t ans{};
  for (auto&& e : a) {
    cin >> e;
    ans += e * e;
  }

  auto f = [&](int i, int m) -> int64_t {
    assert(m <= a[i]);
    auto q = a[i] / m, r = a[i] % m;
    return q * q * (m - r) + (q + 1) * (q + 1) * r;
  };

  priority_queue<tuple<int64_t, int, int>> pq;
  auto go = [&](int i, int m) -> void {
    if (m >= a[i]) return;
    pq.emplace(f(i, m) - f(i, m + 1), i, m);
  };

  for (int i : rep(n)) go(i, 1);

  for (int _ = k - n; _--;) {
    auto [diff, i, m] = pq.top();
    pq.pop();
    ans -= diff;
    go(i, m + 1);
  }
  cout << ans << '\n';
}