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

const int maxsize=2e2+10;
const ll maxw=1e15+10;

ll t;
ll n,m;
ll c[maxsize];
ll adj[maxsize][maxsize];
ll D[maxsize];
ll k;
bool isv[maxsize];

void solve(ll f,ll ee){
	ll Min,x;
	for(ll i=0;i<n;i++){
		D[i]=adj[f][i];
		isv[i]=0;
	}
	D[f]=0;
	isv[f]=1;
	for(ll i=1;i<n;i++){
		Min=maxw;
		x=-1;
		for(ll j=0;j<n;j++){
			if(!isv[j]&&D[j]<Min){
				if(j==ee||c[j]<=k){
					x=j;
					Min=D[j];
				}
			}
		}
		if(x!=-1){
			isv[x]=1;
			for(ll j=0;j<n;j++){
				if(!isv[j]&&(Min+adj[x][j])<D[j]){
					D[j]=Min+adj[x][j];
				}
			}
		}
	}
}

void handle(){
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=n;j++){
			adj[i][j]=maxw;
		}
	}
}

int main(void){
	ll u,v,w,q;
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld %lld",&n,&m);
			for(ll i=0;i<n;i++){
				scanf("%lld",&c[i]);
			}
			handle();
			for(ll i=0;i<m;i++){
				scanf("%lld %lld %lld",&u,&v,&w);
				if(w<adj[u][v]){
					adj[u][v]=w;
					adj[v][u]=w;	
				}
			}
			scanf("%lld",&q);
			while(q--){
				//cout<<"ok"<<endl;
				scanf("%lld %lld %lld",&u,&v,&k);
				solve(u,v);
				if(D[v]==maxw){
					puts("-1");
				}
				else{
					printf("%lld\n",D[v]);
				}
			}
			
		}
	}
	return 0;
}
