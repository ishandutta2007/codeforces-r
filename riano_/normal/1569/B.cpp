#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<int>>;
 
const ll mod = 1000000007;
template<uint64_t mod>
struct modint{
    uint64_t val;
    constexpr modint(const int64_t val_=0) noexcept:val((val_%int64_t(mod)+int64_t(mod))%int64_t(mod)){}
    constexpr modint operator-() const noexcept{
        return modint(*this)=mod-val;
    }
    constexpr modint operator+(const modint rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept{
        val+=rhs.val;
        val-=((val>=mod)?mod:0);
        return (*this);
    }
    constexpr modint &operator-=(const modint rhs) noexcept{
        val+=((val<rhs.val)?mod:0);
        val-=rhs.val;
        return (*this);
    }
    constexpr modint &operator*=(const modint rhs) noexcept{
        val=val*rhs.val%mod;
        return (*this);
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        uint64_t ex=mod-2;
        modint now=1;
        while(ex){
            now*=((ex&1)?rhs:1);
            rhs*=rhs,ex>>=1;
        }
        return (*this)*=now;
    }
    constexpr bool operator==(const modint rhs) noexcept{
        return val==rhs.val;
    }
    constexpr bool operator!=(const modint rhs) noexcept{
        return val!=rhs.val;
    }
    friend constexpr ostream &operator<<(ostream& os,const modint x) noexcept{
        return os<<(x.val);
    }
    friend constexpr istream &operator>>(istream& is,modint& x) noexcept{
        uint64_t t;
        is>>t,x=t;
        return is;
    }
};

int main() {
    riano_; //ll ans = 1;
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        string S; cin >> S;
        char ans[N][N];
        rep(i,N){
            rep(j,N){
                if(i==j) ans[i][j] = 'X';
                else ans[i][j] = '=';
            }
        }
        vector<ll> win;
        rep(i,N){
            if(S[i]=='2') win.push_back(i);
        }
        if(win.size()>0&&win.size()<3){
            cout << "NO" << "\n"; continue;
        }
        cout << "YES" << "\n";
        vector<ll> w,l;
        if(win.size()>0){
            rep(i,win.size()){
                w.push_back(win[i]);
                l.push_back(win[(i+1)%(win.size())]);
            }
        }
        rep(i,w.size()){
            ans[w[i]][l[i]] = '+';
            ans[l[i]][w[i]] = '-';
        }
        rep(i,N){
            rep(j,N){
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
}