#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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
const int MAX_N = 1;

int N, K, T;
ll KK;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &K);
		KK = (ll)K*(ll)K;
		if((ll)N<KK){
			printf("NO\n");
		}else{
			if((N%2)==(K%2)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}