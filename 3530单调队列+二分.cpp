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

int n,m,k;

struct node{
	int num;
	int pos;
};

node Max[maxn],Min[maxn];
int a[maxn]; 

void solve(){
	int front1=0,front2=0,back1=0,back2=0;
	int tmp;
	int ans=0,index=0;
	for(int i=1;i<=n;i++){
		while(front1<back1&&Max[back1].num<a[i]){
			--back1;
		}
		Max[++back1].num=a[i];
		Max[back1].pos=i;
		while(front2<back2&&Min[back2].num>a[i]){
			--back2;
		}
		Min[++back2].num=a[i];
		Min[back2].pos=i;
		while(front1<back1&&front2<back2&&(Max[front1+1].num-Min[front2+1].num)>k){
			if(Max[front1+1].pos<Min[front2+1].pos){
				index=Max[front1+1].pos;
				++front1;
			}
			else{
				index=Min[front2+1].pos;
				++front2;
			}
		}
		if(front1<back1&&front2<back2&&Max[front1+1].num-Min[front2+1].num>=m)
			ans=max(ans,i-index);
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);	
		}
		if(m>k){
			puts("0");
			continue;
		}
		solve();
	}
	return 0;
}
