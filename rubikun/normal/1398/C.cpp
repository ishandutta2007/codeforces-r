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
        int N;cin>>N;
        string S;cin>>S;
        vector<int> A(N+1);
        for(int i=1;i<=N;i++){
            A[i]=A[i-1]+int(S[i-1]-'0')-1;
        }
        map<int,int> MA;
        
        ll ans=0;
        
        for(int i=0;i<=N;i++){
            ans+=MA[A[i]];
            MA[A[i]]++;
        }
        cout<<ans<<"\n";
    }
}