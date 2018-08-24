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

const int maxsize=25;

struct node{
	int x;
	int y;
	int ti;
	node():ti(0){			};
	bool operator==(const node &a)const{
		if(a.x==x&&a.y==y&&a.ti==ti)
			return 1;
		return 0;
	}
	bool operator<(const node &a)const{
		return ti>a.ti;
	}
};

char str[maxsize][maxsize];
bool isv[maxsize][maxsize],stop[maxsize][maxsize];
node ss,ee;//起始点和终点 
int m,n;
priority_queue<node> q;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void solve(){
	node tmp,now;
	q.push(ss);
	isv[ss.x][ss.y]=1;
	int i,nx,ny;
	while(!q.empty()){
		now=q.top();
		q.pop();
		//printf("x=%d   y=%d   ti=%d\n",now.x,now.y,now.ti);
		if(now.x==ee.x&&now.y==ee.y){
			printf("%d\n",now.ti);
			while(!q.empty())
				q.pop(); 
			return ;
		}
		for(i=0;i<4;i++){
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx>=0&&nx<m&&ny>=0&&ny<n&&!isv[nx][ny]&&str[nx][ny]!='*'){
				if(str[nx][ny]!='|'&&str[nx][ny]!='-'){
					tmp.x=nx;
					tmp.y=ny;
					tmp.ti=now.ti+1;
					isv[nx][ny]=1;
					q.push(tmp);
				}
				else if(str[nx][ny]=='|'){//楼梯 
					if(now.ti&1){//奇数 
						if(i&1){//i为奇数才能走 
							int nnx=nx+dx[i];
							int nny=ny+dy[i];
							if(nnx>=0&&nnx<m&&nny>=0&&nny<n&&!isv[nnx][nny]&&str[nnx][nny]!='*'){
								tmp.x=nnx;
								tmp.y=nny;
								tmp.ti=now.ti+1;
								isv[nnx][nny]=1;
								q.push(tmp);
							}
						}
						else if(!stop[now.x][now.y]){//不能走的话停留一分钟 
							tmp=now;
							tmp.ti++;
							stop[tmp.x][tmp.y]=1;
							q.push(tmp);
						}
					}
					else{//偶数，楼梯在原位置 
						if(i&1&&!stop[now.x][now.y]){//此时不能通过 
							tmp=now;
							tmp.ti++;
							stop[tmp.x][tmp.y]=1;
							q.push(tmp);
						}
						else{
							int nnx=nx+dx[i];
							int nny=ny+dy[i];
							if(nnx>=0&&nnx<m&&nny>=0&&nny<n&&!isv[nnx][nny]&&str[nnx][nny]!='*'){
								tmp.x=nnx;
								tmp.y=nny;
								tmp.ti=now.ti+1;
								isv[nnx][nny]=1;
								q.push(tmp);
							}
						}
					}
				}
				else if(str[nx][ny]=='-'){
					if(now.ti&1){//奇数，楼梯为'|'
						if(i&1&&!stop[now.x][now.y]){//此时不能走 
							tmp=now;
							tmp.ti++;
							stop[tmp.x][tmp.y]=1;
							q.push(tmp);//等一分钟 
						}
						else{//能走 
							int nnx=nx+dx[i];
							int nny=ny+dy[i];
							if(nnx>=0&&nnx<m&&nny>=0&&nny<n&&!isv[nnx][nny]&&str[nnx][nny]!='*'){
								tmp.x=nnx;
								tmp.y=nny;
								tmp.ti=now.ti+1;
								isv[nnx][nny]=1;
								q.push(tmp);
							}
						}
					}
					else{//偶数，楼梯为'-' 
						//printf("ok\n");
						if(i&1){//能通过楼梯 
							int nnx=nx+dx[i];
							int nny=ny+dy[i];
							if(nnx>=0&&nnx<m&&nny>=0&&nny<n&&!isv[nnx][nny]&&str[nnx][nny]!='*'){
								tmp.x=nnx;
								tmp.y=nny;
								tmp.ti=now.ti+1;
								isv[nnx][nny]=1;
								q.push(tmp);
							}
						}
						else if(!stop[now.x][now.y]){
							tmp=now;
							tmp.ti++;
							stop[tmp.x][tmp.y]=1;
							q.push(tmp);//等一分钟	
						}
					}
				}
			}
		}
	}
}

int main(void){
	int i,j;
	while(scanf("%d %d",&m,&n)!=EOF){
		for(i=0;i<m;i++){
			getchar();
			for(j=0;j<n;j++){
				scanf("%c",&str[i][j]);
				if(str[i][j]=='S'){
					ss.x=i;
					ss.y=j;
				}
				else if(str[i][j]=='T'){
					ee.x=i;
					ee.y=j;
				}
			}
		}
		memset(stop,0,sizeof(stop));
		memset(isv,0,sizeof(isv));
		solve();
	}
	return 0;
}
