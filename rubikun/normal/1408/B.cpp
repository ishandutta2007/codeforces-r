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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        set<int> SE;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            SE.insert(A[i]);
        }
        
        if(K==1){
            if(si(SE)==1) cout<<1<<"\n";
            else cout<<-1<<"\n";
        }else{
            int X=si(SE);
            X-=K;
            if(X<=0) cout<<1<<"\n";
            else{
                cout<<1+(X+K-2)/(K-1)<<"\n";
            }
        }
    }
}