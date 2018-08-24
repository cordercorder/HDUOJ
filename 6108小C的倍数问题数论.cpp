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

int t;
int p; 

int solve(int x){
	int ans=0;
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0){
			//cout<<"i=="<<i<<endl;
			ans++;
			int j=x/i;
			if(j!=i){
				ans++;
			}
		}
	} 
	return ans;
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&p);
		printf("%d\n",solve(p-1));
	}
	return 0;
}
