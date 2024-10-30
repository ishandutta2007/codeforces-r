#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#else
#define File(s)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
  char ch; x = 0;int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> inline void wi(T x){
  static char stk[128]; int top = 0;
  if(x == 0) putchar('0');
  if(x < 0) putchar('-'), x = -x;
  while(x) stk[++top] = x % 10, x /= 10;
  while(top) putchar(stk[top--] + '0');
}
template<class T, class ...Args>
inline void gi(T &x, Args&... args) {gi(x); gi(args...);}
template<class T, class ...Args>
inline void wi(T x, Args... args) {wi(x); SP; wi(args...);}
template<class T> void upmax(T &x, T y) {x = x > y ? x : y;}
template<class T> void upmin(T &x, T y) {x = x < y ? x : y;}

const int N = 300005;
int k[N], c[N];
ll s[N], cs[N];
int n, m;

bool check(int cnt) {
  for (int i = 1; i <= cnt; ++i)
    if (k[n - cnt + i] < i) return false;
  return true;
}

int main(){
  File("a");
  int T;
  gi(T);
  while(T--) {
    gi(n, m);
    for (int i = 1; i <= n; ++i) gi(k[i]);
    for (int i = 1; i <= m; ++i) gi(c[i]);
    sort(k + 1, k + 1 + n);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + c[k[i]];
    for (int i = 1; i <= m; ++i) cs[i] = cs[i - 1] + c[i];
    int L = 0, R = min(n, m), M, res = 0;
    while (L <= R) {
      M = (L + R) >> 1;
      if (!check(M)) R = M - 1;
      else res = M, L = M + 1;
    }
    ll mn = numeric_limits<ll>::max();
    for (int i = 0; i <= res; ++i)
      mn = min(mn, cs[i] + s[n - i]);
    wi(mn), EL;
  }
  return 0;
}