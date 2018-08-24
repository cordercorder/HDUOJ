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

# define ll long long

using namespace std;

int a,b;

const int maxsize=1e2+10;

int ans[maxsize];

void solve(){
	int i,cnt=0;
	for(i=0;i<100;i++){
		if((a+i)%b==0){
			ans[cnt++]=i;
		}
	}
	if(cnt>0)
		printf("%02d",ans[0]);
	for(i=1;i<cnt;i++){
		printf(" %02d",ans[i]);
	}
	printf("\n");
}

int main(void){
	int i;
	while(scanf("%d %d",&a,&b)){
		if(a==0&&b==0){
			break;
		}
		a=a*100;
		solve();
	}
	return 0;
}
