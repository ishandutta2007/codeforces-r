#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll x=0,y=0;
    
    for(int i=0;i<2*N;i++){
        ll a,b;cin>>a>>b;
        x+=a;
        y+=b;
    }
    
    cout<<x/(N)<<" "<<y/(N)<<endl;
}