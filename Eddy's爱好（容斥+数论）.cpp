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

ll n,ans;

ll prime[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

const double eps=1e-8;

void dfs(ll cnt,ll x,ll bor,ll k){//x为所选择的数字的个数，bor为限定选择的数的个数 
	if(k>60)
		return ;
	if(x==bor){
		ll tmp=pow(n,1.0/(0.0+k))+eps-1;
		ans=ans+tmp;
		return ;
	}
	if(cnt>=17)
		return ;
	dfs(cnt+1,x,bor,k);//不选择第cnt个素数 
	dfs(cnt+1,x+1,bor,k*prime[cnt]);//选择第cnt个素数 
}

int main(void){
	ll res,i;
	while(scanf("%lld",&n)!=EOF){
		res=0;
		for(i=1;i<=3;i++){
			ans=0;
			dfs(0,0,i,1);
			if(i&1){
				res=res+ans;
			}
			else{
				res=res-ans;
			}
		}
		res=res+1;
		printf("%lld\n",res);
	}
	return 0;
}
