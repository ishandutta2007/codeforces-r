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


template<typename T>
class matrix{
    public:
    vector<vector<T>> val;
    int n;
    matrix<T>(int size){
        n=size;
        val.resize(n);
        rep(i,0,n)val[i].resize(n);
    }
    matrix<T> operator+(const matrix<T>&) const;
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T>& operator=(const matrix<T>& b){
        val=b.val;
        n=b.n;
        return *this;
    }
    void set(int x){
        rep(i,0,n){
            rep(j,0,n){
                val[i][j]=x;
            }
        }
    }
    void print(){
        rep(i,0,n){
            rep(j,0,n){
                cout<<val[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    matrix<T> mul(T a){
        matrix<T> ans(this->n);
        rep(i,0,this->n){
            rep(j,0,this->n){
                ans.val[i][j]=a*this->val[i][j];
            }
        }
        return ans;
    }
    matrix<T> operator*(const matrix<T>& b) const{
        matrix<T> ans(b.n);
        rep(i,0,b.n){
            rep(j,0,b.n){
              rep(k,0,b.n){
                  ans.val[i][j]+=this->val[i][k]*b.val[k][j];
              }
           }
        }
        return ans;			
    }
    matrix<T> identity(int N){
       matrix<T> ans(N);
       rep(i,0,N){
          ans.val[i][i]=1;
       }
       return ans;
    }
    matrix<T> matexpo(matrix<T> a, int n){
        if(n==0){
          return identity(a.n);
        }
        if(n==1) return a;
        matrix<T> x=matexpo(a,n/2);
        matrix<T> r=x*x;
        if(n&1) r=r*a;
        return r;
   }

};

const int M = 100;

int solve(){
 		int n,x; cin >> n >> x;
 		vector<int>d(101);
 		rep(i,1,n+1){
 			int t; cin >> t;
 			d[t]++;
 		}	
 		if(x <= 100){
 			vector<mod_int>dp(x+1);
 			mod_int ans = 1;
 			dp[0] = 1;
 			for(int j = 1; j <= x; j++){
 				for(int k = 1; k <= j; k++){
 					dp[j] += d[k]*dp[j - k];
 				}
 				ans += dp[j];
 			}
 			cout << ans << endl;
 			return 0;
 		}else{
 			vector<mod_int>dp(101);
 			mod_int val = 1;
 			dp[0] = 1;
 			for(int j = 1; j <= 100; j++){
 				for(int k = 1; k <= j; k++){
 					dp[j] += d[k]*dp[j - k];
 				}
 				val += dp[j];
 			}
 			matrix<mod_int>mat(M + 1);
 			for(int j = 0; j < M; j++){
 				mat.val[0][j] = d[j + 1];
 				mat.val[M][j] = d[j + 1];
 			}	
 			mat.val[M][M] = 1;
 			for(int i = 1; i < M; i++){
 				mat.val[i][i - 1] = 1;
 			}
 			mat = mat.matexpo(mat,x - M);
 			mod_int ans = 0;
 			for(int j = 0; j < M; j++){
 				ans += mat.val[M][j]*dp[M - j];
 			}
 			ans += mat.val[M][M]*val;
 			cout << ans << endl;
 		}
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