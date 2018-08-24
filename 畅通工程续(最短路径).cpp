# include<iostream>
# include<algorithm>
# include<cstring>
# include<cstdlib>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

using namespace std;

# define ll long long

const int maxsize=1e3+10;
const ll maxw=pow(2,62)+5;

struct node{
	ll adj[maxsize][maxsize];
	ll vnum;
};

node G;
ll n,m;
ll a,b,x;
bool isv[maxsize];
ll D[maxsize];

void solve(const ll &f,const ll &end){
	ll i,u,v=maxw,Min;
	for(i=1;i<=n;i++){
		isv[i]=0;
		D[i]=G.adj[f][i];
	}
	isv[f]=1;
	D[f]=0;
	for(i=1;i<n;i++){
		Min=maxw;
		for(u=1;u<=n;u++){
			if(!isv[u]&&D[u]<Min){
				Min=D[u];
				v=u;
			}
		}
		if(v<n)
			isv[v]=1;
		for(u=1;u<=n;u++){
			if(!isv[u]&&v<n&&(G.adj[v][u]+Min)<D[u])
				D[u]=G.adj[v][u]+Min;
		}
	}
	if(D[end]==maxw){
		printf("-1\n");
		return ;
	}
	printf("%lld\n",D[end]);
}

int main(void){
	ll i,j,x1,y1;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		for(i=1;i<=n;i++){
			for(j=0;j<n;j++){
				G.adj[i][j]=maxw;
			}
		}
		while(m--){
			scanf("%lld %lld %lld",&a,&b,&x);
			if(a==b)
				continue;
			if(x<G.adj[a][b]){
				G.adj[a][b]=x;
				G.adj[b][a]=x;
			}
		}
		scanf("%lld %lld",&x1,&y1);
		solve(x1,y1);
	}
	return 0;
}
