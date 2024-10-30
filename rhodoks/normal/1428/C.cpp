#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

string s;

void work()
{
	int cnt[3]={0,0,0};
	cin>>s;
	int ptrA=s.size()-1;
	int ptrB=s.size()-1;
	while (1)
	{
		while (ptrB>=0 && s[ptrB]!='B' && ptrB>=0)
			ptrB--;
		while (ptrA>=0 && (s[ptrA]!='A' || ptrA>=ptrB))
			ptrA--;
		if (ptrA<0 || ptrB<0)
			break;
		//cout<<ptrA<<' '<<ptrB<<endl;
		if (ptrA>=0)
			s[ptrA]=s[ptrB]='C';
		ptrA--;
		ptrB--;
	}
	for (int i=0;i<s.size();i++)
	{
		cnt[s[i]-'A']++;
		//putchar(s[i]);
	}
	//cout<<endl;
	cnt[1]%=2;
	printf("%d\n",cnt[0]+cnt[1]); 
}

int main()
{
	int t;
	cin>>t;
	while (t--)
		work(); 
	return ~~(0^_^0);
}