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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e2+10;
const int maxw=1e9+10;

int t;
int E,F;
int N;
int P[maxn],W[maxn];
int dp[10000+10];

void solve(){
	int res=F-E;
	for(int i=0;i<=res;i++){
		dp[i]=maxw;
	}
	dp[0]=0;
	for(int i=1;i<=N;i++){
		for(int j=W[i];j<=res;j++){
			dp[j]=min(dp[j],dp[j-W[i]]+P[i]);
		}
	}
	if(dp[res]==maxw){
		puts("This is impossible.");
		return ;
	}
	printf("The minimum amount of money in the piggy-bank is %d.\n",dp[res]);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&E,&F,&N);
		for(int i=1;i<=N;i++){
			scanf("%d %d",&P[i],&W[i]);
		}
		solve();
	}
	return 0;
}
