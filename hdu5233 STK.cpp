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

const int maxn=1e5+10;

struct node{
	int h;
	int id;
	bool operator<(const node &a)const{
		if(h<a.h)
			return 1;
		if(h==a.h&&id<a.id)
			return 1;
		return 0;
	}
};

int n,m;
int h[maxn],q[maxn];
set<node> res;
set<node>::iterator it;

int main(void){
	node tmp;
	int ans;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
			tmp.id=i;
			tmp.h=h[i];
			res.insert(tmp);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&q[i]);
			tmp.h=q[i];
			tmp.id=-1;
			it=res.lower_bound(tmp);
			if(it==res.end()||it->h!=q[i]){
				puts("-1");
				continue;
			}
			printf("%d\n",it->id);
			res.erase(it);
		}
	}
	return 0;
}
