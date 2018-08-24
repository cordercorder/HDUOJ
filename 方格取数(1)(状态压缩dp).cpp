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

const int maxn=30;

int n;
int a[maxn][maxn];
int status[(1<<20)+1],cnt;
int dp[25][(1<<20)+1];

int sum(int row,int x){
	int ans=0,pos=0;
	int res=status[x];
	while(res){
		if(res&1){
			ans+=a[row][pos];
		}
		res>>=1;
		pos++;
	}
	return ans;
}

void solve(){
	int ans=0,Max;
	for(int i=0;i<cnt;i++){
		dp[0][i]=sum(0,i);
		ans=max(dp[0][i],ans);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<cnt;j++){
			Max=0;
			for(int k=0;k<cnt;k++){
				if((status[j]&status[k])==0){
					Max=max(dp[i-1][k],Max);
				}
			}
			dp[i][j]=Max+sum(i,j);
			ans=max(dp[i][j],ans);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		}
		cnt=0;
		for(int i=0;i<(1<<n);i++){
			if((i&(i>>1))==0){
				status[cnt++]=i;
			}
		}
		solve();
	}
	return 0;
}
