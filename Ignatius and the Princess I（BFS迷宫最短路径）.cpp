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

const int maxsize=1e2+10;

struct node{
	int x;
	int y;
	int steps;
	bool operator<(const node &a)const{
		return steps>a.steps;
	}
	node():steps(0){			};
	node(int xx,int yy):x(xx),y(yy),steps(0){			};
};

int n,m,ans;

char str[maxsize][maxsize];
int dir[maxsize][maxsize];
bool isv[maxsize][maxsize];

priority_queue<node> q;
int ti;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

bool solve(){
	memset(isv,0,sizeof(isv));
	memset(dir,0,sizeof(dir));
	node tmp(0,0),now;
	q.push(tmp);
	isv[0][0]=1;
	int nx,ny,i;
	while(!q.empty()){
		now=q.top();
		//printf("x=%d  y=%d  steps=%d\n",now.x,now.y,now.steps);
		if(now.x==n-1&&now.y==m-1){
		ans=now.steps;
			while(!q.empty())
				q.pop();
			return 1;
		}
		q.pop();
		for(i=0;i<4;i++){
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&str[nx][ny]!='X'&&!isv[nx][ny]){
				tmp.x=nx;
				tmp.y=ny;
				if(str[nx][ny]=='.'){
					tmp.steps=now.steps+1;
				}
				else if(str[nx][ny]<='9'&&str[nx][ny]>='0'){
					tmp.steps=now.steps+1+str[nx][ny]-'0';
				}
				q.push(tmp);
				isv[tmp.x][tmp.y]=1;
				dir[tmp.x][tmp.y]=i+1; //活结点 ,记录所走的方向 
			}
		}
	}
	return 0;
}

void print(int x,int y){
	if(!dir[x][y])
		return ;
	int nx,ny;
	nx=x-dx[dir[x][y]-1];
	ny=y-dy[dir[x][y]-1];
	print(nx,ny);
	printf("%ds:(%d,%d)->(%d,%d)\n",ti++,nx,ny,x,y);
	if(str[x][y]>='0'&&str[x][y]<='9'){
		for(int i=str[x][y]-'0';i>0;i--){
			printf("%ds:FIGHT AT (%d,%d)\n",ti++,x,y);
		}
	}
}

int main(void){
	int i;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		ti=1;
		if(solve()){
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);			
			print(n-1,m-1);	
		}
		else{
			printf("God please help our poor hero.\n");
		}
		printf("FINISH\n");
		
	}
	return 0;
}
