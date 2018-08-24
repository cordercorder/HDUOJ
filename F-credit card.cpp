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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

int a[maxsize];
int d,n;

int main(void){
	int sum=0,ans=0,res=0;
	bool flag=0;
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0){
			sum+=a[i];
			res+=a[i];
		}
		else if(a[i]>0){
			sum+=a[i];
			if(sum>d){
				puts("-1");
				return 0;
			}
			res+=a[i];
			res=(res>d?d:res);
		}
		else{
			sum=(sum<0?0:sum);
			if(res<0){
				res=d;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
