// LUOGU_RID: 90440962
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n; 

int main()
{
	cin>>n;
	if(n <= 1) cout<<-1<<endl;
	else cout<<n<<" "<<n+1<<" "<<n*(n+1)<<endl;
	return 0;
}