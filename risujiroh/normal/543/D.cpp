#include <bits/stdc++.h>
using namespace std;

template <class T> struct tree {
  struct edge {
    int u, v;
    T w;
  };
  const int n;
  vector<edge> es;
  vector<vector<int>> g;
  vector<int> pv, pe, sz, dep, vs, in, out, head;
  vector<T> dist;
  tree(int _n = 0) : n(_n), g(n) {}
  void add(int u, int v, T w = 1) {
    g[u].push_back(es.size()), g[v].push_back(es.size());
    es.push_back({u, v, w});
  }
  int other(int id, int v) const { return es[id].u ^ es[id].v ^ v; }
  void dfs(int v) {
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = other(id, v);
      assert(pv[to] == -1);
      pv[to] = v, pe[to] = id;
      dep[to] = dep[v] + 1, dist[to] = dist[v] + es[id].w;
      dfs(to);
      sz[v] += sz[to];
    }
    sort(begin(g[v]), end(g[v]), [&](int a, int b) {
      return sz[other(a, v)] * (a != pe[v]) > sz[other(b, v)] * (b != pe[v]);
    });
  }
  void build(int r = 0) {
    assert((int)es.size() == n - 1);
    pv.assign(n, -1), pe.resize(n), sz.resize(n), dep.resize(n), dist.resize(n);
    pe[r] = -1, dep[r] = 0, dist[r] = 0;
    dfs(r);
  }
  void dfs_hld(int v) {
    in[v] = vs.size(), vs.push_back(v);
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = other(id, v);
      head[to] = to == other(g[v][0], v) ? head[v] : to;
      dfs_hld(to);
    }
    out[v] = vs.size();
  }
  void build_hld(int r = 0) {
    build(r);
    vs.clear(), in.resize(n), out.resize(n), head.resize(n);
    head[r] = r;
    dfs_hld(r);
  }
  bool anc(int u, int v) const { return in[u] <= in[v] and out[v] <= out[u]; }
  int lca(int u, int v) const {
    while (true) {
      if (in[u] > in[v]) swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
  T len(int u, int v) const { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
  int la(int v, int d) const {
    assert(0 <= d and d <= dep[v]);
    while (dep[head[v]] > d) v = pv[head[v]];
    return vs[in[head[v]] + (d - dep[head[v]])];
  }
  int next(int from, int to) const {
    assert(from != to);
    if (not anc(from, to)) return pv[from];
    return la(to, dep[from] + 1);
  }
  vector<pair<int, int>> ascend(int from, int to) const {
    vector<pair<int, int>> res;
    while (head[from] != head[to]) {
      res.emplace_back(in[from], in[head[from]]);
      from = pv[head[from]];
    }
    if (from != to) res.emplace_back(in[from], in[to] + 1);
    return res;
  }
  vector<pair<int, int>> descend(int from, int to) const {
    if (from == to) return {};
    if (head[from] == head[to]) return {{in[from] + 1, in[to]}};
    auto res = descend(from, pv[head[to]]);
    res.emplace_back(in[head[to]], in[to]);
    return res;
  }
  template <class F> void run(int from, int to, F f, bool vertex = true) const {
    int v = lca(from, to);
    for (auto e : ascend(from, v)) f(e.first + 1, e.second);
    if (vertex) f(in[v], in[v] + 1);
    for (auto e : descend(v, to)) f(e.first, e.second + 1);
  }
  template <class Node> vector<Node> dp(int r = 0) {
    build_hld(r);
    vector<Node> lower(n - 1), upper(n - 1), res(n);
    vector<vector<Node>> cum(n);
    for (int t = n; t--; ) {
      int v = vs[t], m = g[v].size() - (v != r);
      cum[v].resize(m + 1);
      for (int i = m; i--; ) cum[v][i] = lower[g[v][i]] + cum[v][i + 1];
      if (v != r) lower[pe[v]] = cum[v][0].add(v, pe[v]);
    }
    for (int v : vs) {
      Node cur = v != r ? upper[pe[v]] : Node();
      for (int i = 0, m = cum[v].size() - 1; i < m; ++i) {
        upper[g[v][i]] = (cur + cum[v][i + 1]).add(v, g[v][i]);
        cur = cur + lower[g[v][i]];
      }
      res[v] = cur.add(v);
    }
    return res;
  }
};

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % M; return *this; }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  tree<int> g(n);
  for (int v = 1; v < n; ++v) {
    int p;
    cin >> p;
    --p;
    g.add(v, p);
  }
  struct node {
    mint dp = 1;
    node operator+(node b) const {
      return {dp * b.dp};
    }
    node add(int v, int id = -1) const {
      return {dp + 1};
    }
  };
  auto res = g.dp<node>();
  for (int v = 0; v < n; ++v) {
    res[v].dp -= 1;
    cout << res[v].dp.v << " \n"[v == n - 1];
  }
}