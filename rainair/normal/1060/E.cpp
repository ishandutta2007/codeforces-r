#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define RFOR(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

namespace fastIO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(ll &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 
using namespace fastIO;
#define int long long

const int MAXN = 200000 + 5;

struct Node{
	struct Edge *firstEdge;
	LL size;bool vis,used;
	LL f,dist;
	LL dp1,dp2;
}node[MAXN];

struct Edge{
	Node *s,*t;
	struct Edge *next;
}pool[MAXN*2],*frog = pool;

Edge *New(Node *s,Node *t){
	Edge *ret = ++frog;
	ret->s = s;ret->t = t;
	ret->next = s->firstEdge;
	return ret;
}

inline void add(int u,int v){
	node[u].firstEdge = New(&node[u],&node[v]);
	node[v].firstEdge = New(&node[v],&node[u]);
}
LL ans = 0ll;
int N;
void dfs1(Node *v){
	v->vis = true;
	v->size = 1;
	for(Edge *e = v->firstEdge;e;e = e->next){
		if(!e->t->vis){
			e->t->dist = v->dist + 1;
			dfs1(e->t);
			v->size += e->t->size;
			v->f += e->t->f + e->t->size * (N - e->t->size);
		}
	}
}

signed main(){
	read(N);
	FOR(i,1,N-1){
		int u,v;read(u);read(v);
		add(u,v);
	}
	dfs1(&node[1]);
	LL a = 0,b = 0;//DEBUG(node[1].f);
	FOR(i,1,N){
		if(node[i].dist & 1) a++;
		else b++;
	}
	LL sum = a * b;
	printf("%I64d\n",(node[1].f + sum + 1)/2);
	return 0;
}
// 2 3
// 2 3
// (f2[r]-f2[l]) <= x/(f1[r]-f1[l])
// 25
// 4 6
// 6 9