#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool f=false;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=2;i<=n;i++)
        {
            if(max(a[i]-a[i-1],a[i-1]-a[i])>=2)
            {
                f=true;
                puts("YES");
                printf("%d %d\n",i-1,i);
                break;
            }
        }
        if(!f) puts("NO");
    }
    return 0;
}