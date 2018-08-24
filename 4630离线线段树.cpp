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

const int maxn=5e4+10;

int a[maxn];
int t,n;
int Max[maxn<<2];
int Q;
int isv[maxn],ans[maxn];

struct node{
	int l;
	int r;
	int id;
	bool operator<(const node &a)const{
		return r<a.r;
	}
}qur[maxn];

void update(int rt,int l,int r,int pos,int val){
	if(l==r){
		Max[rt]=max(val,Max[rt]);
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(rt<<1,l,mid,pos,val);
	}
	else{
		update(rt<<1|1,mid+1,r,pos,val);
	}
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}

int query(int rt,int l,int r,int L,int R){
	if(l==L&&r==R){
		return Max[rt];
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return max(query(rt<<1,l,mid,L,mid),query(rt<<1|1,mid+1,r,mid+1,R));
	}
}

void solve(){
	sort(qur+1,qur+1+Q);
	memset(isv,-1,sizeof(isv));
	memset(Max,0,sizeof(Max));
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				if(isv[j]!=-1){
					update(1,1,n,isv[j],j);
				}
				if(a[i]/j!=j&&isv[a[i]/j]!=-1){
					update(1,1,n,isv[a[i]/j],a[i]/j);
				}
				isv[j]=i;
				isv[a[i]/j]=i;
			}
		}
		while(cnt<=Q&&qur[cnt].r<=i){
			ans[qur[cnt].id]=query(1,1,n,qur[cnt].l,qur[cnt].r);
			cnt++;
		}
	}
	for(int i=1;i<=Q;i++){
		printf("%d\n",ans[i]);
	}
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		scanf("%d",&Q);
		for(int i=1;i<=Q;i++){
			scanf("%d %d",&qur[i].l,&qur[i].r);
			qur[i].id=i;
		}
		solve();
	}
	return 0;
}
