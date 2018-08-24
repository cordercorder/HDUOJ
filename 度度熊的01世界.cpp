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

const int maxn=1e2+10;

char s[maxn][maxn];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool isv[2][maxn][maxn];

void handle(int x,int y){
	int nx,ny;
	for(int i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&!isv[0][nx][ny]&&s[nx][ny]=='1'){
			isv[0][nx][ny]=1;
			handle(nx,ny);
		}
	}
}

void handle2(int x,int y){
	int nx,ny;
	for(int i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&!isv[1][nx][ny]&&s[nx][ny]=='0'){
			isv[1][nx][ny]=1;
			handle2(nx,ny);
		}
	}
}

void solve(){
	int sum=0;
	memset(isv,0,sizeof(isv));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='1'&&!isv[0][i][j]){
				isv[0][i][j]=1;
				handle(i,j);
				sum++;
				if(sum>1){
					puts("-1");
					return ;
				}
			}
		}
	}
	if(sum==0){
		puts("-1");
		return ;
	}
	for(int i=0;i<m;i++){
		if(s[0][i]=='0'&&!isv[1][0][i]){
			isv[1][0][i]=1;
			handle2(0,i);
		}
	}
	for(int i=0;i<n;i++){
		if(s[i][0]=='0'&&!isv[1][i][0]){
			isv[1][i][0]=1;
			handle2(i,0);
		}	
	}
	for(int i=0;i<n;i++){
		if(s[i][m-1]=='0'&&!isv[1][i][m-1]){
			isv[1][i][m-1]=1;
			handle2(i,m-1);
		}	
	}
	for(int i=0;i<m;i++){
		if(s[n-1][i]=='0'&&!isv[1][n-1][i]){
			isv[1][n-1][i]=1;
			handle2(n-1,i);
		}	
	}
	sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='0'&&!isv[1][i][j]){
				sum++;
				isv[1][i][j]=1;
				handle2(i,j);
			}
		}
	}
	if(sum==1){
		puts("0");
	}
	else if(sum==0){
		puts("1");
	}
	else{
		puts("-1");
	}
}

int main(void){
	int sum;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		solve();
	}
	return 0;
}
