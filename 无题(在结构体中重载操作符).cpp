# include<iostream>
# include<algorithm>
# include<cstring>
# include<cstdlib>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

using namespace std;

const int maxsize=1e2+10; 

struct node{
	int num;
	int sum;
	int p;
};

int t;
int n,m;
node a[maxsize];

bool cmp(const node &a,const node &b){
	if(a.p<b.p)
		return 1;
	else if(a.p==b.p&&a.sum>b.sum)
		return 1;
	return 0;
}

void solve(const int &x){
	int i;
	for(i=0;i<n;i++){
		if(x<=a[i].sum){
			a[i].sum=a[i].sum-x;
			printf("%d\n",a[i].num);
			return ;
		}
	}
	printf("sorry\n");
}

int main(void){
	int i,x;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(i=0;i<n;i++){
				scanf("%d %d %d",&a[i].num,&a[i].sum,&a[i].p);
			}
			scanf("%d",&m);
			sort(a,a+n,cmp);
			while(m--){
				scanf("%d",&x);
				solve(x);
			}
		}
	}
	return 0;
}
