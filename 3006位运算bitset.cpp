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

const int maxn=1e2+10;

const int len=1<<14;

int n,m;

int bits[1<<14];

int main(void){
	int k,x;
	int tmp;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			tmp=0;
			for(int j=0;j<k;j++){
				scanf("%d",&x);
				tmp+=(1<<(x-1));
			}
			//deb(tmp);
			bits[tmp]=1;
			for(int j=0;j<len;j++){
				if(bits[j]){
					bits[j|tmp]=1;
				}
			}
		}
		int ans=0;
		for(int i=0;i<len;i++){
			if(bits[i])
				ans++;
		}
		printf("%d\n",ans);
		memset(bits,0,sizeof(bits));
	}
	return 0;
}
