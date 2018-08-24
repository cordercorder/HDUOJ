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

ll n,m;
ll t;
const ll p=100001651;

ll Pow(ll n, ll k, ll p){
	ll ans=1;
	while(k){
		if(k&1)
			ans=(ans*n)%p;
		n = (n*n)%p;
		k>>=1; //k=k>>1  k=k/2£»
	}
	return ans;
}

ll C(ll n,ll m,ll p){
	if(m==0)
		return 1;
	if(m>n-m)
		m=n-m;
	ll up=1,down=1;
	for(int i=1;i<=m;i++){
		up = (up*(n-i+1))%p;
		down=(down*i)%p;
	}
	return up*Pow(down,p-2,p)%p;
}
ll lucas(ll n,ll m,ll p){
	if(m==0)
		return 1;
	return C(n%p,m%p,p)*lucas(n/p,m/p,p);
}

int main(void){
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld %lld",&n,&m);
			if(m>n){
				puts("0");
				continue;
			}
			printf("%lld\n",lucas(n,m,p));
		}
	}
	return 0;
}
