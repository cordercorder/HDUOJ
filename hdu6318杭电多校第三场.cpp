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

const int maxn=1e5+10;

ll a[maxn],tmp[maxn];

ll n,x,y;
ll ans;

void Merge(ll st1,ll ed1,ll st2,ll ed2){
	ll i=st1,j=st2,cnt=st1;
	while(i<=ed1&&j<=ed2){
		if(a[i]<=a[j]){
			tmp[cnt++]=a[i++];
		}
		else{
			ans+=(ed1-i+1);
			tmp[cnt++]=a[j++];
		}
	}
	while(i<=ed1){
		tmp[cnt++]=a[i++];
	}
	while(j<=ed2){
		tmp[cnt++]=a[j++];
	}
	for(i=st1;i<=ed2;i++){
		a[i]=tmp[i];
	}
}

void m_sort(ll l,ll r){
	ll mid;
	if(l<r){
		mid=(l+r)>>1;
		m_sort(l,mid);
		m_sort(mid+1,r);
		Merge(l,mid,mid+1,r);
	}
}

void solve(){
	ans=0;
	m_sort(1,n);
	ans=ans*min(x,y);
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%lld %lld %lld",&n,&x,&y)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		solve();
	}
	return 0;
}
