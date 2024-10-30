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
const ll mod=998244353;

int n;

pll tun[nax];
int stan[nax];

pll tab[nax];
ll przez[nax];

ll dp[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld%d", &tun[i].second, &tun[i].first, &stan[i]);
		tab[2*i-1]={tun[i].first, i};
		tab[2*i]={tun[i].second, -i};
	}
	sort(tab+1, tab+1+2*n);
	dp[2*n]=1;
	tab[2*n+1].first=tab[2*n].first+1;
	for (int i=2*n; i; i--)
	{
		int x=abs(tab[i].second);
		if (tab[i].second<0)//wyjscie
		{
			przez[x]=(dp[i]-1+stan[x]+mod)%mod;
			dp[i-1]=dp[i]+przez[x];
		}
		else//wejscie
		{
			dp[i-1]=(dp[i]-przez[x]+mod)%mod;
		}
		dp[i-1]%=mod;
		dp[i-1]+=mod;
		dp[i-1]%=mod;
	}
	//~ debug() << range(dp, dp+1+2*n);
	ll wyn=0;
	for (int i=0; i<=2*n; i++)
		wyn=(wyn+dp[i]*(tab[i+1].first-tab[i].first))%mod;
	printf("%lld\n", wyn);
	return 0;
}