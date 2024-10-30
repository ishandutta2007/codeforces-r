#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,maxm= (1 << 21);
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
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
int a[N],b[N];
inline void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    ll sum = 0;
    int mx = 0,l = 0,t = 0;
    rep(i,0,n){
        cin >> a[i];
        if (i && i < n-1){
            if (a[i]&1){
                cnt++;
                l++;
            }
            else{
                t = max(l,t);
                l = 0;
            }
            sum += a[i];
            mx = max (mx,a[i]);
        }
    }
    t = max(l,t);
    if (mx == 1 || (cnt && n == 3)){
        cout << -1 << endl;
        return;
    }
    if (t <= cnt-t){
        if ((sum&1)){
            cout << sum/2+cnt/2+1 << endl;
            return;
        }
        else{
            cout << sum/2+cnt/2 << endl;
            return;
        }
    }
    cout << sum/2+(cnt+1)/2 << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}