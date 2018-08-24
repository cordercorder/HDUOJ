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

int t;
int n,m,x,y;
int a[maxn][maxn];
int sum[maxn][maxn];

void solve(){
	int ans=INT_MIN,tmp;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	for(int i=1;i<=m-x+1;i++){
		for(int j=1;j<=n-y+1;j++){
			tmp=sum[i+x-1][j+y-1]-sum[i+x-1][j-1]-sum[i-1][j+y-1]+sum[i-1][j-1];
			ans=max(ans,tmp);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d %d %d",&m,&n,&x,&y);
			memset(sum,0,sizeof(sum));
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					scanf("%d",&a[i][j]);
					sum[i][j]=a[i][j];
				}
			}
			solve();
		}
	}
	return 0;
}
