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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n, m;

ll lim;
ll tab[nax];

int oj[nax];

int wyn=0;

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	a=fin(a);
	b=fin(b);
	if (a!=b)
	{
		debug() << a << " " << b;
		wyn--;
		oj[a]=b;
	}
}

void dod(int v, ll x)
{
	if (tab[v]<=lim && tab[v]+x>lim)
	{
		wyn++;
		//~ debug() << v << " " << tab[v-1] <<  " " << tab[v+1] << " " << tab[v];
		if (tab[v-1]>lim)
			uni(v-1, v);
		if (tab[v+1]>lim)
			uni(v+1, v);
	}
	tab[v]+=x;
}

int main()
{
	scanf("%d%d%lld", &n, &m, &lim);
	for (int i=1; i<=n; i++)
		oj[i]=i;
	
	for (int i=1; i<=n; i++)
	{
		ll x;
		scanf("%lld", &x);
		dod(i, x);
	}
	while(m--)
	{
		int typ;
		scanf("%d", &typ);
		if (!typ)
		{
			printf("%d\n", wyn);
		}
		else
		{
			ll a, b;
			scanf("%lld%lld", &a, &b);
			dod(a, b);
		}
	}
	
	return 0;
}