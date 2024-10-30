#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;

int main(){
	n=readint();
	vector<int> ans(0);
	for(int i=n-90;i<=n;i++){
		int x=i,num=i;
		while(x) num+=x%10,x/=10;
		if(num==n) ans.pb(i);
	}
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d\n",r);
	return 0;
}