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

const int MAX_B=60;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n); cin >> a;

    vector<vector<int>> G(n+MAX_B);
    for (int i=0;i<n;++i){
        for (int j=0;j<MAX_B;++j){
            if (a[i]&1LL<<j){
                G[i].emplace_back(n+j);
                G[n+j].emplace_back(i);
            }
        }
    }

    for (int i=n;i<n+MAX_B;++i){
        if (G[i].size()>=3){
            cout << 3 << '\n';
            return 0;
        }
    }

    int ans=INF;
    auto BFS=[&](int s){
        if (G[s].size()<2) return;
        for (int _=0;_<2;++_){
            int to=G[s][_^1];
            vector<int> d(n+MAX_B,INF);
            queue<int> que;
            d[s]=0; d[G[s][_]]=1; que.emplace(G[s][_]);
            while(!que.empty()){
                int v=que.front(); que.pop();
                for (int u:G[v]){
                    if (d[u]<=d[v]+1) continue;
                    if (u==to&&d[v]+1==3) continue;
                    d[u]=d[v]+1;
                    que.emplace(u);
                }
            }
            if (d[to]==INF) continue;
            chmin(ans,(d[to]+1)/2);
        }
    };
    for (int i=n;i<n+MAX_B;++i) BFS(i);

    cout << (ans==INF?-1:ans) << '\n';
}