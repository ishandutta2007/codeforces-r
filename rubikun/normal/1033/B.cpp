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
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll a,b;cin>>a>>b;
        if(a-b==1){
            bool ok=true;
            for(ll i=2;i*i<=a+b;i++){
                if((a+b)%i==0) ok=false;
            }
            if(ok) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}