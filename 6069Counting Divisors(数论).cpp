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

const int mod=998244353;

const int maxn=1e6;

ll t;
ll l,r,k;
vector<ll> pre;
bool flag[maxn+10];

ll handle(ll x){
	ll ans=1,res;
	for(ll i=0;i<pre.size()&&pre[i]<=x;i++){
		res=0;
		while(x%pre[i]==0){
			x/=pre[i];
			res++;
		}
		if(res!=0)
			ans=(ans%mod*(res*k+1)%mod)%mod;
		if(x==1)
			break;
	}
	if(x!=1){
		ans=ans*(k+1)%mod; 
	}
	return ans;
}

void solve(){
	ll ans=0;
	for(ll i=l;i<=r;i++){
		ans=(ans+handle(i))%mod;
	}
	printf("%lld\n",ans);
}

int main(void){
	memset(flag,0,sizeof(flag));
	for(ll i=2;i<=maxn;i++){
		if(!flag[i]){
			pre.push_back(i);
			for(ll j=i*i;j<=maxn;j+=i){
				flag[j]=1;
			}
		}	
	}
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld %lld %lld",&l,&r,&k);
			solve();
		}
	}
	return 0;
}
