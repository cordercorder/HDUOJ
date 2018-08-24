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

const int maxn=1e2+10;

int sum[maxn][maxn];
int a[maxn][maxn];
int n;

void solve(){
	int ans=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=i;k<=n;k++){
				for(int l=j;l<=n;l++){
					ans=max(ans,sum[k][l]-sum[k-i][l]-sum[k][l-j]+sum[k-i][l-j]);
					//printf("ans==%d\n",ans);
				}	
			}
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				sum[i][j]=a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		}
		solve();
	}
	return 0;
}
