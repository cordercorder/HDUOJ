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

const int maxw=1e6+10;
const int maxn=1e3+10;

vector<pair<int,int> > p[maxn];
int n,m,ee;
int q;
pair<int,int> tmp;
int D[maxn];
bool isv[maxn];
queue<int> qq;

void spfa(int u){
	for(int i=0;i<=n;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[u]=0;
	isv[u]=1;
	qq.push(u);
	int now;
	int v,w;
	while(!qq.empty()){
		now=qq.front();
		isv[now]=0;
		qq.pop();
		for(int i=0;i<p[now].size();i++){
			v=p[now][i].first;
			w=p[now][i].second;
			if(D[v]>D[now]+w){
				D[v]=D[now]+w;
				if(!isv[v]){
					qq.push(v);
					isv[v]=1;
				}
			}		
		}	
	}
}

int main(void){
	int u,v,w;
	int x;
	while(scanf("%d %d %d",&n,&m,&ee)!=EOF){
		while(m--){
			scanf("%d %d %d",&u,&v,&w);
			p[u].push_back({v,w});
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			scanf("%d",&x);
			tmp.first=x;
			tmp.second=0;
			p[0].push_back(tmp);
		}
		spfa(0);
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
