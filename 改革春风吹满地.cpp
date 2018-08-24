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

# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

struct node{
	double x;
	double y;
	bool operator<(const node &a)const{
		if(y<a.y)
			return 1;
		else if(y==a.y&&x<a.x)
			return 1;
		return 0;
	}
};

ll n;
node p[maxsize];

double area(const node &a,const node &b,const node &c){
	return (a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y)/2.0;
}

void solve(){
	double ans=0,s;
	ll i;
	ans+=area(p[0],p[1],p[2]);
//	if(s<0)
//		s=-s;
//	ans+=s;
	//deb_d(ans);
	for(i=3;i<n;i++){
//		s=area(p[0],p[i-1],p[i]);
//		if(s<0)
//			s=-s;
//		deb_d(s);
		ans+=area(p[0],p[i-1],p[i]);
	}
	printf("%.1lf\n",ans);
}

int main(void){
	int i;
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		solve();
	}
	return 0;
}
