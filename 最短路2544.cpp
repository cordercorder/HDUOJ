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
# include<deque>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const ll maxsize=1e2+10;
const ll maxw=1e16+10;

ll adj[maxsize][maxsize];
ll D[maxsize];
bool isv[maxsize];
ll n,m;

void solve(const ll &f){
	for(ll i=1;i<=n;i++){
		D[i]=adj[f][i];
		isv[i]=0;
	}
	isv[f]=1;
	D[f]=0;
	ll Min,u;
	for(ll i=1;i<n;i++){
		Min=maxw;
		u=-1;
		for(ll j=1;j<=n;j++){
			if(!isv[j]&&D[j]<Min){
				Min=D[j];
				u=j;
			}
		}
		if(u==-1)
			return ;
		isv[u]=1;
		for(ll j=1;j<=n;j++){
			if(!isv[j]&&adj[u][j]+Min<D[j])
				D[j]=adj[u][j]+Min;
		}
	}
	printf("%lld\n",D[n]);
}

int main(void){
	ll u,v,w;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		if(n==0&&m==0){
			break;
		}
		for(ll i=0;i<=n;i++){
			for(ll j=0;j<=n;j++)
				adj[i][j]=maxw;
		}
		for(ll i=0;i<m;i++){
			scanf("%lld %lld %lld",&u,&v,&w);
			if(w<adj[u][v]){
				adj[v][u]=w;
				adj[u][v]=w;
			}
		}
		solve(1);
	}
	return 0;
}
