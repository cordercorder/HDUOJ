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

const int maxn=1e6+10;

struct node{
	int num;
	int pos;
};

int a[maxn];
int n,k;
node Max[maxn],Min[maxn];
int front1,back1,front2,back2; 
int ans1[maxn],cnt1,ans2[maxn],cnt2;

void solve(){
	front1=0;
	back1=0;
	front2=0;
	back2=0;
	cnt1=0;
	cnt2=0;
	for(int i=1;i<=k;i++){
		if(front1==back1){
			Max[++back1].num=a[i];
			Max[back1].pos=i;
		}
		else{
			while(front1<back1&&Max[back1].num<a[i]){
				--back1;
			}
			Max[++back1].num=a[i];
			Max[back1].pos=i;
		}
		if(front2==back2){
			Min[++back2].num=a[i];
			Min[back2].pos=i;
		}
		else{
			while(front2<back2&&Min[back2].num>a[i]){
				--back2;
			}
			Min[++back2].num=a[i];
			Min[back2].pos=i;
		}
	}
	ans1[++cnt1]=Max[front1+1].num;
	ans2[++cnt2]=Min[front2+1].num;
	for(int i=k+1;i<=n;i++){
		while(front1<back1&&Max[front1+1].pos+k<=i){
			++front1;
		}
		if(front1==back1){
			Max[++back1].num=a[i];
			Max[back1].pos=i;
		}
		else{
			while(front1<back1&&Max[back1].num<a[i]){
				--back1;
			}
			Max[++back1].num=a[i];
			Max[back1].pos=i;
		}
		ans1[++cnt1]=Max[front1+1].num;
		while(front2<back2&&Min[front2+1].pos+k<=i){
			++front2;
		}
		if(front2==back2){
			Min[++back2].num=a[i];
			Min[back2].pos=i;
		}
		else{
			while(front2<back2&&Min[back2].num>a[i]){
				--back2;
			}
			Min[++back2].num=a[i];
			Min[back2].pos=i;
		}
		ans2[++cnt2]=Min[front2+1].num;
	}
	printf("%d",ans2[1]);
	for(int i=2;i<=cnt2;i++){
		printf(" %d",ans2[i]);
	}
	puts("");
	printf("%d",ans1[1]);
	for(int i=2;i<=cnt1;i++){
		printf(" %d",ans1[i]);
	}
	puts("");
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
