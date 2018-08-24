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

const int maxsize=5e4+10;

struct node{
	int x;
	int y;
};

node p[maxsize],a[maxsize];
int n,cnt;

int cross(const node &a,const node &b,const node &c){//求叉积 
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

bool cmp(const node &a,const node &b){
	if(a.y<b.y)
		return 1;
	else if(a.y==b.y&&a.x<b.x)
		return 1;
	return 0;	
}

void solve(){
	int i,temp;
	cnt=0;
	sort(p,p+n,cmp);
	for(i=0;i<n;i++){//求上凸包 
		while(cnt>1&&cross(a[cnt-1],p[i],a[cnt-2])<=0)
			cnt--;
		a[cnt++]=p[i];
	}
	temp=cnt;
	for(i=n-2;i>=0;i--){
		while(cnt>temp&&cross(a[cnt-1],p[i],a[cnt-2])<=0)
			cnt--;
		a[cnt++]=p[i];
	}
	if(cnt>1)
		cnt--;//去除重复点 
}

double area(const node &a,const node &b,const node &c){
	return abs((a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-c.x*b.y-b.x*a.y))/2.0;
}

int main(void){
	int i,j,k;
	double ans;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d %d",&p[i].x,&p[i].y);
		solve();
		ans=0;
		for(i=0;i<cnt;i++){
			for(j=i+1;j<cnt;j++){
				for(k=j+1;k<cnt;k++){
					ans=max(ans,area(a[i],a[j],a[k]));
				}
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
