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

const int maxn=1e2+10;

int n,m;

int p[maxn],h[maxn],c[maxn];
int t;
int dp[maxn];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++){
		for(int j=n;j>=p[i];j--){
			for(int k=0;k<=c[i]&&j>=k*p[i];k++){
				dp[j]=max(dp[j],dp[j-k*p[i]]+k*h[i]);
			}
		}
	}
	printf("%d\n",dp[n]);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&p[i],&h[i],&c[i]);
		}
		solve(); 
	}
	return 0;
}
