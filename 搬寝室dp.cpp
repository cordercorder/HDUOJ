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

const int maxsize=2e3+10;

const ll maxw=1e9+10;

int a[maxsize];
int n,k;
int dp[maxsize][maxsize];

int solve(int x,int sum){
	if(sum==2*k)
		return 0;
	if(x>=n)
		return maxw;
	if(dp[x][sum]>=0)
		return dp[x][sum];
	int res1,res2;
	res1=solve(x+2,sum+2)+(a[x]-a[x+1])*(a[x]-a[x+1]);
	res2=solve(x+1,sum);
	//cout<<"res1=="<<res1<<endl;
	//cout<<"res2=="<<res2<<endl;
	return dp[x][sum]=min(res1,res2);
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		for(ll i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(1,0));
	}
	return 0;
}
