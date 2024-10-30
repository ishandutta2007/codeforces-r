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
    cout << '(' << p.first << ',' << p.second << ')';
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

template<typename T>
struct Dijkstra{
    const T inf=numeric_limits<T>::max();
    using P=pair<T,int>;
    int n;
    vector<vector<pair<int,T>>> G;
    vector<T> d;
    Dijkstra(int n):n(n),G(n),d(n){}
    void add_edge(int u,int v,T w){
        G[u].emplace_back(v,w);
    }
    vector<T> build(int s){
        fill(d.begin(),d.end(),inf);
        d[s]=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.emplace(d[s],s);
        while(!pq.empty()){
            P p=pq.top(); pq.pop();
            int v=p.second;
            if (d[v]<p.first) continue;
            for (auto &e:G[v]){
                int u=e.first; T c=e.second;
                if (d[v]+c<d[u]){
                    d[u]=d[v]+c;
                    pq.emplace(d[u],u);
                }
            }
        }
        return d;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    Dijkstra<int> D(n);
    vector<vector<int>> G(n);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v;
        D.add_edge(--v,--u,1);
        G[u].emplace_back(v);
    }
    int k; cin >> k;
    vector<int> p(k);
    for (int i=0;i<k;++i) cin >> p[i],--p[i];
    int t=p[k-1];
    vector<int> d=D.build(t);
    int Min=0,Max=0;
    for (int i=0;i<k-1;++i){
        if (d[p[i]]-1!=d[p[i+1]]){
            ++Min; ++Max;
            continue;
        }
        int cnt=0;
        for (int u:G[p[i]]){
            if (d[u]==d[p[i+1]]){
                ++cnt;
            }
        }
        if (cnt>=2) ++Max;
    }
    cout << Min << ' ' << Max << '\n';
}