#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<list>
#include<queue>
#include<deque>
#include<random>
#include<functional>
#include<set>
#include<map>
#include<utility>
#include<string>
#include<bitset>
#include<chrono>
#include<cassert>
#include<ctime>
#include<iomanip>

using namespace std;

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fore(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if (min(m, k) >= n) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}