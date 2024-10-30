#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e2+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
int b[N][N],ans[N][N];
bool mark[N][N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;       
        cin >> n >> m;
        multiset<pair<int,pll>> st;
        rep(i,0,n) rep(j,0,m) mark[i][j] = 0,ans[i][j] =-1;
        rep(i,0,n){
            rep(j,0,m){
                cin >> b[i][j];
                st.insert({b[i][j],{i,j}});
            }
        }
        rep(i,0,m){
            auto p = *(st.begin());
            ans[p.Y.X][i] = p.X;
            mark[p.Y.X][p.Y.Y] = 1;
            st.erase(st.begin());
        }
        rep(i,0,n){
            int p = 0;
            rep(j,0,m){
                if (mark[i][j]) continue;
                while (p < m && ans[i][p] != -1) p++;
                ans[i][p] = b[i][j];
            }
        }
        rep(i,0,n){
            rep(j,0,m) cout << ans[i][j] << ' ';
            cout << endl;
        }

    }
    return 0;
}