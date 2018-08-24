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

const int maxn=(1<<16);

ll dp[maxn+10][33];
ll k;
ll num;
ll ans;

bool check(const ll &nl,const ll &p){
	ll l=nl+1,r=maxn,mid;
	ll tmp;
	while(l<r){
		mid=(l+r)>>1;
		tmp=dp[mid][p]+nl*mid*p;
		if(dp[mid][p]==0||tmp>num){
			r=mid;
		}
		else if(tmp==num){
			return 1;
		}
		else{
			l=mid+1;
		}
	}
	return 0;
}

int main(void){
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=maxn;i++){
		dp[i][1]=i;
		for(ll j=2;j<=31;j++){
			dp[i][j]=dp[i][j-1]*i;
			if(dp[i][j]>(ll)INT_MAX)
				break;
		}
	}
	while(scanf("%lld",&k)!=EOF){
		if(k==0)
			break;
		ans=0;
		for(ll i=1;i<=maxn;i++){
			for(ll j=2;j<=31;j++){
				if(dp[i][j]==0)
					continue;
				if(k<=(i*j))
					break;
				num=k-dp[i][j];
				if(check(i,j))
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
