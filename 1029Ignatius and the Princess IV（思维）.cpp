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

const int maxsize=1e6+10;

int a[maxsize];

int n;

int main(void){
	int i,u;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		u=(n+1)/2;
		printf("%d\n",a[u]);		
	}
	return 0;
}
