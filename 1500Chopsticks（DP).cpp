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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=5e3+10;
const ll maxw=1e10+10;


ll t;
ll n,k;
ll a[maxsize];

ll solve(ll x,ll y){
	if(y==k+8){
		return 0;
	}
	if(x>n-3){
		return maxw;//»¹Ã»Ñ¡Âú 
	}
	ll res1,res2;
	//printf("x=%lld\n",x);
	res1=solve(x+3,y+1)+(a[x]-a[x+1])*(a[x]-a[x+1]);
	//printf("###res1=%lld\n",res1);
	res2=solve(x+1,y);
	//printf("res1=%lld   res2=%lld\n",res1,res2);
	
	
	if(res1<res2)
		return res1;
	return res2;
}

int main(void){
	int i;
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld %lld",&k,&n);
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			sort(a,a+n);
			for(i=0;i<n;i++)
				printf("%d ",a[i]);
			printf("\n");
			
			printf("%lld\n",solve(0,0));
		}
	}
	
	return 0;
}
