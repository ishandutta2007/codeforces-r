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
long double dis(long double x1,long double y1,long double x2,long double y2){
	       return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int solve(){
 long double a,b,c;cin>>a>>b>>c;
 long double x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
 long double d=abs(x1-x2)+abs(y1-y2);
 long double d1=1e18,d2=1e18,d3=1e18,d4=1e18;
 if(a!=0){
 	long double xn=(-b*y1-c)/a;
 	long double yn=y1;
 	long double xn2=(-b*y2-c)/a;
 	long double yn2=y2;
 	d1=abs(xn-x1)+abs(xn2-x2)+dis(xn,yn,xn2,yn2);
 }
 if(b!=0){
 	long double yn=(-a*x1-c)/b;
 	long double xn=x1;
 	long double yn2=(-a*x2-c)/b;
 	long double xn2=x2;
 	d2=abs(yn-y1)+abs(yn2-y2)+dis(xn,yn,xn2,yn2);
 }
 if(a!=0 && b!=0){
 	long double yn=(-a*x1-c)/b;
 	long double xn=x1;
 	long double xn2=(-b*y2-c)/a;
 	long double yn2=y2;
 	d3=abs(yn-y1)+abs(xn2-x2)+dis(xn,yn,xn2,yn2);
 }
 if(a!=0 && b!=0){
 	long double xn=(-b*y1-c)/a;
 	long double yn=y1;
 	long double yn2=(-a*x2-c)/b;
 	long double xn2=x2;
 	d4=abs(xn-x1)+abs(yn2-y2)+dis(xn,yn,xn2,yn2);
 }
 cout<<fixed<<setprecision(12);
 //cout<<d<<" "<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
 cout<<min({d1,d,d2,d3,d4})<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}