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

const int maxsize=1e3+10;

int state[maxsize],n;

int INit(int n){
	int cnt=0,i;
	for(i=0;i<n;i++){
		if((i&(i>>1))==0)
			state[cnt++]=i;
	}
	return cnt;
} 


int main(void){
	int i,cnt;
	while(scanf("%d",&n)!=EOF){
		cnt=INit(n);
		for(i=0;i<cnt;i++){
			deb(state[i]);
		}
	}
	
	return 0;
}
