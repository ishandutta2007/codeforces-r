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

int N, M;

int main(){
	cin>>M;
	while(M--){
		cin>>N;
		if(N==2){
			cout<<2<<endl;
		}else if(N==3){
			cout<<1<<endl;
		}else if(N%2==0){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}