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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e3+10;

int t;
int n,m;
int val[maxsize],v[maxsize];
int dp[maxsize][maxsize];

int solve(int x,int y){
	if(x>n)
		return 0;
	if(dp[x][y]>=0)
		return dp[x][y];
	int res1,res2;
	if(y>=v[x]){
		res1=solve(x+1,y-v[x])+val[x];
		res2=solve(x+1,y);
	}
	else{
		res1=solve(x+1,y);
		res2=0;
	}
	return dp[x][y]=max(res1,res2);
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;i++)
				scanf("%d",&val[i]);
			for(int i=1;i<=n;i++)
				scanf("%d",&v[i]);
			memset(dp,-1,sizeof(dp));
			printf("%d\n",solve(1,m));
		}
	}
	return 0;
}
