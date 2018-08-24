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

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

int pre[maxsize],Max=0;
bool isv[maxsize];

void Init(){
	int i;
	for(i=1;i<maxsize;i++)
		pre[i]=i;
}

int Find(int x){
	return x==pre[x]?x:pre[x]=Find(pre[x]);//路径压缩 
}

bool Merge(const int &x,const int &y){
	int nx=Find(x),ny=Find(y);
	if(nx==ny)
		return 0;
	pre[ny]=nx;
	return 1;
}

bool check(){
	int i,cnt=0;
	for(i=1;i<=Max;i++){
		if(isv[i]&&pre[i]==i)
			cnt++;
		if(cnt>1)
			return 0;
	}
	if(cnt==1)
		return 1;
	return 0;
}

int main(void){
	int i;
	int x,y,sum=0;
	bool flag=0;
	Init();
	memset(isv,0,sizeof(isv));
	while(scanf("%d %d",&x,&y)!=EOF){
		if(x==-1&&y==-1)
			break;
		if(sum==0&&x==0&&y==0){
			printf("Yes\n");
			continue;
		}
		if(x==0&&y==0){
			if(flag){
				printf("No\n");
			}
			else{
				if(check()){
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
			Max=0;
			memset(isv,0,sizeof(isv));
			Init();
			flag=0;	
			sum=0;
			continue;
		}
		isv[x]=1;//出现过的结点 
		isv[y]=1;
		if(max(x,y)>Max){
			Max=max(x,y);//记录编号最大的结点 
		}
		if(!Merge(x,y)){
			flag=1;
		}
		else{
			sum++;
		}
	}
	return 0;
}
