#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
// const long long MOD=1e9+7;
const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(x%Modulus){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept{return a;}
    constexpr modint &operator+=(const modint &rhs) noexcept{
        a+=rhs.a;
        if (a>=Modulus) a-=Modulus;
        return *this;
    }
    constexpr modint operator+(const modint &rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint &operator++() noexcept{
        return ++a,*this;
    }
    constexpr modint operator++(int) noexcept{
        modint t=*this; return ++a,t;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{
        if (a<rhs.a) a+=Modulus;
        a-=rhs.a;
        return *this;
    }
    constexpr modint operator-(const modint &rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint &operator--() noexcept{
        return --a,*this;
    }
    constexpr modint operator--(int) noexcept{
        modint t=*this; return --a,t;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        a=a*rhs.a%Modulus;
        return *this;
    }
    constexpr modint operator*(const modint &rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        u64 exp=Modulus-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    constexpr modint operator/(const modint &rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint operator-() const noexcept{
        return modint(Modulus-a);
    }
    constexpr bool operator==(const modint &rhs) const noexcept{
        return a==rhs.a;
    }
    constexpr bool operator!=(const modint &rhs) const noexcept{
        return a!=rhs.a;
    }
    constexpr bool operator!() const noexcept{return !a;}
    friend constexpr modint pow(modint rhs,long long exp) noexcept{
        modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept{
        return modint(x)+y;
    }
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept{
        return modint(x)-y;
    }
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept{
        return modint(x)*y;
    }
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept{
        return modint(x)/y;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,modint &rhs) noexcept{
        u64 a; rhs=modint{(s >> a,a)}; return s;
    }
};

using mint=modint<MOD>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> a(n),w(n); cin >> a >> w;

    vector<int> sum(2,0);
    int Max=0;
    for (int i=0;i<n;++i) sum[a[i]]+=w[i];

    vector<vector<mint>> dp0(m+1,vector<mint>(m+1,0))
                        ,dp1(m+1,vector<mint>(m+1,0));
    dp0[0][0]=dp1[0][0]=1;
    for (int i=0;i<m;++i){
        for (int j=0;j<m;++j){
            int OK=sum[1]+j,NG=sum[0]-(i-j);
            if (NG<0) continue;
            mint inv=(mint)1/(OK+NG);
            dp0[i+1][j+1]+=dp0[i][j]*OK*inv;
            dp0[i+1][j]+=dp0[i][j]*(NG-dp0[i][j])*inv+(dp0[i][j]-1)*dp0[i][j]*inv;
            dp1[i+1][j+1]+=dp1[i][j]*(OK-dp1[i][j])*inv+(dp1[i][j]+1)*dp1[i][j]*inv;
            dp1[i+1][j]+=dp1[i][j]*NG*inv;
        }
    }

    mint ans0=0,ans1=0;
    for (int j=0;j<=m;++j){
        ans0+=dp0[m][j];
        ans1+=dp1[m][j];
    }

    for (int i=0;i<n;++i){
        cout << (a[i]?ans1:ans0)*w[i] << '\n';
    }
}