#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
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
typedef pair<long double,long double> pld;
const long long int N = 1e5+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
   // cin >> T;
    while(T--){
        int n,q;
        string s;
        cin >> n >> q >> s;
        int t = 0;
        rep(i,0,n-2)
            if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') t++;
        while (q--){
            char c;
            int p;
            cin >> p >> c;
            p--;
            if (s[p] == 'a'){
                if (p+2 < n && s[p+1] == 'b' && s[p+2] == 'c') t--;
            }
            if (s[p] == 'b'){
                if (p+1 < n && p && s[p-1] == 'a' && s[p+1] == 'c') t--;
            }
            if (s[p] == 'c'){
                if (p-1 > 0 && s[p-1] == 'b' && s[p-2] == 'a') t--;
            }
            s[p] = c;
            if (s[p] == 'a'){
                if (p+2 < n && s[p+1] == 'b' && s[p+2] == 'c') t++;
            }
            if (s[p] == 'b'){
                if (p+1 < n && p && s[p-1] == 'a' && s[p+1] == 'c') t++;
            }
            if (s[p] == 'c'){
                if (p-1 > 0 && s[p-1] == 'b' && s[p-2] == 'a') t++;
            }
            cout << t << endl;
        }
    }
}