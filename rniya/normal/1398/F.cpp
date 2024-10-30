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

const int MAX_N=1e6+10;
int nxt[2][MAX_N];
vector<int> pos[2][MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; string S; cin >> n >> S;

    for (int i=n-1;i>=0;--i){
        if (S[i]!='1') nxt[0][i]=nxt[0][i+1]+1;
        if (S[i]!='0') nxt[1][i]=nxt[1][i+1]+1;
    }

    for (int _=0;_<2;++_){
        int l=0;
        while(l<n){
            while(l<n&&S[l]==char('0'+(_^1))) ++l;
            int r=l+1;
            while(r<n&&S[r]!=char('0'+(_^1))) ++r;
            for (int i=1;i<=r-l;++i) pos[_][i].emplace_back(l);
            l=r;
        }
    }

    for (int i=1;i<=n;++i){
        int now=0,ans=0;
        vector<int> big(2,0);
        while(now<n){
            int npos=INF;
            for (int _=0;_<2;++_){
                if (nxt[_][now]>=i) npos=min(npos,now+i);
                while(big[_]<pos[_][i].size()&&pos[_][i][big[_]]<now) ++big[_];
                if (big[_]<pos[_][i].size()) npos=min(npos,pos[_][i][big[_]]+i);
            }
            ans+=(npos!=INF);
            now=npos;
        }

        cout << ans << (i==n?'\n':' ');
    }
}