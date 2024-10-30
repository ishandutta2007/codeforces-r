//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const int nax=207;
using pii=pair<int,int>;

void ans(int res)
{
	printf("%d\n", res);
	exit(0);
}

int n, m;
pii tabn[nax];
pii tabm[nax];

int prze(pii v, pii u)
{
	int ret=0;
	ret+=(v.first==u.first);
	ret+=(v.first==u.second);
	ret+=(v.second==u.first);
	ret+=(v.second==u.second);
	return ret;
}

int com(pii v, pii u)
{
	if (v.first==u.first)
		return v.first;
	if (v.first==u.second)
		return v.first;
	return v.second;
}

set <int> ile;

set <int> setel[nax];

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &tabn[i].first, &tabn[i].second);
	for (int i=1; i<=m; i++)
		scanf("%d%d", &tabm[i].first, &tabm[i].second);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (prze(tabn[i], tabm[j])==1)
			{
				int x=com(tabn[i], tabm[j]);
				ile.insert(x);
				setel[i].insert(x);
				setel[n+j].insert(x);
			}
		}
	}
	if ((int)ile.size()==1)
		ans(*ile.begin());
	for (int i=1; i<=n+m; i++)
		if ((int)setel[i].size()>1)
			ans(-1);
	ans(0);
	return 0;
}