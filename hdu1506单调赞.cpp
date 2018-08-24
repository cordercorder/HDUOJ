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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=1e5+10;

ll a[maxn];
ll L[maxn],R[maxn];
ll n;
stack<ll> s;

void handle(){
	while(!s.empty())
		s.pop();
}

template<typename T>
void print(T *a,ll n){
	for(ll i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(ll i=1;i<=n;i++){
			while(s.size()&&a[s.top()]>=a[i])
				s.pop();
			if(s.empty())
				L[i]=0;
			else
				L[i]=s.top();
			s.push(i);
		}
		handle();
		for(ll i=n;i>=1;i--){
			while(s.size()&&a[s.top()]>=a[i])
				s.pop();
			if(s.empty())
				R[i]=n+1;
			else
				R[i]=s.top();
			s.push(i);
		}
		//print(L,n);
		//print(R,n);
		handle();
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ans=max(ans,a[i]*(R[i]-L[i]-1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
