#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=4e5+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;aN f;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline ll qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}int qmax(ll&a,ll&b,ll c){return c>a?b=a,a=c,2:c>b?b=c,1:0;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN next,head,to,dfn;ll cnt,top;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}void dfs(ll u,ll fa){dfn[++top]=u,f[u]=fa;rev(i,u,v)if(v^fa)dfs(v,u);}
ll query(ll s){pc('?'),pc(' ');writell(s);rep(i,1,s)writell(dfn[i]);return pc(10),fflush(stdout),readll();}void getans(ll a,ll b){pc('!'),pc(' '),writell(a),writell(b,10),fflush(stdout);}
int main(){ll n=readll(),u,v;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);dfs(1,0);ll l=2,r=n,g=query(n);
while(l<=r){ll mid=(l+r)>>1;if(query(mid)==g)r=mid-1;else l=mid+1;}getans(dfn[r+1],f[dfn[r+1]]);return 0;}
/*
6
5 6
1 5
2 4
2 3
1 2
*/