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
const ll inf=1e18;

void ff()
{
	fflush(stdout);
}

int n, k;

void test()
{
	scanf("%d", &n);
	ll lew=inf;
	ll pra=-inf;
	ll kl=inf;
	ll kp=inf;
	ll kw=inf;
	for (int i=1; i<=n; i++)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a<lew)
		{
			lew=a;
			kl=inf;
			kw=inf;
		}
		if (b>pra)
		{
			pra=b;
			kp=inf;
			kw=inf;
		}
		if (a==lew)
			kl=min(kl, c);
		if (b==pra)
			kp=min(kp, c);
		if (a==lew && b==pra)
			kw=min(kw, c);
		printf("%lld\n", min(kl+kp, kw));
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}