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

ll f[maxn];
vector<ll> p;
ll n,a[maxn];
ll t;
ll sum,res[maxn],cnt;

ll handle(ll x){
	ll ss=0,tmp,ans=0;
	cnt=0;
	for(ll i=1;i<=n;i++){
		tmp=a[i]%x;
		ss+=tmp;
		if(tmp)
			res[++cnt]=tmp;
	}
	sort(res+1,res+1+cnt,greater<ll>());
	for(ll i=1;i<=cnt;i++){
		ans+=(x-res[i]);
		ss-=x;
		if(ss==0)
			break;
	}
	//deb(x);
	//deb(ans);
	//puts("");
	return ans;
}

void solve(){
	ll ans=maxw;
	for(ll i=0;i<(ll)p.size();i++){
		if(sum%p[i]==0){
			ans=min(ans,handle(p[i]));
		}
	}
	if(ans==maxw){
		sort(a+1,a+1+n);
		ans=sum-a[n];
		printf("%lld\n",ans);
		return ;
	}
	printf("%lld\n",ans);
}

int main(void){
	for(ll i=2;i<=100000;i++){
		if(!f[i]){
			p.push_back(i); 
			for(ll j=i*i;j<=100000;j+=i){
				f[j]=1;
			}
		}
	}
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		sum=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		solve();
	}
	return 0;
}
