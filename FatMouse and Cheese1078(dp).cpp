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

const int maxn=1e2+10;

int a[maxn][maxn];
int n,k;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dp[maxn][maxn];

int solve(int x,int y){
	if(dp[x][y]>=0)
		return dp[x][y];
	int nx,ny;
	int res=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<4;j++){
			nx=x+dx[j]*i;
			ny=y+dy[j]*i;
			if(nx>=0&&nx<n&&ny>=0&&ny<n&&a[nx][ny]>a[x][y]){
				res=max(res,solve(nx,ny));
			}
		}
	}
	dp[x][y]=res+a[x][y];
	return dp[x][y];
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		if(n==-1&&k==-1)
			break;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(0,0));
	}
	return 0;
}
