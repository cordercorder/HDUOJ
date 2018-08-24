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

const int maxn=1e3+10;

struct node{
	int x;
	int y;
	int z;
	bool operator<(const node &a)const{
		if(x<a.x&&y<a.y)
			return 1;
		return 0;
	}
};

node a[maxn];
int cnt;
int d[3];
int n;

bool cmp(const node &a,const node &b){
	if(a.x<b.x)
		return 1;
	else if(a.x==b.x&&a.y<b.y)
		return 1;
	return 0;
}

void solve(){
	int ans=0,sum;
	node tmp;
	for(int i=0;i<cnt;i++){
		tmp=a[i];
		sum=a[i].z;
		for(int j=i+1;j<cnt;j++){
			if(tmp<a[j]){
				tmp=a[j];
				sum+=a[j].z;
			}
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
}

int main(void){
	int sum=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&d[0],&d[1],&d[2]);
			sort(d,d+3);
			a[cnt].x=d[0];  a[cnt].y=d[1];  a[cnt++].z=d[2];
			a[cnt].x=d[0];  a[cnt].y=d[2];  a[cnt++].z=d[1];
			a[cnt].x=d[1];  a[cnt].y=d[2];  a[cnt++].z=d[0];
		}
		sort(a,a+cnt,cmp);
		sum++;
		printf("Case %d: maximum height = ",sum);
		solve();
	}
	return 0;
}
