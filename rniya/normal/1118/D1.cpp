#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; ll m; cin >> n >> m;
    vector<ll> a(n); cin >> a;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int lb=0,ub=n+1;
    while(ub-lb>1){
        int mid=(ub+lb)>>1;
        ll sum=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        for (int i=0;i<mid;++i) pq.emplace(0,IINF);
        for (int i=0;i<n;++i){
            while(!pq.empty() and !(a[i]>pq.top().first)) pq.pop();
            if (pq.empty()) break;
            auto p=pq.top(); pq.pop();
            sum+=a[i]-p.first; ++p.first;
            p.second=min(a[i],p.second-1);
            if (p.second>1) pq.emplace(p);
        }
        (m<=sum?ub:lb)=mid;
    }
    cout << (ub==n+1?-1:ub) << '\n';
}