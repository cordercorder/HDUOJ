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

const int maxsize=1e9;

int t;
ll n;
vector<ll> p;
vector<ll> c[4];

ll q_mod(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1){
			ans=ans*x;
		}
		y>>=1;
		x=x*x;
	}
	return ans;
}

void handle(){
	ll i=0;
	ll tmp;
	while((tmp=q_mod(ll(2),i))<=1e10){
		c[0].push_back(tmp);
		i++; 
	}
	i=0;
	while((tmp=q_mod(ll(3),i))<=1e10){
		c[1].push_back(tmp);
		i++;
	}
	i=0;
	while((tmp=q_mod(ll(5),i))<=1e10){
		c[2].push_back(tmp);
		i++;
	}
	i=0;
	while((tmp=q_mod(ll(7),i))<=1e10){
		c[3].push_back(tmp);
		i++;
	}
	//cout<<c[0].size()<<endl;
	//cout<<c[1].size()<<endl;
	//cout<<c[2].size()<<endl;
	//cout<<c[3].size()<<endl;
}

void solve(){
	ll tmp;
	for(ll i=0;i<c[0].size();i++){
		for(ll j=0;j<c[1].size();j++){
			for(ll k=0;k<c[2].size();k++){
				for(ll u=0;u<c[3].size();u++){
					tmp=c[0][i]*c[1][j]*c[2][k]*c[3][u];
					if(tmp>=1e10||tmp<=0)
						continue;
					p.push_back(tmp);
				}
			}
		}
	}
	sort(p.begin(),p.end());
}

int main(void){
	handle();
	solve();
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%lld",&n);
			printf("%lld\n",*lower_bound(p.begin(),p.end(),n));
		}
	}
	return 0;
}
