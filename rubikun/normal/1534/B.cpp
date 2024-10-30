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
        vector<ll> A(N+2);
        for(int i=0;i<N;i++) cin>>A[i+1];
        ll sum=0;
        for(int i=1;i+1<si(A);i++){
            if(A[i]>A[i-1]&&A[i]>A[i+1]){
                sum+=A[i]-max(A[i-1],A[i+1]);
                A[i]=max(A[i-1],A[i+1]);
            }
        }
        for(int i=0;i+1<si(A);i++){
            sum+=abs(A[i]-A[i+1]);
        }
        
        cout<<sum<<"\n";
    }
}