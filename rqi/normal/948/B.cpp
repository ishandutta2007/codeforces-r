#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
/*
CUML SUM
DFS BFS BIN SEARCH
STRUCTS
TWOPOINT
GREEDY
Data Structures
Basic 1D Range Queries
Graphs
Shortest Path
Topological Sort
Strings
Hashing
Trees
MST
Dynamic Programming
Intro
DP
DSU
*/
bool isprime[1000006];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	for(int i = 2; i < 1000006; i++){
	    if(isprime[i] == 0){
	        for(int j = 2*i; j < 1000006; j+=i){
	            isprime[j] = 1;
	        }
	    }
	}
	
	int x2;
	cin >> x2;
	int prime = x2;
	for(int i = x2-1; i >=2; i--){
	    if(isprime[i] == 0 && x2 % i == 0){
	        prime = i;
	        break;
	    }
	}
	int ans = MOD;
	for(int i = x2-prime+1; i < x2; i++){
	    if(i % 2 == 0 && isprime[i/2] == 0){
	        ans = i/2+1;
	        break;
	    }
	    if(isprime[i] == 0){
	        ans = min(ans, i);
	    }
	    for(int j = i/2; j >= 2; j--){
	        if(isprime[j] == 0 && i % j == 0){
	            ans = min(ans, i-j+1);
	        }
	    }
	}
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!