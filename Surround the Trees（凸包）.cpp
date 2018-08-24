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

const int maxsize=1e2+10;

struct node{
	ll x;
	ll y;
	bool operator <(const node &a)const{
		if(y<a.y)
			return 1;
		else if(y==a.y&&x<a.x)
			return 1;
		return 0;
	}
};

node p[maxsize],a[maxsize];

ll n,cnt;

ll cross(const node &a,const node &b,const node &c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);//x1*y2-x2*y1
}

void handle(){
	sort(a,a+n);
	ll i,j;
	cnt=0;
	for(i=0;i<n;i++){
		while(cnt>1&&cross(p[cnt-1],a[i],p[cnt-2])<=0)
			cnt--;//排除不符合条件的点
		p[cnt++]=a[i]; 
	}
	j=cnt;
	for(i=n-2;i>=0;i--){
		while(cnt>j&&cross(p[cnt-1],a[i],p[cnt-2])<=0)
			cnt--;
		p[cnt++]=a[i];
	}
	if(n>1)
		cnt--;
}

double len(const node &a,const node &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void solve(){
	ll i;
	handle();
	double ans=0;
	//deb(cnt);
	for(i=1;i<cnt;i++){
		ans+=len(p[i],p[i-1]);
	}
	if(cnt>2){
		ans+=len(p[0],p[cnt-1]);
	}
	printf("%.2lf\n",ans);
}

int main(void){
	ll i;
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lld %lld",&a[i].x,&a[i].y);
		solve();
	}
	return 0;
}
