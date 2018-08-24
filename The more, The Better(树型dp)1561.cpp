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

const int maxn=2e2+10;

vector<int> p[maxn]; 
int n,m;
int dp[maxn][maxn];//当前i节点及其子树下最多选择j个城市的最大值为dp[i][j]

void solve(int x){
	int res;
	for(int i=0;i<p[x].size();i++){
		res=p[x][i];
		if(p[res].size()>0)
			solve(res);
		for(int j=m;j>1;j--){
			for(int k=1;k<j;k++){
				dp[x][j]=max(dp[x][j],dp[x][k]+dp[res][j-k]);
			}
		}
	}
}

int main(void){
	int a,b;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		m++;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a,&b);
			p[a].push_back(i);
			for(int j=1;j<=m;j++){
				dp[i][j]=b;
			}
		}
		solve(0);
		printf("%d\n",dp[0][m]);
		for(int i=0;i<=200;i++)
			p[i].clear();
	}
	return 0;
}
