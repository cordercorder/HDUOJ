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
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

const int maxw=1e9+10;

int n;

bool isv[maxsize];
int adj[maxsize][maxsize];
int lowcost[maxsize];

void solve(){
	int i,u,Min,p,ans=0;
	isv[1]=1;
	for(i=1;i<=n;i++){
		lowcost[i]=adj[1][i];
	}
	for(i=2;i<=n;i++){
		Min=maxw;
		p=-1;
		for(u=1;u<=n;u++){//选取邻接边中最小的 
			if(!isv[u]&&lowcost[u]<Min){
				Min=lowcost[u];
				p=u;
			}
		}
		//deb(p);
		if(p==-1){
			//printf("error\n");
			return ;
		}
		isv[p]=1;
		ans+=Min;
		for(u=1;u<=n;u++){
			if(!isv[u]&&adj[p][u]<lowcost[u])
				lowcost[u]=adj[p][u];
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int i,j;
	int u,v,w;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		memset(isv,0,sizeof(isv));
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				adj[i][j]=maxw;
		for(i=0;i<(n*(n-1))/2;i++){
			scanf("%d %d %d",&u,&v,&w);
			if(w<=adj[u][v]){
				adj[u][v]=w;
				adj[v][u]=w;
			}
		}
		solve();
	}
	return 0;
}
