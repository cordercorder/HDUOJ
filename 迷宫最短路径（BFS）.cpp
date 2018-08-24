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

const int maxsize=20;

struct node{
	int x;
	int y;
};

char str[maxsize][maxsize];
bool isv[maxsize][maxsize];
node ss,ee;
int n,m,ti,sum;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dis(int x,int y){
	return abs(x-ee.x)+abs(y-ee.y);
}

bool solve(int x,int y,int step){
	if(x==ee.x&&ee.y==y&&step==ti)
		return 1;
	if(ti-step-dis(x,y)<0||(ti-step-dis(x,y))%2==1)
		return 0;
	if(step>=ti)
		return 0;
	int i,nx,ny;
	for(i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&str[nx][ny]!='X'&&!isv[nx][ny]){
			isv[nx][ny]=1;//走过的标记 
			if(solve(nx,ny,step+1))
				return 1;
			isv[nx][ny]=0;
		}
	}
	return 0;
}

int main(void){
	int i,j;
	while(scanf("%d %d %d",&n,&m,&ti)){
		if(n==0&&m==0&&ti==0)
			break;
		sum=0;
		for(i=0;i<n;i++){
			scanf("%s",str[i]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(str[i][j]=='S'){
					ss.x=i;
					ss.y=j;
				}
				else if(str[i][j]=='D'){
					ee.x=i;
					ee.y=j;
				}
				else if(str[i][j]=='.'){
					sum++;//计算空地的个数 
				}
			}
		}
		//printf("sum=%d\n",sum);
		if(ti>sum+1){
			printf("NO\n");
			continue;
		}
		memset(isv,0,sizeof(isv));
		isv[ss.x][ss.y]=1;
		if(solve(ss.x,ss.y,0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
