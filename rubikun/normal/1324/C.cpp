#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<20;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        S+='R';
        int mi=1;
        
        int la=0;
        
        for(int i=0;i<S.size();i++){
            if(S[i]=='R'){
                mi=max(mi,i+1-la);
                la=i+1;
            }
        }
        
        cout<<mi<<"\n";
    }
}