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

const int maxsize=1e2+10;

int t,n,m;
int p[maxsize],h[maxsize],c[maxsize];
int dp[maxsize][maxsize][30]; 

int solve(int x,int y,int sum){
	if(x>m)
		return 0;
	if(dp[x][y][sum]>=0)
		return dp[x][y][sum];
	int res1,res2;
	if(y>=p[x]){
		if(sum<c[x]){
			res1=solve(x,y-p[x],sum+1)+h[x];
			res2=solve(x+1,y,0);
		}
		else{
			res1=solve(x+1,y,0);
			res2=0;
		}
	}
	else{
		res1=solve(x+1,y,0);
		res2=0;
	}
	return dp[x][y][sum]=max(res1,res2);
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d",&n,&m);
			for(int i=1;i<=m;i++)
				scanf("%d %d %d",&p[i],&h[i],&c[i]);
			memset(dp,-1,sizeof(dp));
			printf("%d\n",solve(1,n,0));
		}
	}
	return 0;
}
