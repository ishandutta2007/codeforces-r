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
    
    string S;cin>>S;
    int N;cin>>N;
    vector<string> T(N);
    for(int i=0;i<N;i++) cin>>T[i];
    
    bool ok=false;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            string U=T[i]+T[j];
            for(int k=0;k+1<si(U);k++){
                string X;
                X+=U[k];
                X+=U[k+1];
                if(X==S) ok=true;
            }
        }
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}