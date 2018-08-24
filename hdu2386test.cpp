#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 200005;
char a[N];
int next[N],d[N];
void get_next(char *b)
{
    int i = -1, j = 0;
    next[0] = -1;
    int len = strlen(b);
    while(j < len)
    {
        if(i == -1 || b[i] == b[j])
            next[++j] = ++i;
        else
            i = next[i];
    }
}
int main()
{
    int T,i,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&n,a);
        get_next(a);
        for(i = 1; i <= n; i ++)
            d[i] = 1;
        d[0] = 0;
        int sum = 0;
        for(i = 1; i <= n; i ++)
        {
            d[i] = d[next[i]] + 1;
            sum += d[i]%10007;
        }
        printf("%d\n",sum%10007);
    }
    return 0;
}
