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
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e2+10;

int n,m;
int cnt;
int dp[maxn];
int num[maxn][maxn];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			for(int k=1;k<=j;k++){
				dp[j]=max(dp[j],dp[j-k]+num[i][k]);
			}
		}
	}
	printf("%d\n",dp[m]);
}

int main(void){
	int tmp;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(m==0&n==0)
			break;
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&num[i][j]);
			}
		}
		solve();
	}
	return 0;
}
