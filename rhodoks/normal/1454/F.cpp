#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

/*  									*/ 

//Segment_Tree  
//Segment_Tree<DataType>(int _l=0,int _r=MAXN)		  
//void Clear()	 									 
//void Build(DataType *a)							a 
//void Add(int L,int R,DataType x) 					 
//DataType Qmin(int L,int R) 						 
//DataType Qmax(int L,int R) 						 
//DataType Qsum(int L,int R) 						 
//void Output() 									 


#define MID ((l+r)>>1)
#define LS (pos<<1)
#define RS (pos<<1|1)
template <class DataType> 
class Segment_Tree
{
	int l,r;
	DataType *mx,*mi,*sum,*tag;
	DataType inf;
	
	void pushdown(int pos,int l,int r)
	{
		mx[LS]+=tag[pos];
		mx[RS]+=tag[pos];
		mi[LS]+=tag[pos];
		mi[RS]+=tag[pos];
		sum[LS]+=tag[pos]*(MID-l+1);
		sum[RS]+=tag[pos]*(r-MID);
		tag[LS]+=tag[pos];
		tag[RS]+=tag[pos];
		tag[pos]=0;
	}
	
	void pushup(int pos,int l,int r)
	{
		mi[pos]=min(mi[LS],mi[RS])+tag[pos];
		mx[pos]=max(mx[LS],mx[RS])+tag[pos];
		sum[pos]=sum[LS]+sum[RS]+tag[pos]*(r-l+1);
	}
	
	void build(int pos,int l,int r,DataType *a)
	{
		if (l==r)
		{
			mx[pos]=mi[pos]=sum[pos]=a[l];
			return;
		}
		build(LS,l,MID,a);
		build(RS,MID+1,r,a);
		pushup(pos,l,r);
	}
	
	void modify(int pos,int l,int r,int L,int R,DataType k)
	{
		if (r<L || l>R)
			return;
		if (l>=L && r<=R)
		{
			tag[pos]+=k;
			mx[pos]+=k;
			mi[pos]+=k;
			sum[pos]+=k*(r-l+1);
			return;
		}
		pushdown(pos,l,r);
		modify(LS,l,MID,L,R,k);
		modify(RS,MID+1,r,L,R,k);
		pushup(pos,l,r);
	}
	
	DataType querymi(int pos,int l,int r,int L,int R)
	{
		if (r<L || l>R)
			return inf;
		if (l>=L && r<=R)
			return mi[pos];
		pushdown(pos,l,r);
		return min(querymi(LS,l,MID,L,R),querymi(RS,MID+1,r,L,R));
	}
	
	DataType querymx(int pos,int l,int r,int L,int R)
	{
		if (r<L || l>R)
			return -inf;
		if (l>=L && r<=R)
			return mx[pos];
		pushdown(pos,l,r);
		return max(querymx(LS,l,MID,L,R),querymx(RS,MID+1,r,L,R));
	}
	
	DataType querysum(int pos,int l,int r,int L,int R)
	{
		if (r<L || l>R)
			return 0;
		if (l>=L && r<=R)
			return sum[pos];
		pushdown(pos,l,r);
		return querysum(LS,l,MID,L,R)+querysum(RS,MID+1,r,L,R);
	}
	
	void output(int pos,int l,int r)
	{
		if (l==r)
		{
			cout<<mx[pos]<<' ';
			return;
		}
		pushdown(pos,l,r);
		output(LS,l,MID);
		output(RS,MID+1,r);
	}
	
	public:
	void Clear()
	{
		for (int i=0;i<(r-l+5)<<2;i++)
			mx[i]=mi[i]=sum[i]=tag[i]=0;
	}
	
	Segment_Tree(int _l=0,int _r=MAXN)
	{
		memset(&inf,0x3f,sizeof(DataType));
		l=_l;
		r=_r;
		mx=new DataType[(r-l+5)<<2];
		mi=new DataType[(r-l+5)<<2];
		sum=new DataType[(r-l+5)<<2];
		tag=new DataType[(r-l+5)<<2];
		Clear();
	}
	
	~Segment_Tree()
	{
		delete mx;
		delete mi;
		delete sum;
		delete tag;
	}
	
	void Build(DataType *a)
	{
		build(1,l,r,a);
	}
	
	void Add(int L,int R,DataType x)
	{
		modify(1,l,r,L,R,x);
	}
	
	DataType Qmin(int L,int R)
	{
		return querymi(1,l,r,L,R);
	}
	
	DataType Qmax(int L,int R)
	{
		return querymx(1,l,r,L,R);
	}
	
	DataType Qsum(int L,int R)
	{
		return querysum(1,l,r,L,R);
	}
	
	void Output()
	{
		output(1,l,r);
	}
};


/*  									*/ 

int n;
int a[MAXN];
int mx1[MAXN];
int mx2[MAXN];
void work()
{
	scanf("%d",&n);
	Segment_Tree<int> sgt(1,n);
	for (int i=1;i<=n;i++)
	{
		mx1[i]=mx2[i]=0;
		scanf("%d",&a[i]);
		sgt.Add(i,i,a[i]);
	}
	mx1[0]=mx2[n+1]=0;
	for (int i=1;i<=n;i++)
		mx1[i]=max(a[i],mx1[i-1]);
	for (int i=n;i>=1;i--)
	{
		mx2[i]=max(a[i],mx2[i+1]);
		WRT(mx2[i])
	}
	for (int i=2;i<=n-1;i++)
	{
		WRT(i)
		int l=upper_bound(mx1,mx1+n+1,a[i])-mx1-1;
		WRT(l)
		if (l>=i)
			l=i-1;
		if (l<=0 || mx1[l]!=a[i])
			continue;
		int r=lower_bound(mx2+1,mx2+n+2,a[i],greater<int>())-mx2;
		if (r<=i)
			r=i+1;
		if (r>=n+1 || mx2[r]!=a[i])
			continue;
		WRT(r)
		if (sgt.Qmin(l+1,r-1)==a[i])
		{
			
			printf("YES\n%d %d %d\n",l,r-l-1,n-r+1);
			return;
		}
	}
	printf("NO\n");
}
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}