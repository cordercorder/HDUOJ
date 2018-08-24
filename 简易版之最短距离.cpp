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

# define ll long long

using namespace std;

const int maxsize=5e2+10;

int t;
int n;
int a[maxsize];

int main(void){
	int i,ans;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(i=1;i<=n;i++){
				scanf("%d",&a[i]);
			}
			sort(a+1,a+1+n);
			ans=0;
			for(i=1;i<n/2+1;i++){
				ans=ans+a[n/2+1]-a[i];
			}
			for(i=n/2+2;i<=n;i++){
				ans=ans+a[i]-a[n/2+1];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
