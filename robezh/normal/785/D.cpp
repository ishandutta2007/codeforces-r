#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll mod = (ll)1e9 + 7;

string str;
int n;
int pl[N], sr[N];
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> str;
    n = str.length();
    for(int i = 0; i < n; i++) {
        if(i > 0) pl[i] += pl[i-1];
        if(str[i] == '(') pl[i]++;
    }
    for(int i = n-1; i >= 0; i--) {
        if(i < n-1) sr[i] += sr[i+1];
        if(str[i] == ')') sr[i]++;
    }
    ll res = 0;
    for(int i = 0; i + 1 < n; i++) {
        res += comb(pl[i] + sr[i+1], sr[i+1]) - 1;
        if(i > 0) res -= comb(pl[i-1] + sr[i+1], sr[i+1]) - 1;
    }
    res = (res % mod + mod) % mod;
    cout << res << endl;
}