#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

const int MAX_N=2e5+10;

int n;
int a[MAX_N];

void solve(){
    map<int,int> m;
    for (int i=0;i<n;++i) ++m[a[i]];
    vector<int> v;
    for (auto p:m) v.emplace_back(p.second);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int ans=0,pre=INF;
    for (auto x:v){
        if (x<pre) ans+=x,pre=x;
        else if (1<pre) ans+=pre-1,--pre;
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n;
        for (int i=0;i<n;++i) cin >> a[i];
        solve();
    }
}