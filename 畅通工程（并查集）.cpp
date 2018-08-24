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


const int maxsize=1e3+10;

int pre[maxsize];

int n,m;

int Find(int x){
	return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y){
	int nx=Find(x),ny=Find(y);
	if(nx!=ny){
		pre[ny]=nx;
	}
}

int main(void){
	int i;
	int a,b,ans;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		scanf("%d",&m);
		memset(pre,-1,sizeof(pre));
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			Union(a,b);
		}
		ans=0;
		for(i=1;i<=n;i++){
			if(pre[i]==-1)
				ans++;//计算集合的个数 
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
