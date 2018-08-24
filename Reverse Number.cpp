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

typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

ll t,n;

ll num[maxsize];

void solve(){
	ll tmp=n,m=1,cnt=0,i,j;
	if(tmp<0){
		printf("-");
		tmp=-tmp;
	}
	while(m<=tmp){
		num[cnt++]=(tmp/m)%10;
		m=m*10;
	}
	for(i=0;i<cnt&&num[i]==0;i++);//ÅÅ³ý½áÎ²µÄ0 
	j=i;
	for(;j<cnt;j++){
		printf("%d",num[j]);
	}
	for(j=0;j<i;j++){
		printf("%d",num[j]);
	}
	printf("\n");
}

int main(void){
	ll i;
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld",&n);
			if(n==0){
				printf("0\n");
				continue;
			}
			solve();
		}
	}
	return 0;
}
