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

const int maxsize=1e2+10;
const ll maxw=1e17+10;

struct node{
	ll id;
	ll w;
	bool operator<(const node &a)const{
		if(id==a.id){
			if(w<a.w)
				return 1;
			return 0;
		}
		return w>a.w;
	}
};

ll n,m;
ll adj[maxsize][maxsize];
ll D[maxsize];
bool isv[maxsize];
priority_queue<node> q;

void solve(const ll &f){
	node now;
	for(ll i=1;i<=n;i++){
		isv[i]=0;
		if(i!=f){
			D[i]=adj[f][i];
			now.id=i;
			now.w=adj[f][i];
			q.push(now);
		}
	}
	D[f]=0;
	isv[f]=1;
	for(ll i=1;i<n;i++){
		while(!q.empty()&&isv[q.top().id])
			q.pop();
		isv[q.top().id]=1;
		for(ll j=1;j<=n;j++){
			if(!isv[j]&&q.top().w+adj[q.top().id][j]<D[j])
				D[j]=adj[q.top().id][j]+q.top().w;
				now.id=j;
				now.w=D[j];
				q.push(now);
		}
		q.pop();
	}
	printf("%lld\n",D[n]);
}

int main(void){
	ll u,v,w;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		for(ll i=0;i<=n;i++){
			for(ll j=0;j<=n;j++)
				adj[i][j]=maxw;
		}
		for(ll i=0;i<m;i++){
			scanf("%lld %lld %lld",&u,&v,&w);
			if(w<adj[u][v]){
				adj[u][v]=w;
				adj[v][u]=w;
			}
		}
		solve(1);	
	}
	return 0;
}
