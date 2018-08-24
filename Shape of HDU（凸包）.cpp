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

# define deb(x) printf("# x=%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e6+10;

struct node{
	int x;
	int y;
	bool operator<(const node &a)const{
		if(y<a.y)
			return 1;
		else if(y==a.y&&x<a.x)
			return 1;
		return 0;
	}
}; 

node a[maxsize],p[maxsize];
int n,cnt;

int cross(const node &a,const node &b,const node &c){//计算叉积 
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

void solve(){
	int i,j;
	sort(a,a+n);
	cnt=0;
	for(i=0;i<n;i++){
		while(cnt>1&&cross(p[cnt-1],a[i],p[cnt-2])<=0)
			cnt--;
		p[cnt++]=a[i]; 
	}
	j=cnt;
	for(i=n-2;i>=0;i--){
		while(cnt>j&&cross(p[cnt-1],a[i],p[cnt-2])<=0)
			cnt--;
		p[cnt++]=a[i];
	}
	if(cnt>1)
		cnt--;//凸包上面点的数量 
	if(cnt==n)
		printf("convex\n");	
	else
		printf("concave\n");
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i].x,&a[i].y);
		solve();
	}
	return 0;
}
