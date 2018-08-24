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

const int maxn=1e5+10;

struct node{
	int num;
	int pos;
	bool operator<(const node &a)const{
		return num<a.num;
	}
};

multiset<node> res;
multiset<node>::iterator it;

int n,m;
int cnt;

int main(void){
	node tmp;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&tmp.num);
			tmp.pos=i;
			res.insert(tmp);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&tmp.num);
			it=res.find(tmp);
			if(it==res.end()){
				puts("-1");
				continue;
			}
			printf("%d\n",it->pos);
			res.erase(it);
		}
		res.clear();
	}
	return 0;
}
