#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(), (x).end()

template <typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const unordered_set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...)                                                                   \
    cerr << " ";                                                                     \
    cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                     \
    debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

template <class T1, class T2> inline bool chmin(T1& a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2> inline bool chmax(T1& a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

/**
 * @brief Binary Indexed Tree
 * @docs docs/datastructure/BinaryIndexedTree.md
 */
template <typename T> class BinaryIndexedTree {
    T sum(int i) {
        T res = T();
        for (; i > 0; i -= (i & -i)) res += dat[i];
        return res;
    }

public:
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n_) : n(n_ + 1), dat(n + 1, 0) {}
    void add(int i, const T& x) {
        for (++i; i <= n; i += (i & -i)) dat[i] += x;
    }
    T query(int l, int r) { return sum(r) - sum(l); }
    int lower_bound(T x) const {
        if (x <= 0) return 0;
        int pos = 0, k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (pos + k <= n && dat[pos + k] < x) {
                x -= dat[pos + k];
                pos += k;
            }
        }
        return pos;
    }
    int upper_bound(T x) const { return lower_bound(x + 1); }
    T operator[](int i) { return query(i, i + 1); }
};

/**
 * @brief compress
 */
template <typename T> map<T, int> compress(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<T, int> res;
    for (int i = 0; i < (int)v.size(); i++) res[v[i]] = i;
    return res;
}

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    cin >> a;

    vector<int> comp = a;
    map<int, int> mp = compress(comp);
    for (int& x : a) x = mp[x];
    int sz = mp.size();
    vector<int> b = a;
    sort(ALL(b));

    vector<pair<int, int>> seat;
    for (int i = 0; i < n * m; i++) seat.emplace_back(a[i], i);
    sort(ALL(seat));
    vector<int> idx;

    for (int j = 0, cur = 0; j < sz; j++) {
        int Min = cur;
        while (cur < n * m && b[cur] == j) cur++;
        int Max = cur - 1;
        // debug(j, Min, Max, cur);
        if (Min / m == Max / m) {
            for (int i = Max; i >= Min; i--) idx.emplace_back(i);
            continue;
        }
        {
            int x = Min / m, y = Min % m;
            for (int i = m - 1; i >= y; i--) idx.emplace_back(x * m + i);
        }
        {
            for (int i = Min / m + 1; i < Max / m; i++) {
                for (int k = m - 1; k >= 0; k--) {
                    idx.emplace_back(i * m + k);
                }
            }
        }
        {
            int x = Max / m, y = Max % m;
            for (int i = y; i >= 0; i--) idx.emplace_back(x * m + i);
        }
    }
    // debug(idx);

    vector<int> pos(n * m);
    for (int i = 0; i < n * m; i++) pos[seat[i].second] = idx[i];

    vector<BinaryIndexedTree<int>> BIT(n, BinaryIndexedTree<int>(m));
    ll ans = 0;
    for (int i = 0; i < n * m; i++) {
        int x = pos[i] / m, y = pos[i] % m;
        ans += BIT[x].query(0, y);
        BIT[x].add(y, 1);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}