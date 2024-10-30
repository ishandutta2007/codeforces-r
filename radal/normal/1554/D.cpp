#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 'a' << endl;
            continue;
        }
        if (n&1){
            rep(i,0,(n-1)/2) cout<<'a';
            cout << "bc";
            rep(i,0,(n-3)/2) cout << 'a';
            cout << endl;
            continue;
        }
        rep(i,0,n/2) cout << 'a';
        cout << 'b';
        rep(i,0,(n-2)/2) cout << 'a';
        cout << endl;
    }
    return 0;
}