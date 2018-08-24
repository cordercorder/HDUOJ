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

const int maxn=5e3+10;

struct node{
	int l;
	int w;
	bool operator<(const node &a)const{
		if(l<a.l)
			return 1;
		else if(l==a.l&&w<a.w)
			return 1;
		return 0;
	}
};

int t;
int n;
node a[maxn];
bool isv[maxn];

void solve(){
	int ans=0;
	node tmp;
	sort(a,a+n);
	memset(isv,0,sizeof(isv));
	for(int i=0;i<n;i++){
		if(!isv[i]){
			ans++;
			isv[i]=1;
			tmp=a[i];
			for(int j=i+1;j<n;j++){
				if(!isv[j]&&tmp.l<=a[j].l&&tmp.w<=a[j].w){
					isv[j]=1;
					tmp=a[j];
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main(void){
	
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%d %d",&a[i].l,&a[i].w);
			}
			solve();
		}
	}
	return 0;
}
