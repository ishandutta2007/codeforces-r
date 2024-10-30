#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2000 + 5;
int n,a[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        std::vector<int> v[2];
        FOR(i,1,n){
            int x;scanf("%d",&x);
            v[x%2].pb(x);
        }
        n = 0;
        for(auto x:v[0]) a[++n] = x;
        for(auto x:v[1]) a[++n] = x;
        int ans = 0;
        FOR(i,1,n){
            FOR(j,i+1,n){
                ans += (std::__gcd(a[i],2*a[j]) > 1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}