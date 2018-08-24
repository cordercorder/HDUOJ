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
//#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e3+10;

int t;
int n,v;
int w[maxn],val[maxn];
bool path[maxn][maxn];
vector<int> p;
int dp[maxn];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=v;j>=w[i];j--){
			if(dp[j]<=dp[j-w[i]]+val[i]){
				path[i][j]=1;
				dp[j]=dp[j-w[i]]+val[i];
			}
		}
	}
	printf("%d\n",dp[v]);
	#ifdef DEBUG
	for(int i=1;i<=n;i++){
		for(int j=0;j<=v;j++){
			cout<<path[i][j]<<" ";
		}
		printf("\n");
	}
	int i=n,j=v;
	while(i>0&&j>=0){
		if(path[i][j]){
			j-=w[i];
			p.push_back(i);
		}
		i--;
	}
	for(int i=0;i<(int)p.size();i++){
		printf("%d ",p[i]);
	}
	#endif
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&v);
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
		}
		solve();
	}
	return 0;
}
