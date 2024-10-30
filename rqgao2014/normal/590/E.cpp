#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=755,M=10000005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

queue<int> q;
int n,ans,mx[N],my[N],__end[N];
bool g[N][N],vis[N],mark[N][2];
int cnt,a[M][2],p[M],fail[M],tag[M];
char str[M];

bool dfs(int x){
	for(int y=1;y<=n;y++){
		if(vis[y]||!g[x][y]) continue;
		vis[y]=1;
		if(!my[y]||dfs(my[y])){
			my[y]=x;mx[x]=y;
			return 1;
		}
	}
	return 0;
}
void dfs(int x,int k){
	if(mark[x][k]) return;
	mark[x][k]=1;
	if(k) dfs(my[x],0); else{
		for(int y=1;y<=n;y++)
			if(g[x][y]) dfs(y,1);
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++){
		reads(str);
		int l=strlen(str),k=0;
		for(int j=0;j<l;j++){
			if(!a[k][str[j]-'a']) a[k][str[j]-'a']=++cnt,p[cnt]=k;
			k=a[k][str[j]-'a'];
		}
		tag[k]=i;__end[i]=k;
	}
	q.push(0);
	while(!q.empty()){
		int k=q.front();q.pop();
		if(!tag[k]) tag[k]=tag[fail[k]];
		for(int c=0;c<2;c++){
			if(!a[k][c]) continue;
			q.push(a[k][c]);
			if(!k){fail[a[k][c]]=0;continue;}
			int t=fail[k];
			while(t&&!a[t][c]) t=fail[t];
			fail[a[k][c]]=a[t][c];
		}
	}
	for(int i=1;i<=n;i++){
		int k=__end[i];
		while(k)
			g[i][tag[k]]=1,g[i][tag[fail[k]]]=1,k=p[k];
		g[i][i]=0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]|=g[i][k]&&g[k][j];
				
	for(int i=1;i<=n;i++,dprintf("\n"))
		for(int j=1;j<=n;j++)
			dprintf("%d",g[i][j]);
	for(int i=1;i<=n;i++)
		clr(vis,0),ans+=dfs(i);
	for(int i=1;i<=n;i++)
		if(!mx[i]) dfs(i,0);
	printf("%d\n",n-ans);
	for(int i=1;i<=n;i++)
		if(mark[i][0]&&!mark[i][1]) printf("%d ",i);
	puts("");
	return 0;
}