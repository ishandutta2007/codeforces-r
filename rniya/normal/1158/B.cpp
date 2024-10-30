#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
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

int calc(string s){
    map<string,int> mp;
    for (int i=0;i<s.size();++i){
        for (int j=1;i+j-1<s.size();++j){
            ++mp[s.substr(i,j)];
        }
    }
    int res=s.size();
    for (auto p:mp){
        if (p.second==1){
            res=min(res,(int)p.first.size());
        }
    }
    return res;
}

void check(int n){
    for (int mask=0;mask<(1<<n);++mask){
        string s="";
        for (int i=0;i<n;++i) s+=(char)('0'+((mask&1<<i)>>i));
        int Min=calc(s);
        if (Min!=4) continue;
        cerr << s << ' ' << Min << '\n';
    }
}

void solve(int n,int k){
    if (k==1){
        string ans="0";
        for (int i=0;i<n-1;++i) ans+='1';
        cout << ans << '\n';
        return;
    }
    int cycle=(n-k)/2;
    string base="0";
    for (int i=0;i<cycle;++i) base+='1';
    string ans="";
    for (int i=0;i<n;++i) ans+=base[i%(cycle+1)];

    cout << ans << '\n';
    // if (calc(ans)!=k){debug(n,k,ans);}
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    solve(n,k);
    // for (int i=1;i<20;++i){
    //     for (int j=i;j>0;j-=2){
    //         solve(i,j);
    //     }
    // }
}