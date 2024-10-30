#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define ll long long
#define ull unsigned long long

#define FOR(i, n) for(ll i = 0; i < (n); ++i)
#define FORU(i, j, k) for(ll i = j; i <= (k); ++i)
#define FORD(i, j, k) for(ll i = j; i >= (k); --i)

#define pf push_front
#define pb push_back

#define mp make_pair
#define f first
#define s second


int main(int, char**){
  ios::sync_with_stdio(false);
  ll n, m; cin >> n >> m;
  ll r = 0;ll c = 0;
  FOR(i, n){
    ll a; cin >> a;
    if(c < a){
      r+=1;
      c=m;
    }
    c-=a;
  }
  cout << r << endl;
  return 0;
}