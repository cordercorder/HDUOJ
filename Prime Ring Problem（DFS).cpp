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

const int maxsize=45;

int prime[12]={2,3,5,7,11,13,17,19,23,29,31,37};

int n;
int a[maxsize];
bool isv[maxsize];

bool check(int num){//判断是否是质数 
	int l=0,r=11,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(num<=prime[mid]){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(prime[l]==num)
		return 1;
	return 0;
}

void solve(int x){
	if(x>n){		
		printf("%d",a[1]);
		for(int i=2;i<=n;i++){
			printf(" %d",a[i]);
		}
		printf("\n");
		return ;
	}
	int i;
	for(i=2;i<=n;i++){
		//deb(i);
		if(!isv[i]&&check(i+a[x-1])){
			if(x==n){
				if(check(a[1]+i)){
					a[x]=i;
					isv[i]=1;
					solve(x+1);
					isv[i]=0;
				}
			}
			else{
				a[x]=i;
				isv[i]=1;
				solve(x+1);
				isv[i]=0;
			}
		}
	}
}

int main(void){
	int i,sum=0;
	while(scanf("%d",&n)!=EOF){
		sum++;
		memset(isv,0,sizeof(isv));
		a[1]=1;
		isv[1]=1;
		printf("Case %d:\n",sum);
		solve(2);
		printf("\n");
	}
	return 0;
}
