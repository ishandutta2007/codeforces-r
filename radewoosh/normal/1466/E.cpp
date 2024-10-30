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
const int d=60;
const ll mod=1000*1000*1000+7;

int n;

ll tab[nax];

ll p2[d*3+7];
int ile[d];
int ile2[d][d];

ll wyn;

bool tak[d];

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	wyn=0;
	memset(ile, 0, sizeof(ile));
	memset(ile2, 0, sizeof(ile2));
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<d; j++)
		{
			if (tab[i]&(1LL<<j))
				tak[j]=1;
			else
				tak[j]=0;
		}
		for (int j=0; j<d; j++)
		{
			if (tak[j])
			{
				ile[j]++;
				ile2[j][j]++;
				for (int l=0; l<j; l++)
					if (tak[l])
						ile2[j][l]++;
			}
		}
	}
	for (int i=0; i<d; i++)
		for (int j=0; j<i; j++)
			ile2[j][i]=ile2[i][j];
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<d; j++)
		{
			ll mno=p2[i+j];
			ll li=0;
			li+=ile[i]*(ll)ile2[i][j]*(ll)n;
			li%=mod;
			li+=ile[i]*(ll)(ile[i]-ile2[i][j])*(ll)ile[j];
			li%=mod;
			wyn=(wyn+mno*li)%mod;
		}
	}
	printf("%lld\n", wyn);
}

int main()
{
	p2[0]=1;
	for (int i=1; i<=d*3; i++)
		p2[i]=(p2[i-1]*2)%mod;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}