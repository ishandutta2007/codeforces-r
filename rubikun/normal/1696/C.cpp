#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,K,M;cin>>N>>K;
        vector<pair<ll,ll>> A,B;
        for(int i=0;i<N;i++){
            ll x;cin>>x;
            ll cn=1;
            while(x%K==0){
                x/=K;
                cn*=K;
            }
            if(!A.empty()&&A.back().fi==x){
                A.back().se+=cn;
            }else{
                A.push_back(mp(x,cn));
            }
        }
        cin>>M;
        for(int i=0;i<M;i++){
            ll x;cin>>x;
            ll cn=1;
            while(x%K==0){
                x/=K;
                cn*=K;
            }
            if(!B.empty()&&B.back().fi==x){
                B.back().se+=cn;
            }else{
                B.push_back(mp(x,cn));
            }
        }
        
        if(A==B) cout<<"Yes\n";
        else cout<<"No\n";
    }
}