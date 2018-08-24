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

# define deb(x) printf("# x=%d\n",x)

typedef long long ll;

using namespace std;

ll n; 

ll Cnm(ll m){
	ll i,ans=1;
	for(i=1;i<=m;i++){
		ans=ans*(n-i+1)/i;
		//deb(ans);
	}
	return ans;
}

void solve(){
	ll i,ans=0;
	for(i=1;i<n;i++){
		ans=ans+i*Cnm(i+1);
		//deb(ans);
	}
	printf("%lld\n",ans);
}

int main(void){
	int i;
	while(scanf("%lld",&n)!=EOF){
		solve();
	}
	return 0;
}
