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
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

int t;
int n,k;
int x[maxn];

void solve(){
	sort(x+1,x+1+n);
	int pos;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		pos=upper_bound(x+i+1,x+1+n,x[i]+k)-x;
		ans+=pos-i-1;
	}
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d",&n,&k);
			for(int i=1;i<=n;i++){
				scanf("%d",&x[i]);
			}
			solve();
		}
	}
	return 0;
}
