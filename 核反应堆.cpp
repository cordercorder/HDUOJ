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

# define ll long long

using namespace std;

int n;

ll ans1,ans2;
ll temp;

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		if(n<0)
			break;
		ans1=1;
		ans2=0;
		for(i=0;i<n;i++){
			temp=ans1;
			ans1=ans2*2+ans1*3;
			ans2=temp+ans2;
		}
		printf("%lld, %lld\n",ans1,ans2);
	}
	return 0;
}
