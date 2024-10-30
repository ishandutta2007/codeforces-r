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

#define REP(i,n) for(int i = 0; i < int(n); ++i)
typedef double ld; // 'long double' is 2.2 times slower
struct C { ld re, im;
	C operator * (const C & he) const {
		return C{re * he.re - im * he.im,
				re * he.im + im * he.re};
	}
	void operator += (const C & he) { re += he.re; im += he.im; }
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].re, om[k].im * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.re - y.re, x.im - y.im};
			}
	}
	if(rev) REP(i, n) a[i].re /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
		bool split = true, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { // [0,B] into [-B/2, B/2]
		assert(a.size() == b.size()); // equal size!!!
		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	/* if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
		return ans; } */
	while(n&(n-1)) ++n;
	auto foo = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].re + w[j].re * r, w[i].im
				- w[j].im * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { // standard fast version
		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].re = a[i] - big;
		REP(i, b.size()) in[i].im = b[i] - big;
		dft(in, false);
		REP(i, n) done[i] = foo(in, i, 0) * foo(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].re) : done[i].re;
	//REP(i,ans.size())err=max(err,abs(done[i].re-ans[i]));
	}
	else { // Split big INTEGERS into pairs a1*M+a2,
		const T M = 1<<15; // where M = sqrt(max_absvalue).
		vector<C> t[2]; // This version is 2.2-2.5 times slower.
		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a; // below use (in[i]-big) if normalized
			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul = (mul * M)%mod) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += foo(t[0], i, x) * foo(t[1], i, y);
			dft(prod, true); // remember: llround(prod[i].re)%MOD*mul !!!
			REP(i, ans.size()) ans[i] = (ans[i] + llround(prod[i].re)%mod*mul)%mod;
		}
	}
	if(normalize) {
		T so_far = 0;
		REP(i, ans.size()) {
			if(i < (int) a.size()) so_far += a[i] + b[i];
			else so_far -= a[i-a.size()] + b[i-a.size()];
			ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
		}
	}
	return ans;
}

ll pot(ll a, ll b)
{
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

int n, k;

ll sil[nax];
ll odw[nax];
ll inv[nax];

ll wyb[nax];

ll kom(int a, int b)
{
	if (b>a || b<0)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

ll zn[nax];

ll wyn;

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%d%d", &n, &k);
	sil[0]=1;
	for (int i=1; i<=k; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[k]=pot(sil[k], mod-2);
	for (int i=k; i; i--)
		odw[i-1]=(odw[i]*i)%mod;
	for (int i=1; i<=k; i++)
		wyb[i]=pot(i, k);
	for (int i=1; i<=k; i++)
		inv[i]=(odw[i]*sil[i-1])%mod;
	//~ debug() << range(wyb+1, wyb+1+k);
	{
		vll a(k+1);
		vll b(k+1);
		for (int i=1; i<=k; i++)
			a[i]=wyb[i]*odw[i]%mod;
		for (int i=1; i<=k; i++)
		{
			b[i]=odw[i];
			if (i&1)
				b[i]=(mod-b[i])%mod;
		}
		vll wez=multiply(a, b);
		//~ debug() << a;
		//~ debug() << b;
		//~ debug() << wez;
		for (int i=1; i<=k; i++)
		{
			//~ debug() << i << " " << wez[i] << " " << wez[i]*sil[i]%mod;
			wyb[i]=(wyb[i]+wez[i]*sil[i])%mod;
		}
	}
	//~ debug() << range(wyb+1, wyb+1+k);
	{
		zn[0]=1;
		for (int i=1; i<=k; i++)
		{
			zn[i]=(zn[i-1]*(n-i)%mod*inv[i])%mod;
		}
		
		for (int i=1; i<=min(k, n-1); i++)
		{
			dod(wyn, wyb[i]*zn[i]%mod*(n+1)%mod*pot(n+1, n-1-i));
		}
		for (int i=1; i<=min(k, n); i++)
		{
			dod(wyn, wyb[i]*zn[i-1]%mod*pot(n+1, n-1-(i-1)));
		}
	}
	
	printf("%lld\n", wyn);
	return 0;
}