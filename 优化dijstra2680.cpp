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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e3+10;
const int maxw=1e7+10;

int n,m,ee;
int q;
vector<pii> p[maxn];
bool isv[maxn];
int D[maxn];
priority_queue<pii,vector<pii>,greater<pii> > qq;

void solve(int ss){
	for(int i=0;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	D[ss]=0;
	qq.push({0,ss});
	pii now;
	int u,v,w;
	while(!qq.empty()){
		now=qq.top();
		qq.pop();
		u=now.second;
		w=now.first;
		if(isv[u])
			continue;
		isv[u]=1;
		for(int i=0;i<p[u].size();i++){
			v=p[u][i].second;
			w=p[u][i].first;
			if(!isv[v]&&D[v]>D[u]+w){
				D[v]=D[u]+w;
				qq.push({D[v],v});
			}
		}
	}
}

int main(void){
	int u,v,w;
	while(scanf("%d %d %d",&n,&m,&ee)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&w);
			p[u].push_back({w,v});
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			scanf("%d",&u);
			p[0].push_back({0,u});
		}
		solve(0);
		if(D[ee]==maxw){
			puts("-1");
		}
		else{
			printf("%d\n",D[ee]);
		}
		for(int i=0;i<=n;i++)
			p[i].clear();
	}
	return 0;
}
