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
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

typedef long long ll;

using namespace std;

const int maxn=1e3+10;
const int maxw=1e7+10;

vector<pair<int,int> > p[maxn];
int n,m;
queue<int> q;
int D[maxn];
bool isv[maxn];
int dp[maxn];


void spfa(int u){
	for(int i=0;i<=n;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[u]=0;
	isv[u]=1;
	int now,w,v;
	q.push(u);
	while(!q.empty()){
		now=q.front();
		q.pop();
		isv[now]=0;
		for(int i=0;i<p[now].size();i++){
			v=p[now][i].first;
			w=p[now][i].second;
			if(D[v]>D[now]+w){
				D[v]=D[now]+w;
				if(!isv[v]){
					q.push(v);
					isv[v]=1;
				}				
			}	
		}
	}
}

int solve(int x){
	if(x==2)
		return 1;
	if(dp[x]>0)
		return dp[x];
	int u;
	for(int i=0;i<p[x].size();i++){
		u=p[x][i].first;
		if(D[u]<D[x]){
			dp[x]+=solve(u);
		}
	}
	return dp[x];
}

int main(void){
	int u,v,w;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&w);
			p[u].push_back({v,w});
			p[v].push_back({u,w});		
		}
		spfa(2);
		memset(dp,0,sizeof(dp));
		printf("%d\n",solve(1));
		for(int i=0;i<=n;i++)
			p[i].clear();
	}
	return 0;
}
