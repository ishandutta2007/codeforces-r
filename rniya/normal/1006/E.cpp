#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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
    cout << '(' << p.first << ',' << p.second << ')';
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

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

const int MAX_N=2e5+10;

int n,q;
vector<int> G[MAX_N];
int ord[MAX_N],sub[MAX_N];
vector<int> ans;

void dfs(int v,int p){
    sub[v]=1;
    ord[v]=ans.size();
    ans.emplace_back(v);
    for (int u:G[v]){
        if (u==p) continue;
        dfs(u,v); sub[v]+=sub[u];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1;i<n;++i){
        int p; cin >> p;
        G[--p].emplace_back(i);
    }
    dfs(0,-1);
    for (;q--;){
        int u,k; cin >> u >> k; --u;
        cout << (sub[u]<k?-1:ans[ord[u]+k-1]+1) << '\n';
    }
}