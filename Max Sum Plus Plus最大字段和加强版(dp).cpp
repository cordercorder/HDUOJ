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

const int maxn=1e6+10;

ll n,m;
ll a[maxn];
ll dp[2][maxn];
ll sum[maxn];

void solve(){
	ll Max,ans=INT_MIN;
	for(ll i=1;i<=m;i++){
		Max=INT_MIN;
		for(ll j=i;j<=n;j++){
			Max=max(Max,dp[(i-1)%2][j-1]);
			if(i==j){
				dp[i%2][j]=sum[j];
			}
			else{
				dp[i%2][j]=max(dp[i%2][j-1]+a[j],Max+a[j]);
			}
		}
	}
	for(ll i=m;i<=n;i++){
		ans=max(ans,dp[m%2][i]);
	}
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%lld %lld",&m,&n)!=EOF){
		sum[0]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		memset(dp,0,sizeof(dp));
		solve();
	}
	return 0;
}
