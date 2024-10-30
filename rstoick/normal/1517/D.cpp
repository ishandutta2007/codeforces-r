#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include <functional>
#include <cassert>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
// using mint = modint1000000007;
#define MOD (long long int)(1e9+7)
// using mint = modint998244353;
// #define MOD (long long int)(9982/44353)
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=(int)(n)-1; i>=0; i--)
#define REPS(i,n) for(int i=(int)(n); i>0; i--)
#define INF (int)(1e9)
#define LINF (long long int)(1e18)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0-1.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  if(n <= 1e7){
    ret *= kaijo(n); ret %= MOD;
    ret *= gyaku_kaijo(r); ret %= MOD;
    ret *= gyaku_kaijo(n-r); ret %= MOD;
  }else{
    rep(i,r){
      ret *= n-i; ret %= MOD;
      ret *= mpow(r-i, MOD-2); ret %= MOD;
    }
  }
  return ret;
}

vector<ll> yakusu(ll n){
  assert(n > 0);
  vector<ll> ret;
  for(ll p = 1; p*p <= n; p++){
    if(n%p == 0){
      ret.push_back(p);
      if(p*p != n){
        ret.push_back(n/p);
      }
    }
  }
  sort(all(ret));
  return ret;
}

map<ll,ll> soinsu(ll n){
  assert(n > 0);
  map<ll,ll> mp;
  for(ll p = 2; p*p <= n; p++){
    if(n%p == 0){
      mp[p]++;
      n /= p;
      p--;
    }
  }
  if(n > 1){
    mp[n]++;
  }
  return mp;
}


int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  int h,w,k;cin>>h>>w>>k;
  vector<vector<ll>> DX(h, vector<ll>(w-1, INF)), DY(h-1, vector<ll>(w, INF));
  rep(y,h){
    rep(x,w-1){
      cin>>DX[y][x];
    }
  }
  rep(y,h-1){
    rep(x,w){
      cin>>DY[y][x];
    }
  }
  if(k%2 == 1){
    rep(y,h){
      rep(x,w){
        cout<<-1<<" ";
      }
      cout<<endl;
    }
    return 0;
  }
  k/=2;
  vector<vector<vector<ll>>> dp(k+1, vector<vector<ll>>(h, vector<ll>(w, INF)));
  rep(y,h){
    rep(x,w){
      dp[0][y][x] = 0;
    }
  }
  reps(t, k){
    rep(y,h){
      rep(x,w){
        auto& target = dp[t][y][x];
        if(y-1>=0){
          chmin(target, dp[t-1][y-1][x] + DY[y-1][x]);
        }
        if(x-1>=0){
          chmin(target, dp[t-1][y][x-1] + DX[y][x-1]);
        }
        if(y+1<h){
          chmin(target, dp[t-1][y+1][x] + DY[y][x]);
        }
        if(x+1<w){
          chmin(target, dp[t-1][y][x+1] + DX[y][x]);
        }
      }
    }
  }

  rep(y,h){
    rep(x,w){
      cout<<dp[k][y][x]*2<<" ";
    }
    cout<<endl;
  }
  return 0;
}