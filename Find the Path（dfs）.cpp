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

const int maxsize=2e2+10;

const int maxw=1e9+10;

ll adj[maxsize][maxsize];
ll t,Q,ans,sum;
ll n,m;
ll c[maxsize];
bool flag;

bool isv[maxsize];

void Init_map(){
	ll i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			adj[i][j]=maxw;
	}
}

bool dfs(ll nu,ll nv,ll path,ll cc){
	int i;
	if(nu==nv&&flag==1){
		if(path<ans){
			ans=path;
			sum=cc-c[nv];
		}
		return 1;
	}
	if(nu==nv){
		if(path<ans){
			ans=path;
			sum=cc-c[nv];
		}
		flag=1;
		return 0;
	}
	for(i=0;i<n;i++){
		if(!isv[i]&&adj[nu][i]!=maxw){
			isv[i]=1;
			if(dfs(i,nv,path+adj[nu][i],cc+c[i])){
				return 1;
			}
			isv[i]=0;
		}
	}
	return 0;
}

int main(void){
	ll i;
	ll u,v,w,k;
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld %lld",&n,&m);
			for(i=0;i<n;i++)
				scanf("%lld",&c[i]);
			Init_map();
			for(i=0;i<m;i++){
				scanf("%lld %lld %lld",&u,&v,&w);
				if(w<adj[u][v]){
					adj[u][v]=w;
					adj[v][u]=w;
				}
			}
			scanf("%lld",&Q);
			while(Q--){
				scanf("%lld %lld %lld",&u,&v,&k);
				memset(isv,0,sizeof(isv));
				isv[u]=1;
				ans=maxw;
				flag=0;
				sum=0;
				dfs(u,v,0,0);
				//printf("ans=%lld\n",ans);
				//printf("sum=%lld\n",sum);
				if(ans==maxw||sum>k){
					printf("-1\n");
				}
				else{
					printf("%lld\n",ans);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
