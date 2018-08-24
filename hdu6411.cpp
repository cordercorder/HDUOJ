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

const int maxn=1e5+10;
const ll mod=1e9+7;

ll t;
ll n,m;
ll res[maxn];
vector<ll> e[maxn];
bool isv[maxn];
vector<ll> s[maxn];
vector<ll>::iterator it;
ll cnt;
ll sum[35];

void dfs(ll x){
	isv[x]=1;
	s[cnt].push_back(res[x]);
	ll u;
	for(ll i=0;i<(ll)e[x].size();i++){
		u=e[x][i];
		if(!isv[u]){
			dfs(u);
		}
	}
}

void solve(){
	cnt=0;
	for(ll i=1;i<=n;i++){
		if(!isv[i]){
			++cnt;
			dfs(i);
		}
	}
	ll ans=0;
	for(ll i=1;i<=cnt;i++){
		sort(s[i].begin(),s[i].end());
		memset(sum,0,sizeof(sum));
		for(ll j=0;j<(ll)s[i].size();j++){
			for(ll k=0;k<31;k++){
				if(s[i][j]&(ll)(1<<k)){
					ans=(ans+s[i][j]*(sum[k]*(ll)(1<<k)%mod)%mod)%mod;
					sum[k]++;
				}
			}
		}
		s[i].clear();
	}
	printf("%lld\n",ans);
}

int main(void){
	ll u,v;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&res[i]);
			isv[i]=0;
			e[i].clear();
		} 
		while(m--){
			scanf("%lld %lld",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		solve();
	}
	return 0;
}
