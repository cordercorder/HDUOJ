#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e5+10;

struct node{
	ll num;
	ll pos;
};

node Q[maxn];
ll n,c;
ll t;
ll buy[maxn],sell[maxn];
ll a[maxn];


void solve(){
	
	
	
	
	
	
}



int main(void){
	
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&c);
		a[0]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(ll i=0;i<=n;i++){
			scanf("%lld %lld",&buy[i],&sell[i]);
		}
		
		
	}
	
	
	return 0;
}
