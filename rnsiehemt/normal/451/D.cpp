#include <cstdio>

char s[100005];
long long c[2][2], o;

int main()
{
    scanf(" %s", s);
    for (int i = 0; s[i]; i++)
        c[s[i]-'a'][i%2]++;
    o = (c[0][0]*(c[0][0]+1) + c[1][0]*(c[1][0]+1) + c[0][1]*(c[0][1]+1) + c[1][1]*(c[1][1]+1)) / 2;
    printf("%I64d %I64d\n", ((c[0][0]+c[0][1])*(c[0][0]+c[0][1]+1) + (c[1][0]+c[1][1])*(c[1][0]+c[1][1]+1))/2 - o, o);
}