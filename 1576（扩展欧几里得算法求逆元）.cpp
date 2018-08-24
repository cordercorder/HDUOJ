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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int mod=9973;

ll t,n,B;

ll solve(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int d=solve(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-a/b*y;
	return d;
}

int main(void){
	scanf("%lld",&t);
	ll ans,x,y;//(A/B)%mod
	while(t--){
		scanf("%lld %lld",&n,&B);
		solve(B,mod,x,y);
		ans=((x*n)%mod+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
