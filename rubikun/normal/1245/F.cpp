#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    
    while(T){
        ll L,R;cin>>L>>R;
        
        ll dp[40][2][2][2];
        
        memset(dp,0,sizeof(dp));
        
        dp[0][1][1][1]=1;
        
        for(int i=0;i<36;i++){
            
            dp[i+1][0][0][0]+=3*dp[i][0][0][0];
            dp[i+1][0][0][0]+=dp[i][0][0][1];
            dp[i+1][0][0][1]+=dp[i][0][0][1];
            
            if(L&(1LL<<(35-i))){
                if(R&(1LL<<(35-i))){
                    dp[i+1][1][0][0]+=dp[i][1][0][0];
                    
                    dp[i+1][0][0][0]+=2*dp[i][0][1][0];
                    dp[i+1][0][1][0]+=dp[i][0][1][0];
                    
                    dp[i+1][0][0][1]+=dp[i][0][1][1];
                    dp[i+1][0][1][0]+=dp[i][0][1][1];
                    
                    dp[i+1][1][0][0]+=dp[i][1][1][0];
                }else{
                    dp[i+1][1][0][0]+=dp[i][1][0][0];
                    
                    dp[i+1][0][1][0]+=2*dp[i][0][1][0];
                    
                    dp[i+1][0][1][1]+=dp[i][0][1][1];
                    
                    dp[i+1][1][1][0]+=dp[i][1][1][0];
                }
            }else{
                if(R&(1LL<<(35-i))){
                    dp[i+1][0][0][0]+=dp[i][1][0][0];
                    dp[i+1][1][0][0]+=2*dp[i][1][0][0];
                    
                    dp[i+1][1][0][0]+=dp[i][1][0][1];
                    dp[i+1][1][0][1]+=dp[i][1][0][1];
                    
                    dp[i+1][0][0][0]+=2*dp[i][0][1][0];
                    dp[i+1][0][1][0]+=dp[i][0][1][0];
                    
                    dp[i+1][0][0][1]+=dp[i][0][1][1];
                    dp[i+1][0][1][0]+=dp[i][0][1][1];
                    
                    dp[i+1][1][0][0]+=dp[i][1][1][0];
                    dp[i+1][0][0][0]+=dp[i][1][1][0];
                    dp[i+1][1][1][0]+=dp[i][1][1][0];
                    
                    dp[i+1][1][0][1]+=dp[i][1][1][1];
                    dp[i+1][1][1][0]+=dp[i][1][1][1];
                }else{
                    dp[i+1][1][0][0]+=2*dp[i][1][0][0];
                    dp[i+1][0][0][0]+=dp[i][1][0][0];
                    
                    dp[i+1][1][0][0]+=dp[i][1][0][1];
                    dp[i+1][1][0][1]+=dp[i][1][0][1];
                    
                    dp[i+1][0][1][0]+=2*dp[i][0][1][0];
                    
                    dp[i+1][0][1][1]+=dp[i][0][1][1];
                    
                    dp[i+1][0][1][0]+=dp[i][1][1][0];
                    dp[i+1][1][1][0]+=dp[i][1][1][0];
                    
                    dp[i+1][1][1][1]+=dp[i][1][1][1];
                }
            }
        }
        
        ll ans=0;
        
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    //if(dp[i][j][k][l]) cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;
                    ans+=dp[36][j][k][l];
                }
            }
        }
        if(L==0){
            if(R==0) cout<<1<<endl;
            else cout<<ans*2-1<<endl;
        }else cout<<ans*2<<endl;
        
        T--;
    }
}