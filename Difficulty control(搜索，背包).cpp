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

# define ll long long

using namespace std;

const int maxsize=1e4+10;

struct node{
	char id[5];
	int df;
};

int n,m,cnt;
 
node a[maxsize];

int Min(int a,int b){
	if(abs(a-m)<abs(b-m)){
		return a;
	}
	else{
		return b;
	}
}

int solve(int x,int sum){
	if(x>=n){
		return sum;
	}
	int res;
	res=Min(solve(x+1,sum+a[x].df),solve(x+1,sum));
	printf("res=%d\n",res);
	
	return res;
}

int main(void){
	int i;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=0;i<3;i++){
			scanf("%s %d",a[i].id,&a[i].df);
		}
		printf("the ans is %d\n",solve(0,0));		
	}
	return 0;
}
