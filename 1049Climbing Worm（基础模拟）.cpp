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
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

int n,u,d;

void solve(){
	int sum=0,ti=0;
	while(sum<n){
		sum=sum+u;
		ti++;
		if(sum>=n)
			break;
		sum=sum-d;
		ti++;
	}
	printf("%d\n",ti);
}

int main(void){
	while(scanf("%d %d %d",&n,&u,&d)){
		if(n==0)
			break;
		solve();
	}
	return 0;
}
