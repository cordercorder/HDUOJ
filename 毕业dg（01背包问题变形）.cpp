# include<iostream>
# include<algorithm>
# include<cstring>
# include<cstdlib>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

# define ll long long 

using namespace std;

const int maxsize=1e5;

struct node{
	int w;
	int d;
	int l;
	bool operator<(const node &a)const{
		return this->l<a.l;
	}
};

int n;
int dp[maxsize];
node p[35];

void solve(){
	int i,j,ans=0;
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++){
		for(j=p[i].l;j>=p[i].d;j--){
			dp[j]=max(dp[j],dp[j-p[i].d]+p[i].w);
			ans=max(ans,dp[j]);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		if(n<0)
			break;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&p[i].w,&p[i].d,&p[i].l);
		}
		sort(p,p+n);
		solve();
	}
	return 0;
}
