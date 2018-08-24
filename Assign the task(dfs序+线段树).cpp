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

const int maxn=5e4+10;

int T;
int n,m;
int ss[maxn],ee[maxn];
int cnt;
int t[maxn<<2],add[maxn<<2];

vector<int> p[maxn];
bool isv[maxn];

void handle(int x){
	ss[x]=++cnt;
	for(int i=0;i<p[x].size();i++){
		handle(p[x][i]);
	}
	ee[x]=cnt;
}

void pushdown(int rt){
	if(add[rt]!=-1){
		t[rt<<1]=add[rt];
		t[rt<<1|1]=add[rt];
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		add[rt]=-1;
	}
}

void update(int rt,int l,int r,int L,int R,int val){
	if(l==L&&R==r){
		t[rt]=val;
		add[rt]=val;
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,val);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,val);
	}
	else{
		update(rt<<1,l,mid,L,mid,val);
		update(rt<<1|1,mid+1,r,mid+1,R,val);
	}
}

int query(int rt,int l,int r,int x){
	if(l==r){
		return t[rt];
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(x<=mid){
		return query(rt<<1,l,mid,x);
	}
	else{
		return query(rt<<1|1,mid+1,r,x);
	}
}

int main(void){
	int u,v;
	int x,y;
	char str[10];
	while(scanf("%d",&T)!=EOF){
		for(int j=1;j<=T;j++){
			scanf("%d",&n);
			memset(isv,0,sizeof(isv));
			for(int i=1;i<n;i++){
				scanf("%d %d",&u,&v);
				p[v].push_back(u);
				isv[u]=1;
			}
			cnt=0;
			for(int i=1;i<=n;i++){
				if(!isv[i]){
					handle(i);
					break;
				}
			}
			memset(t,-1,sizeof(t));
			memset(add,-1,sizeof(add));
			scanf("%d",&m);
			printf("Case #%d:\n",j);
			while(m--){
				scanf("%s",str);
				if(str[0]=='C'){
					scanf("%d",&x);
					printf("%d\n",query(1,1,cnt,ss[x]));
				}
				else{
					scanf("%d %d",&x,&y);
					update(1,1,cnt,ss[x],ee[x],y);
				}
			}
			for(int i=1;i<=n;i++){
				p[i].clear();
			}
		}
	}
	return 0;
}
