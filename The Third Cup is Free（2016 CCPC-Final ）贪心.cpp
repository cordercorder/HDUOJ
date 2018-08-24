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

# define ll long long

using namespace std;

const int maxsize=1e5+10;

int t;
int a[maxsize],n;

bool cmp(const int &a,const int &b){
	return a>b;
}

int main(void){
	int i,cnt=0,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		cnt++;
		sort(a,a+n,cmp);
		for(i=0;i<n;i++){
			if((i+1)%3==0)
				continue;
			ans=ans+a[i];
		}
		printf("Case #%d: %d\n",cnt,ans);
	}
	return 0;
}
