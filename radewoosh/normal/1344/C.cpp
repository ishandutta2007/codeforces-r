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
const int nax=1000*1007;

int n, m;

vi graf[nax];
vi farg[nax];

int bylo[nax];
int czas;
int post[nax];
int kt[nax];

void nope()
{
	printf("-1\n");
	exit(0);
}

void dfs1(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (int i : graf[v])
		dfs1(i);
	czas++;
	post[czas]=v;
	kt[v]=czas;
}

int prz[nax];
int tyl[nax];

void dfsprz(int v)
{
	if (prz[v])
		return;
	prz[v]=1;
	for (int i : graf[v])
		dfsprz(i);
}

void dfstyl(int v)
{
	if (tyl[v])
		return;
	tyl[v]=1;
	for (int i : farg[v])
		dfstyl(i);
}

int wyn;
char co[nax];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		farg[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		dfs1(i);
	for (int i=1; i<=n; i++)
		for (int j : graf[i])
			if (kt[j]>kt[i])
				nope();
	for (int i=1; i<=n; i++)
	{
		if (!prz[i] && !tyl[i])
		{
			co[i]='A';
			wyn++;
		}
		else
		{
			co[i]='E';
		}
		dfsprz(i);
		dfstyl(i);
	}
	printf("%d\n", wyn);
	for (int i=1; i<=n; i++)
		printf("%c", co[i]);
	printf("\n");
	return 0;
}