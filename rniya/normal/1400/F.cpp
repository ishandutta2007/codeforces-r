#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; int x; cin >> S >> x;

    int n=S.size();
    vector<vector<int>> dp(2,vector<int>(1<<x,INF));
    dp[0][0]=0;
    vector<int> check,div;
    int ng=1;
    for (int i=1;i<x;++i){
        if (x%i==0){
            div.emplace_back(i);
            ng|=1<<i;
        }
    }
    for (int mask=0;mask<(1<<x);++mask){
        if (!(mask&ng)) check.emplace_back(mask);
    }

    for (int i=0;i<n;++i){
        int c=S[i]-'0';
        for (int mask:check){
            int upd=dp[i&1][mask];
            dp[(i+1)&1][mask]=min(dp[(i+1)&1][mask],upd+1);
            (mask|=1)<<=c;
            for (int d:div){
                if (mask&1<<d){
                    mask&=(1<<d)-1;
                }
            }
            if (mask&1<<x) continue;
            mask&=(1<<x)-1;
            dp[(i+1)&1][mask]=min(dp[(i+1)&1][mask],upd);
        }
        for (int mask:check) dp[i&1][mask]=INF;
    }

    int ans=INF;
    for (int mask=0;mask<(1<<x);++mask) ans=min(ans,dp[n&1][mask]);
    cout << ans << '\n';
}