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

const int mod=1e9+7;
const int maxn=1e2+10;

struct node{
	ll l;
	ll r;
}res[maxn];

ll t;
ll inv;
ll n;

ll q_mod(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

bool cmp(const node &a,const node &b){
	if(a.l<b.l)
		return 1;
	else if(a.l==b.l&&a.r<b.r)
		return 1;
	return 0;
}

void solve(){
	ll ans=1;
	sort(res+1,res+1+n,cmp);
	for(ll i=res[n].l;i<=res[n].r;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=res[j].l;k<=res[j].r;k++){
				deb(i);
				deb(j);
				deb(k);
				puts("");
				
				ans=ans*(max(i,k)-k+1)%mod;
			}
		}
	}
	ans=ans*inv%mod;
	printf("%lld\n",ans);
}

int main(void){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		inv=1;
		for(ll i=1;i<=n;i++){
			scanf("%lld %lld",&res[i].l,&res[i].r);
			inv=inv*q_mod(res[i].r-res[i].l+1,mod-(ll)2)%mod;
		}
		solve();
	}
	return 0;
}
