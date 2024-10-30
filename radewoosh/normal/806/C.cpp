//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=100*1007;
const int dax=45;

int n;

int ilep[nax];
int ilenor[nax];

int wyn;

vector <int> moge;

int ter;

void dodaj(long long v)
{
	if (__builtin_popcountll(v)==1)
	{
		for (int i=0; 1; i++)
		{
			if ((1LL<<i)==v)
			{
				ilep[i]++;
				debug() << "p " << i;
				return;
			}
		}
		return;
	}
	for (int i=0; 1; i++)
	{
		if ((1LL<<i)>v)
		{
			debug() << "nor " << i;
			ilenor[i-1]++;
			return;
		}
	}
}

void wypisz()
{
	if (moge.empty())
	{
		printf("-1\n");
		exit(0);
	}
	sort(moge.begin(), moge.end());
	for (int i=0; i<moge.size(); i++)
		printf("%d ", moge[i]);
	printf("\n");
	exit(0);
}

int dys[nax];
int mam[nax];

int smiec[nax];

void check(int v)
{
	int vv=v;
	for (int i=0; i<=dax; i++)
		mam[i]=smiec[i]=0;
	for (int i=0; i<=dax; i++)
		dys[i]=ilep[i];
	for (int i=dax; i>=0; i--)
	{
		int x=min(v, dys[i]);
		v-=x;
		dys[i]-=x;
		mam[i]+=x;
		for (int j=0; j<=i; j++)
			smiec[j]+=dys[i];
		smiec[i]+=ilenor[i];
	}
	if (v)
		return;
	for (int i=0; i<dax; i++)
	{
		int x=min(mam[i], smiec[i]);
		mam[i]-=x;
		smiec[i]-=x;
		smiec[i+1]+=smiec[i];
	}
	if (!smiec[dax])
		moge.push_back(vv);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		long long x;
		scanf("%lld", &x);
		dodaj(x);
	}
	
	for (int i=0; i<=dax; i++)
	{
		while (ilep[i]<ilep[i+1])
		{
			ilep[i+1]--;
			ilenor[i]++;
		}
	}
	
	for (int i=0; i<=dax; i++)
		ilep[i]-=ilep[i+1];
	
	for (int i=1; i<=n; i++)
		check(i);
	
	wypisz();
	
	return 0;
}