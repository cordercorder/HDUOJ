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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

int t;
int n;
int a[maxsize];
int dp[maxsize];

void solve(){
	int i,ans=-1e9-10;
	int l=0,r=0;
	dp[0]=a[0];
	for(i=1;i<n;i++){
		if(dp[i-1]>=0){
			dp[i]=dp[i-1]+a[i];
		}
		else{
			dp[i]=a[i];
		}
	}
	for(i=0;i<n;i++){
		if(dp[i]>ans){
			r=i;//end position
			ans=dp[i];
		}
	}
	i=r;
	while(i>=0&&dp[i]>=0)
		i--;
	l=ans<0?r:i+1;
	printf("%d %d %d\n",ans,l+1,r+1);
}

int main(void){
	int i,sum;
	while(scanf("%d",&t)!=EOF){
		sum=0;
		while(t--){
			scanf("%d",&n);
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			sum++;
			printf("Case %d:\n",sum);
			solve();
			if(t) 
				printf("\n");
		}
	}
	return 0;
}
