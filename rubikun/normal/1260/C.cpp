#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    while(N){
        ll A,B,K;cin>>A>>B>>K;
        ll g=gcd(A,B);
        A/=g;
        B/=g;
        if(A==B) cout<<"OBEY\n";
        else{
            if(A>B) swap(A,B);
            ll n=(B-2)/A;
            if(n>=K-1) cout<<"REBEL\n";
            else cout<<"OBEY\n";
        }
        
        N--;
    }
}