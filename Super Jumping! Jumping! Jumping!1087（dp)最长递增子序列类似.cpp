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

const int maxn=1e3+10;

int a[maxn];
int dp[maxn];
int n;

void solve(){
	int ans=INT_MIN; 
	for(int i=1;i<=n;i++){
		dp[i]=a[i];
		for(int j=1;j<i;j++){
			if(a[j]<a[i])
				dp[i]=max(dp[i],dp[j]+a[i]);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
