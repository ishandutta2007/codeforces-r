#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 200000;

int N;

map<int, ll> mp;
ll ans = 0;
int main(){
	scanf("%d", &N);
	for(int i=1 ;i<=N; i++){
		int x; scanf("%d", &x);
		int y = x-i;
		mp[y]+=(ll)x;
		ans = max(ans, mp[y]);
	}
	printf("%lld", ans);
	return 0;
}