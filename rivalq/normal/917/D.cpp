// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int MOD = hell;
 
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};

/*
* Interpolate polynomial of n - 1 degree from n point
*/

template<typename T>
vector<T> interpolate(const vector<T> &x, const vector<T> &y){
    int n = x.size();
    vector<T> ret(n);
    vector<T> numerator(n + 1);
    vector<T> val(n + 1);
    numerator[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j >= 1; j--){
            numerator[j] = numerator[j - 1] -  x[i] * numerator[j];
        }
        numerator[0] = -numerator[0]*x[i];
    }
    for(int i = 0; i < n; i++){
        T den = 1;
        for(int j = 0; j < n; j++) {
                if(j != i) den *= (x[i] -  x[j]);
        }
        T coeff = y[i]/den;
        copy(numerator.begin(), numerator.end(), val.begin());
        T a = x[i];
        for(int j = n - 1; j >= 0; j--){
            T h = val[j + 1];
            val[j] = val[j] + a*h;
            ret[j] = ret[j] + h*coeff;
        }
    }
    return ret;

}

template<typename T>
T determinant (vector<vector<T>> V){
    T ret = static_cast<T>(1);
    int n = V.size();
    vector<bool> done(n, 0);
    for(int j = 0; j < n; j++){
        bool found = false;
        for(int i = 0; i < n; i++) if(V[i][j] != 0 and !done[i]){
            T coeff = 1/V[i][j];
            for(int k = 0; k < n; k++) if(!done[k] && i != k && V[k][j] != 0){
                // Rk -> Rk - V[k][j] / V[i][j] * Ri
                T factor = V[k][j]*coeff;
                for(int l = 0; l < n; l++){
                    V[k][l] = V[k][l] - factor* V[i][l];
                }
            }
            found = true;
            done[i] = 1;
            ret = ret*V[i][j];
            break;
        }
        if(!found) return static_cast<T>(0);
    }
    return ret;
}



int solve(){
                int n; cin >> n;
                vector<vector<mod_int>>g(n,vector<mod_int>(n,0));
                rep(i,2,n + 1){
                        int u,v; cin >> u >> v;
                        u--;v--;
                        g[u][v] = 1;
                        g[v][u] = 1;
                }

                vector<mod_int>x(n),y(n);
                for(int k = 0; k < n; k++){
                        vector<vector<mod_int>>t(n,vector<mod_int>(n));
                        for(int i = 0; i < n; i++){
                                mod_int deg = 0;
                                for(int j = 0; j < n; j++){
                                        if(i != j){
                                                if(g[i][j] == 0)t[i][j] = -1;
                                                else t[i][j] = -k;
                                                deg += t[i][j];
                                        }
                                }
                                t[i][i] = -deg;
                        }
                        vector<vector<mod_int>>V(n - 1,vector<mod_int>(n - 1));
                        for(int i = 1; i < n; i++){
                                for(int j = 1; j < n; j++){
                                        V[i - 1][j - 1] = t[i][j];
                                }
                        }
                        x[k] = k;
                        y[k] = determinant(V);
                       // cout << x[k] << " " << y[k] << endl;
                }
                auto res = interpolate(x,y);
                for(int i = 0; i < n; i++)cout << res[i] << " ";
                cout << endl;


 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}