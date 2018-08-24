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

const int maxsize=1e2+10;
const int max_w=1e6;

struct G{
	int adj[maxsize][maxsize];
	int vnum;
};

int n,m;
G a;
int D[maxsize];
bool isv[maxsize];

void Init_G(){
	int i,j;
	for(i=0;i<=maxsize;i++){
		for(j=0;j<=maxsize;j++){
			a.adj[i][j]=max_w;
		}
	}
}

void Dijstra(const int &f){
	int i,u,v,Min;
	for(i=0;i<a.vnum;i++){
		isv[i]=0;
		D[i]=a.adj[f][i];
	}
	D[f]=0;
	isv[f]=1;
	for(i=1;i<a.vnum;i++){
		Min=max_w;
		for(u=0;u<a.vnum;u++){
			if(!isv[u]&&D[u]<Min){
				v=u;
				Min=D[u];
			}
		}
		if(v<a.vnum)
			isv[v]=1;
		for(u=0;u<a.vnum;u++){
			if(!isv[u]&&v<a.vnum&&(Min+a.adj[v][u])<D[u]){
				D[u]=Min+a.adj[v][u];
			}
		}
	}
}

bool check(){
	int i,j;
	for(i=0;i<n;i++){
		Dijstra(i);
		for(j=0;j<n;j++){
			if(D[j]>7){
				return 0;
			}
		}
	}
	return 1;
}

int main(void){
	int i,x,y;
	while(scanf("%d %d",&n,&m)!=EOF){
		Init_G();
		a.vnum=n;
		for(i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			a.adj[x][y]=1;
			a.adj[y][x]=1;
		}
		if(check()){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
