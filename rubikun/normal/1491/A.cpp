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
    
    int N,Q;cin>>N>>Q;
    vector<int> A(N);
    int cnt=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]) cnt++;
    }
    
    while(Q--){
        int t,x;cin>>t>>x;
        if(t==1){
            x--;
            if(A[x]) cnt--;
            else cnt++;
            A[x]=1-A[x];
        }else{
            if(cnt>=x) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
}