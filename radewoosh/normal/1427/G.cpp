//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=207;
const ll inf=10;
 
int n;
ll tab[nax][nax];
 
int k;
vll wary;
 
ll wyn;
 
using T = int;
struct Flow {
  struct E {
	int dest;
	T orig, *lim, *rev;
  };
  int zr, uj, n = 0;
  vector<unique_ptr<T>> ts;
  vector<vector<E>> graf;
  vector<int> ptr, odl;
  vi bylo;
  void vert(int v) {
	n = max(n, v + 1);
	graf.resize(n);
	ptr.resize(n);
	odl.resize(n);
	bylo.resize(n);
  }
  bool iszero(T v) {
	return !v; // Zmieni dla doubli.
  }
  void bfs() {
	fill(odl.begin(), odl.end(), 0);
	vector<int> kol = {zr};
	odl[zr] = 1;
	for (int i = 0; i < (int) kol.size(); i++) {
	  for (E& e : graf[kol[i]]) {
		if (!odl[e.dest] and !iszero(*e.lim)) {
		  odl[e.dest] = odl[kol[i]] + 1;
		  kol.push_back(e.dest);
		}
	  }
	}
  }
  T dfs(int v, T lim) {
	if (v == uj) return lim;
	T ret = 0, wez;
	bylo[v]=1;
	for (int& i = ptr[v]; i < (int) graf[v].size(); i++) {
	  E& e = graf[v][i];
	  //~ if (odl[e.dest] == odl[v] + 1 and !iszero(*e.lim) and
	  if (!iszero(*e.lim) and !bylo[e.dest] and
		  !iszero(wez = dfs(e.dest, min(*e.lim, lim)))) {
		ret += wez;
		*e.lim -= wez;
		*e.rev += wez;
		lim -= wez;
		if (iszero(lim)) break;
	  }
	}
	return ret;
  }
  void add_edge(int u, int v, T lim, bool bi = false /* bidirectional? */) {
	vert(max(u, v));
	T *a = new T(lim), *b = new T(lim * bi);
	ts.emplace_back(a);
	ts.emplace_back(b);
	graf[u].push_back(E{v, lim,      a, b});
	graf[v].push_back(E{u, lim * bi, b, a});
  }
  T dinic(int zr_, int uj_) {
	zr = zr_; uj = uj_;
	vert(max(zr, uj));
	T ret = 0;
	while (true) {
	  //~ bfs();
	  fill(bylo.begin(), bylo.end(), 0);
	  fill(ptr.begin(), ptr.end(), 0);
	  const T sta = dfs(zr, numeric_limits<T>::max());  // Dla doubli mona da
	  if (iszero(sta)) break;                           // infinity() zamiast
	  ret += sta;                                       // max().
	}
	return ret;
  }
  vector<int> cut() {
	vector<int> ret;
	bfs();
	for (int i = 0; i < n; i++)
	  if (odl[i])
		ret.push_back(i);
	return ret;
  }
  map<pair<int, int>, T> get_flowing() {  // Tam gdzie plynie 0 moe nie by
	map<pair<int, int>, T> ret;           // krawdzi.
	for (int i = 0; i < n; i++)
	  for (E& e : graf[i])
		if (*e.lim < e.orig)
		  ret[make_pair(i, e.dest)] += e.orig - *e.lim;
	for (auto& i : ret) {
	  const pair<int, int> rev{i.first.second, i.first.first};
	  const T x = min(i.second, ret[rev]);
	  i.second -= x;
	  ret[rev] -= x;
	}
	return ret;
  }
};

Flow janusz;
 
int tonum(int a, int b)
{
	a--;
	b--;
	return a*n+b+1;
}
 
int tonum(pii v)
{
	return tonum(v.first, v.second);
}

int stary;

void unikra(int a, int b, ll w)
{
	if (!w)
		return;
	janusz.add_edge(a, b, w, 0);
}
 
void bikra(int a, int b, ll w)
{
	if (!w)
		return;
	janusz.add_edge(a, b, w, 1);
}

void solve(ll limit, ll zm)
{
	int teraz=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (tab[i][j]==limit-zm)
			{
				teraz++;
				unikra(tonum(i, j), n*n+1, 2*inf);
			}
		}
	}
	int wez=janusz.dinic(0, n*n+1);
	wez-=teraz*inf;
	//~ debug() << imie(limit) << imie(wez);
	stary+=wez;
	wyn+=stary*zm;
	//~ debug() << imie(limit) << imie(stary) << imie(teraz) << imie(zm);
}
 
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			scanf("%lld", &tab[i][j]);
			if (tab[i][j]>0)
				wary.push_back(tab[i][j]);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			int g=tonum(i, j);
			if (tab[i][j]==-1)
				continue;
			ll dol=0;
			ll gor=0;
			if (tab[i][j])
				dol=inf;
			unikra(0, g, dol);
			unikra(g, n*n+1, gor);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (i+1<=n && tab[i][j]>=0 && tab[i+1][j]>=0)
				bikra(tonum(i, j), tonum(i+1, j), 1);
			if (j+1<=n && tab[i][j]>=0 && tab[i][j+1]>=0)
				bikra(tonum(i, j), tonum(i, j+1), 1);
		}
	}
	sort(wary.begin(), wary.end());
	wary.resize(unique(wary.begin(), wary.end())-wary.begin());
	//~ debug() << imie(wary);
	k=wary.size();
	ll ost=wary[0];
	for (int i=1; i<k; i++)
	{
		solve(wary[i], wary[i]-ost);
		ost=wary[i];
	}
	printf("%lld\n", wyn);
	return 0;
}