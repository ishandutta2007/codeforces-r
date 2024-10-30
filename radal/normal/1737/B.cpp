#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+15,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}

ll calc(ll x){
    if (!x) return 0;
    int l = 1,r = inf,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (1ll*m*m <= x) l = m;
        else r = m;
    }
    ll ans = l;
    while (1ll*l*(l+1) > x) l--;
    ans += l;
    while (1ll*l*(l+2) > x) l--;
    ans += l;
    return ans;
}
void solve(){
    ll l,r;
    cin >> l >> r;
    cout << calc(r)-calc(l-1) << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); 
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}