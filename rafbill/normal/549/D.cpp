#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <tuple>

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(int i = (j); i >= (k); --i)

#define X first
#define Y second
#define union union_

using namespace std;

template <typename T>
void hash_combine (size_t& seed, const T& val){
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}
template <typename T, typename... Ts>
void hash_combine (size_t& seed, const T& val, const Ts&... args){
  hash_combine(seed, val);
  hash_combine(seed, args...);
}
void hash_combine (size_t&){}
template <typename... Ts>
size_t hash_val (const Ts&... args){
  size_t seed = 0;
  hash_combine (seed, args...);
  return seed;
}

using pt   = pair<long long int, long long int>;
using vec2 = pair<pt, pt>;

struct union_find{
  union_find(int n) : A(n), R(n){
    FOR(i, n) A[i] = i;
    FOR(i, n) R[i] = 0;
  }

  int find(int i){
    if(A[i] != i){ A[i] = find(A[i]); }
    return A[i];
  }

  int union(int i, int j){
    i = find(i); j = find(j);
    if(i != j){
      if(R[i] < R[j]){
        A[i] = j;
      }else if(R[j] < R[i]){
        A[j] = i;
        R[i] += R[i] == R[j];
      }
    }
    return A[i];
  }

  vector<int> A;
  vector<int> R;
};

long long int A[101][101];

int main(int, char**){
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  FOR(i, n) {
    string s; cin >> s;
    FOR(j, m) if(s[j] == 'W') A[i][j] = 1; else A[i][j] = -1;
  }
  int r = 0;
  FORR(ipj, n+m-2, 0) FOR(i, n) { int j = ipj-i; if (i >= 0 && j >= 0 && i < n && j < m){
      if(A[i][j] != 0){
        long long int v = A[i][j];
        r += 1;
        FOR(x, i+1) FOR(y, j+1){
          A[x][y] -= v;
        }
      }
    }
  }
  cout << r << endl;
  return 0;
}