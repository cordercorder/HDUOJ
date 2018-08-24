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

const int maxn=1e6+10;

ll n;
vector<ll> pre;
bool flag[maxn+10];

void solve(){
	ll tmp=n;
	ll res;
	ll ans=1;
	for(ll i=0;i<pre.size();i++){
		res=0;
		while(tmp%pre[i]==0){
			tmp/=pre[i];
			res++;
		}
		if(res!=0){
			ans*=(res+1);
		}
		if(tmp==1)
			break;
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
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		solve();
	}
	return 0;
}
