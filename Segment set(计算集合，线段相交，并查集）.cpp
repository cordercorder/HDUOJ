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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=1e3+10;

struct element{
	double x;
	double y;
};

struct node{
	element s;
	element e;
	void Set(const node &aa){
		this->e.x=aa.e.x;
		this->e.y=aa.e.y;
		this->s.x=aa.s.x;
		this->s.y=aa.s.y;
	}
}point[maxn];

int cnt;
int pre[maxn];
int sum[maxn];

node a,b;

int t,n;

double cross(element a,element b,element c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

bool check(node a,node b){
	if(cross(b.s,a.e,a.s)*cross(a.e,b.e,a.s)<0)
		return 0;
	if(cross(a.e,b.e,b.s)*cross(b.e,a.s,b.s)<0)
		return 0;
	return 1;
}

int Find(int x){
	return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y){
	int nx=Find(x);
	int ny=Find(y);
	if(nx==ny){
		return ;
	}
	pre[nx]=ny;
	sum[ny]+=sum[nx];
}

void handle(){
	for(int i=1;i<cnt-1;i++){
		if(check(point[cnt-1],point[i])){
			Union(cnt-1,i);
		}
	}
}

int main(void){
	char str[10];
	int tmp,x;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			cnt=1;
			memset(pre,-1,sizeof(pre));
			for(int i=0;i<=n;i++)
				sum[i]=1;
			for(int i=0;i<n;i++){
				scanf("%s",str);
				if(str[0]=='P'){
					scanf("%lf %lf %lf %lf",&a.s.x,&a.s.y,&a.e.x,&a.e.y);
					point[cnt++].Set(a);
					handle();
				}
				else{
					scanf("%d",&x);
					tmp=Find(x);
					printf("%d\n",sum[tmp]);
				}			
			}
			if(t)
				printf("\n");	
		}
	}
	return 0;
}
