#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,z,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&z);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ans=max(ans,a[i]|z);
        }
        printf("%d\n",ans);
    }
    return 0;
}