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
    int n,m; cin >> n >> m;
    struct edge{
        int u,t;
        edge(int u,int t):u(u),t(t){}
    };
    vector<vector<edge>> G(n),rG(n);
    for (int i=0;i<m;++i){
        int u,v,t; cin >> u >> v >> t; --u,--v;
        if (u==v) continue;
        G[u].emplace_back(v,t);
        rG[v].emplace_back(u,t);
    }

    vector<int> ans(n,-1);
    vector<vector<int>> dp(n,vector<int>(2,INF));
    queue<int> que;
    ans[n-1]=dp[n-1][0]=dp[n-1][1]=0;
    que.emplace(n-1);
    while(!que.empty()){
        int v=que.front(); que.pop();
        ans[v]=(dp[v][0]<dp[v][1]?1:0);
        for (auto e:rG[v]){
            if (dp[e.u][e.t]!=INF) continue;
            dp[e.u][e.t]=dp[v][ans[v]]+1;
            if (dp[e.u][e.t]!=INF&&dp[e.u][e.t^1]!=INF) que.emplace(e.u);
        }
    }

    int len=max(dp[0][0],dp[0][1]);
    cout << (len==INF?-1:len) << '\n';
    for (int i=0;i<n;++i) cout << (dp[i][0]<dp[i][1]?1:0);
    cout << '\n';
}