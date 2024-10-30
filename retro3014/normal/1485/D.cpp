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
const int MAX_N = 500;
const int C = 720720;

int N, M;
int arr[MAX_N+1][MAX_N+1];
int ans[MAX_N+1][MAX_N+1];

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &arr[i][j]);
			if((i+j)%2==1){
				ans[i][j] = C-arr[i][j]*arr[i][j]*arr[i][j]*arr[i][j];
			}else{
				ans[i][j] = C;
			}
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			printf("%d ", ans[i][j]);
		}printf("\n");
	}
	return 0;
}