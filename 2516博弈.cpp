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

typedef long long ll;
typedef pair<int,int> pii;

vector<ll> f; 
ll n;

int main(void){
	f.push_back(0);
	f.push_back(1);
	f.push_back(1);
	for(ll i=3;;i++){
		f.push_back(f[i-1]+f[i-2]);
		if(f[i]>1e10){
			break;
		}
	}
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		ll pos=lower_bound(f.begin(),f.end(),n)-f.begin();
		if(pos!=(ll)f.size()&&f[pos]==n){
			puts("Second win");
		}
		else{
			puts("First win");
		}
	}
	return 0;
}
