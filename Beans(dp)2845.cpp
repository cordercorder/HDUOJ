# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=2e5+10;

int n,m;
int a[maxn],dp[maxn];
int row[maxn];

int main(void){
	while(scanf("%d %d",&m,&n)!=EOF){
		for(int i=1;i<=m;i++){
			dp[0]=0;
			for(int j=1;j<=n;j++){
				scanf("%d",&a[j]);
				if(j>=2){
					dp[j]=max(dp[j-1],dp[j-2]+a[j]);
				}
				else{
					dp[j]=a[j];
				}
			}
			row[i]=dp[n];
		}
		dp[0]=0;
		dp[1]=row[1];
		for(int i=2;i<=m;i++){
			dp[i]=max(dp[i-1],dp[i-2]+row[i]);
		}
		printf("%d\n",dp[m]);
	}
	return 0;
}
