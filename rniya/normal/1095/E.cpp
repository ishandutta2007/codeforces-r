#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
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

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; string S; cin >> n >> S;
    vector<int> v(n,0),sum(n+1,0);
    for (int i=0;i<n;++i) v[i]=(S[i]=='('?1:-1);
    for (int i=0;i<n;++i) sum[i+1]=sum[i]+v[i];
    vector<int> left(n+1,INF),right(n+1,INF);
    left[0]=sum[0],right[n]=sum[n];
    for (int i=1;i<=n;++i) left[i]=min(left[i-1],sum[i]);
    for (int i=n-1;i>=0;--i) right[i]=min(right[i+1],sum[i]);
    int ans=0;
    for (int i=0;i<n;++i){
        if (sum[n]-v[i]*2) continue;
        ans+=(left[i]>=0&&right[i+1]-v[i]*2>=0);
    }
    cout << ans << '\n';
}