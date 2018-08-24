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

typedef long long ll;

using namespace std;

const int maxsize=25;

int adj[maxsize][maxsize];

int p[maxsize];

int n,m;

bool check(int x,int u){//组u里面放入x 
	int i;
	for(i=0;i<n;i++){
		if(p[i]==u&&adj[i][x]==0)
			return 0;
	}
	return 1;
}

bool dfs(int x){
	if(x>=n)
		return 1;
	int i;
	for(i=0;i<m;i++){//每个小朋友尝试放入第每个组内 
		if(check(x,i)){
			p[x]=i;
			if(dfs(x+1)){
				return 1;
			}
			p[x]=-1;
		}
	}
	return 0;
}

int main(void){
	int i,k,ans;
	int x;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(adj,0,sizeof(adj));
		memset(p,-1,sizeof(p));//p[i]=x表明i所在的组是x 
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&k);
			while(k--){
				scanf("%d",&x);
				adj[i][x]=1;
				adj[x][i]=1;
			}
		}
		if(dfs(0)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
