#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

int dfn[maxn],low[maxn];
bool isv[maxn];//≈–∂œ «∑Ò‘⁄’ª÷– 
vector<int> e[maxn];
int ans;
int sta[maxn],tt;
int cnt; 
int n,m;

void Tarjan(int u){
	isv[u]=1;
	low[u]=dfn[u]=++cnt;
	sta[++tt]=u;
	int v;
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(isv[v]==1){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		ans++;
		int now;
		while(1){
			now=sta[tt--];
			isv[now]=0;
			if(now==u)
				break;
		}
	}
}

int main(void){
	int a,b;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			e[a].push_back(b);
		}
		cnt=0;
		ans=0;
		tt=0;
		memset(dfn,0,sizeof(dfn));
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				Tarjan(i);
			}
		}
		if(ans==1){
			puts("Yes");
		}
		else{
			puts("No");
		}
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
