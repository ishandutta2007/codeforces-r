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

struct graph {
  struct edge {
    static inline bool cost;  // dummy
    int src, dst;

    int operator-(int v) const {
      assert(v == src or v == dst);
      return src ^ dst ^ v;
    }
  };

  int n, m = 0;
  std::vector<edge> edges;
  std::vector<std::vector<std::pair<int, int>>> adj;
  std::function<bool(int)> ignore = [](int) { return false; };

  graph() : n(0) {}
  explicit graph(int _n) : n(_n), adj(n) {}

  int add(const edge& e, bool directed) {
    assert(0 <= e.src), assert(e.src < n);
    assert(0 <= e.dst), assert(e.dst < n);
    edges.push_back(e);
    adj[e.src].emplace_back(m, e.dst);
    if (not directed) adj[e.dst].emplace_back(m, e.src);
    return m++;
  }
};

struct dfs_forest : graph {
  using cost_t = decltype(edge::cost);

  std::vector<int> root, pv, pe, sz, depth, min_depth, last, order, in, out;
  std::vector<cost_t> dist;
  int trials;

  dfs_forest(int _n = 0) : graph(_n), dist(n), trials(0) {
    for (auto p : {&root, &pv, &pe, &sz, &depth, &min_depth, &last, &in, &out})
      p->assign(n, -1);
  }

  int add(const edge& e) { return graph::add(e, false); }
  void build(int r, bool clear_order = true) {
    assert(0 <= r), assert(r < n);
    root[r] = r, pv[r] = pe[r] = -1, depth[r] = 0, dist[r] = cost_t{};
    if (clear_order) order.clear();
    dfs(r);
    ++trials;
  }
  void build() {
    fill(begin(root), end(root), -1);
    for (int v = 0; v < n; ++v)
      if (root[v] == -1) build(v, v == 0);
  }
  int deeper(int id) const {
    assert(0 <= id), assert(id < m), assert(not ignore(id));
    int u = edges[id].src, v = edges[id].dst;
    return depth[u] < depth[v] ? v : u;
  }
  bool is_tree_edge(int id) const {
    assert(0 <= id), assert(id < m), assert(not ignore(id));
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs(int v) {
    sz[v] = 1, min_depth[v] = depth[v], last[v] = trials;
    in[v] = size(order), order.push_back(v);
    for (auto [id, u] : adj[v]) {
      if (ignore(id) or id == pe[v]) continue;
      if (last[u] == trials) {
        min_depth[v] = std::min(min_depth[v], depth[u]);
        continue;
      }
      root[u] = root[v], pv[u] = v, pe[u] = id, depth[u] = depth[v] + 1;
      dist[u] = dist[v] + edges[id].cost;
      dfs(u);
      sz[v] += sz[u], min_depth[v] = std::min(min_depth[v], min_depth[u]);
    }
    out[v] = size(order);
  }
};

template <class F>
struct y_combinator : private F {
  y_combinator(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    cout << "1 1\n";
    exit(0);
  }
  dfs_forest g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add({u, v});
  }
  g.build(0);
  vector<int> vs;
  y_combinator([&](auto&& self, int v) -> void {
    vs.push_back(v);
    for (auto [id, u] : g.adj[v]) {
      if (not g.is_tree_edge(id) or id == g.pe[v]) continue;
      self(u);
      vs.push_back(v);
    }
  })(0);
  vs.pop_back();
  assert(int(size(vs)) <= 2 * n);
  int sz = (2 * n + k - 1) / k;
  for (int i : rep(k)) {
    cout << sz;
    for (int j : rep(sz)) cout << ' ' << vs[(i * sz + j) % size(vs)] + 1;
    cout << '\n';
  }
}