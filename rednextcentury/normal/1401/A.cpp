/*
______     _   _                               _                
| ___ \   | | (_)                             | |               
| |_/ /___| |_ _ _ __ ___ _ __ ___   ___ _ __ | |_              
|    // _ \ __| | '__/ _ \ '_ ` _ \ / _ \ '_ \| __|             
| |\ \  __/ |_| | | |  __/ | | | | |  __/ | | | |_              
\_| \_\___|\__|_|_|  \___|_| |_| |_|\___|_| |_|\__|             
 
 
 _____      _   _       _      ___  _ _                       _ 
|_   _|    | \ | |     | |    / _ \| | |                     | |
  | | ___  |  \| | ___ | |_  / /_\ \ | | _____      _____  __| |
  | |/ __| | . ` |/ _ \| __| |  _  | | |/ _ \ \ /\ / / _ \/ _` |
 _| |\__ \ | |\  | (_) | |_  | | | | | | (_) \ V  V /  __/ (_| |
 \___/___/ \_| \_/\___/ \__| \_| |_/_|_|\___/ \_/\_/ \___|\__,_|
 
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
      ll n,k;
      cin>>n>>k;
      if (k>n) cout<<k-n<<endl;
      else if (n%2!=k%2) cout<<1<<endl;
      else cout<<0<<endl;
    }
}