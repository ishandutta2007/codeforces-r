#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;

int dep[N],cnt[N];
int n,ans;

int main(){
	n=IN();
	For(i,2,n+1){
		dep[i]=dep[IN()]+1;
	}
	For(i,1,n+1) cnt[dep[i]]++;
	For(i,0,N) if (cnt[i]&1) ans++;
	printf("%d\n",ans);
}