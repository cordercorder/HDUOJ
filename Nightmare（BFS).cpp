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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=15;

struct node{
	int x;
	int y;
	int steps;
	int ti;//剩余爆炸时间 
	bool flag;//是否重置了时间 
	node():steps(0),ti(6),flag(false){			}; 
};

int T;
int n,m;
int num[maxsize][maxsize];
node ss,ee;
queue<node> q;
bool isv[maxsize][maxsize][2];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void solve(){
	int i,nx,ny;
	memset(isv,0,sizeof(isv));
	node now,tmp;
	q.push(ss);
	isv[ss.x][ss.y][0]=1;
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.x==ee.x&&now.y==ee.y){
			printf("%d\n",now.steps);
			while(!q.empty())
				q.pop();
			return ;
		}
		now.ti--;
		//printf("x=%d  y=%d  steps=%d  flag=%d  ti=%d\n",now.x,now.y,now.steps,now.flag,now.ti);
		if(now.ti<=0)
			continue;
		for(i=0;i<4;i++){
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&num[nx][ny]!=0){
				if(num[nx][ny]!=4){
					tmp.ti=now.ti;
					tmp.flag=now.flag;
				}
				else{
					tmp.ti=6;
					tmp.flag=1;
				}
				if(isv[nx][ny][tmp.flag]){
					continue;
				}
				tmp.x=nx;
				tmp.y=ny;
				tmp.steps=now.steps+1;
				isv[nx][ny][tmp.flag]=1;
				q.push(tmp);
			}
		}
	}
	printf("-1\n");
}

int main(void){
	int i,j;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			scanf("%d %d",&n,&m);
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					scanf("%d",&num[i][j]);
					if(num[i][j]==2){//起点 
						ss.x=i;
						ss.y=j;
					}
					else if(num[i][j]==3){//终点 
						ee.x=i;
						ee.y=j;
					}
				}
			}
			solve();
		}
	}
	return 0;
}
