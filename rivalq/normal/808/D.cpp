#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 int n;cin>>n;
 int a[n+1];
 int sum=0;
 rep3(n)cin>>a[i+1],sum+=a[i+1];
 if(sum&1){
 	cout<<"NO"<<endl;return 0;
 }
 map<int,int>s1,s2;
 rep(i,1,n+1)s2[a[i]]++;
 int sum2=0;
 rep(i,1,n+1){
 	sum2+=a[i];
 	sum-=a[i];
 	s1[a[i]]++;
 	s2[a[i]]--;
 	if(sum==sum2){
 		cout<<"YES"<<endl;return 0;
 	}
 	int s=abs(sum-sum2);
 	if(s%2==0){
 		if(sum>sum2 && s2[s/2]>0){
 			cout<<"YES"<<endl;return 0;
 		}
 		if(sum<sum2 && s1[s/2]>0){
 			cout<<"YES"<<endl;return 0;
 		}
 	}
 }
 cout<<"NO"<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef sieve
    sieve();
    #endif
    #ifdef ncr
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}