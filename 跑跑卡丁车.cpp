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

typedef long long ll;

using namespace std;

const int maxsize=1e4+10;

const int maxw=1e5+10; 

int n,l;
int num;
int a[maxsize],b[maxsize];
int dp[maxsize][20];

void solve(){
	int i,j,ans;
	for(i=0;i<maxsize;i++){//初始化数组 
		for(j=0;j<20;j++){
			dp[i][j]=maxw;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n*l;i++){
		for(j=0;j<15;j++){
			if(j)
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a[i]);//不使用加速卡 
			if(j<10)
				dp[i][j]=min(dp[i][j],dp[i-1][j+5]+b[i]);//使用加速卡 
			if(j==10)
				dp[i][j]=min(dp[i][j],dp[i-1][14]+a[i]);
			printf("%-8d",dp[i][j]);
		}
		printf("\n");
	}
	ans=dp[l*n][0];
	for(i=1;i<15;i++){
		ans=min(ans,dp[l*n][i]);
	}
	printf("%d\n",ans);
} 

int main(void){
	int i,j;
	while(scanf("%d %d",&l,&n)!=EOF){
		for(i=1;i<=l;i++){
			scanf("%d",&a[i]);
			for(j=1;j<=n;j++){
				a[i+j*l]=a[i];
			}
		}
		for(i=1;i<=l;i++){
			scanf("%d",&b[i]);
			for(j=1;j<=n;j++){
				b[i+j*l]=b[i];
			}
		}
		solve();
	}
	return 0;
}
