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

ll n,t;
vector<ll> e[maxn];
ll a[maxn];
priority_queue<ll> q[maxn];
priority_queue<ll,vector<ll>,greater<ll> > q2[maxn];

bool isv[maxn];

void solve(){
	ll u,v;
	for(ll i=1;i<=n;i++){
		if(e[i].empty())
			continue;
		for(ll j=0;j<(ll)e[i].size();j++){
			q[i].push(a[e[i][j]]);
			q2[i].push(a[e[i][j]]);
		}
	}
	ll ans1=0,ans2=0;
	ans1=max(ans1,a[1]);
	ans2=min(ans2,a[1]);
	for(ll i=1;i<=n;i++){
		if(!q[i].empty()){
			ans1+=max((ll)0,q[i].top());
			q[i].pop();
		}
		if(!q2[i].empty()){
			ans2+=min((ll)0,q2[i].top());
			q2[i].pop();	
		}
	}
	ll tmp1=0,tmp2=0;
	for(ll i=1;i<=n;i++){
		if(!q[i].empty()){
			tmp1=max(tmp1,q[i].top());//max element
			q[i].pop();
		}
		if(!q2[i].empty()){
			tmp2=min(tmp2,q2[i].top());
			q2[i].pop();	
		}
	}
	ans1+=tmp1;
	ans2+=tmp2;
	printf("%lld %lld\n",ans1,ans2);
	for(ll i=1;i<=n;i++){
		e[i].clear();
		while(!q[i].empty())
			q[i].pop();
		while(!q2[i].empty())
			q2[i].pop();
	}
}

int main(void){
	ll u;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(ll i=2;i<=n;i++){
			scanf("%lld",&u);
			e[u].push_back(i);
		}
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		solve();
	}
	return 0;
}
