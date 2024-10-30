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
const int MAX_N = 100000;

int N;
int arr[MAX_N*2+1];

int main(){
	cin>>N;
	if(N%2==0){
		printf("NO");
		return 0;
	}
	for(int i=1; i<=N; i++){
		if(i%2==1){
			arr[i] = i*2-1;
			arr[i+N] = i*2;
		}else{
			arr[i] = i*2;
			arr[i+N] = i*2-1;
		}
	}
	printf("YES\n");
	for(int i=1; i<=N*2; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}