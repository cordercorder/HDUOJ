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
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=20;

int n,ans;
char str[maxsize][maxsize];
bool isv[maxsize][maxsize];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool check(const int &x,const int &y){
	for(int i=x-1;i>=0;i--){
		if(str[i][y]=='1')
			return 0;
		else if(str[i][y]=='X')
			break;
	}
	for(int i=x+1;i<n;i++){
		if(str[i][y]=='1')
			return 0;
		else if(str[i][y]=='X')
			break;
	}
	for(int i=y+1;i<n;i++){
		if(str[x][i]=='1')
			return 0;
		else if(str[x][i]=='X')
			break;
	}
	for(int i=y-1;i>=0;i--){
		if(str[x][i]=='1')
			return 0;
		else if(str[x][i]=='X')
			break;
	}
	return 1;
}


void solve(int sum){
	ans=max(ans,sum);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(str[i][j]=='.'&&check(i,j)){
				str[i][j]='1';
				solve(sum+1);
				str[i][j]='.';
			}
		}
	}
}

int main(void){
	int nx,ny;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break; 
		for(int i=0;i<n;i++){
			scanf("%s",str[i]);
		}
		ans=0;	
		solve(0);
		//for(int i=0;i<n;i++){
		//	for(int j=0;j<n;j++){
		//		cout<<str[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}
		//cout<<endl;
		ccout(ans);
	}
	return 0;
}
