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
const ll inf=1007LL*1007LL*1007LL*1007LL*1007LL*1007LL;

int n;
ll k;

ll dp[nax];

void test()
{
	scanf("%d%lld", &n, &k);
	if (dp[n]<k)
	{
		printf("-1\n");
		return;
	}
	vi wyn;
	int w=0;
	while(w<n)
	{
		for (int i=1; w+i<=n; i++)
		{
			if (dp[n-w-i]>=k)
			{
				//~ debug() << w << " " << i << " " << n-w-i << " " << dp[n-w-i];
				for (int j=i; j; j--)
					wyn.push_back(w+j);
				w+=i;
				break;
			}
			k-=dp[n-w-i];
		}
	}
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
}

int main()
{
	dp[0]=1;
	for (int i=1; i<nax; i++)
	{
		for (int j=1; j<=i && dp[i]<inf; j++)
		{
			dp[i]=min(inf, dp[i]+dp[i-j]);
		}
		//~ if (i<=10)
			//~ debug() << i << " " << dp[i];
	}
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}