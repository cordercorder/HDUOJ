#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e3+10;

char a[maxn][maxn];
int n;
int dp[maxn][maxn];

void solve(){
	int r,c;
	int ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1){
				dp[i][j]=1;
				ans=max(ans,dp[i][j]);
				continue;
			}
			r=i;
			c=j;
			while(r>=1&&j<=n&&a[r][j]==a[i][c]){
				--r;
				++c;
			}
			r=i-r;
			if(r>dp[i-1][j+1]){
				dp[i][j]=dp[i-1][j+1]+1;
			}
			else{
				dp[i][j]=r;
			}
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		solve();
	}
	return 0;
}
