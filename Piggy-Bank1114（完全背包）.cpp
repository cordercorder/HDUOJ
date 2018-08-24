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

const int maxsize=5e2+10;
const int maxw=1e7+10;

int t;
int E,F;
int m;
int n;
int val[maxsize],w[maxsize];
int dp[510][10010];

int solve(int x,int y){
	if(y==0)
		return 0;
	if(x>n)
		 return maxw;
	if(dp[x][y]>=0)
		return dp[x][y];
	int res1,res2;
	if(y>=w[x]){
		res1=solve(x,y-w[x])+val[x];
		res2=solve(x+1,y);
		return dp[x][y]=min(res1,res2);
	}
	else{
		res1=solve(x+1,y);
		return dp[x][y]=res1;
	}
}

int main(void){
	int ans;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d",&E,&F);
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d %d",&val[i],&w[i]);
			m=F-E;
			memset(dp,-1,sizeof(dp));
			ans=solve(1,m);
			if(ans==maxw){
				puts("This is impossible.");
				continue;
			}
			printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
		}
	}
	return 0;
}
