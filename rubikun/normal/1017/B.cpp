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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string A,B;cin>>A>>B;
    vector<ll> cnt(4);
    
    for(int i=0;i<N;i++){
        cnt[int(A[i]-'0')*2+int(B[i]-'0')]++;
    }
    
    ll ans=0;
    
    ans=cnt[0]*(cnt[2]+cnt[3])+cnt[1]*cnt[2];
    
    cout<<ans<<endl;
}