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
        int N,K;cin>>N>>K;
        vector<ll> A(N);
        vector<pair<ll,int>> B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            B[i]=mp(A[i]-(N-1-i),i);
        }
        sort(all(B));
        reverse(all(B));
        
        vector<int> dont(N);
        for(int i=0;i<K;i++){
            dont[B[i].se]=true;
        }
        
        ll ans=0,cn=0;
        
        for(int i=0;i<N;i++){
            if(dont[i]) cn++;
            else ans+=A[i]+cn;
        }
        
        cout<<ans<<"\n";
    }
}