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

const int maxsize=1e3+10;
const double maxw=1e9;

struct node{
	int J;
	int F;
	double c;	
};

node a[maxsize];
int n,m;

bool cmp(const node &a,const node &b){
	return a.c>b.c;
}

int main(void){
	int i,lef,tmp;
	double ans;
	while(scanf("%d %d",&m,&n)!=EOF){
		if(n==-1&&m==-1)
			break;
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i].J,&a[i].F);
			if(a[i].F==0){
				a[i].c=maxw;
				continue;
			}
			a[i].c=(a[i].J*1.0)/a[i].F;
			//printf("%lf\n",a[i].c);			
		}
		sort(a,a+n,cmp);
		ans=0;
		lef=m;
		for(i=0;i<n;i++){
			if(a[i].c==maxw){
				ans=ans+a[i].J;
				continue;
			}
			tmp=min(a[i].F,lef);
			lef=lef-tmp;
			ans=ans+(tmp)*a[i].c;
			if(lef==0)
				break; 
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
