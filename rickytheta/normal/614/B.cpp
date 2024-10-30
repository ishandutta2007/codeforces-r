#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

int main(){
  int n;
  cin>>n;
  string nonb = "1";
  int zeros = 0;
  REP(_,n){
    string s;
    cin>>s;
    if(s=="0"){
      zeros = -1;
      break;
    }
    // check beautiful
    bool flag = false;
    if(s[0]=='1'){
      flag = true;
      REPR(i,s.size()){
        if(s[i]!='0'){
          flag = false;
          break;
        }
      }
    }
    if(flag){
      zeros += s.size()-1;
    }else{
      nonb = s;
    }
  }
  if(zeros == -1){
    cout<<0<<endl;
  }else{
    cout<<nonb;
    REP(i,zeros)cout<<0;
    cout<<endl;
  }
  return 0;
}