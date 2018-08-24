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

const int maxn=5e4+10;

ll n;
ll l[maxn],r[maxn],a[maxn],b[maxn],c[maxn];
ll t;
ll res[maxn*2];
ll cnt;
ll tmp[maxn*2+1],sum[maxn*2+1];

void solve(){
	sort(res+1,res+1+cnt);
	ll len=unique(res+1,res+1+cnt)-res-1;
	ll nl,nr;
	memset(tmp,0,sizeof(tmp));
	for(ll i=1;i<=n;i++){
		nl=lower_bound(res+1,res+1+len,l[i])-res;
		nr=lower_bound(res+1,res+1+len,r[i])-res;
		nl++;
		nr+=2;
		//deb(nl);
		//deb(nr);
		tmp[1]+=c[i];
		tmp[nl]-=c[i];
		tmp[nl]+=a[i];
		tmp[nr+1]-=a[i];
		tmp[nr+1]+=b[i];
	}
	//for(ll i=1;i<=len+2;i++){
	//	printf("%lld ",tmp[i]);
	//}
	//cout<<endl;
	ll ans=0;
	for(ll i=1;i<=len+4;i++){
		sum[i]=sum[i-1]+tmp[i];
		ans=max(ans,sum[i]);
	}
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld",&n);
			cnt=0;
			for(ll i=1;i<=n;i++){
				scanf("%lld %lld %lld %lld %lld",&l[i],&r[i],&a[i],&b[i],&c[i]);
				res[++cnt]=l[i];
				res[++cnt]=r[i];
			}
			solve();
		}
	}
	return 0;
}
