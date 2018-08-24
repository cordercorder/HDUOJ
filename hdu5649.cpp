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
	int l;
	int r;
	int opt;
}Q[maxn];

int t;
int n,m;
int a[maxn];
int k;
int res[maxn];
int T[maxn<<2],add[maxn<<2];

void create(int rt,int l,int r){
	add[rt]=0;
	if(l==r){
		T[rt]=res[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

void pushdown(int rt,int l,int r){
	if(add[rt]){
		int mid=(l+r)>>1;
		T[rt<<1]=(mid-l+1)*(add[rt]-1); 
		T[rt<<1|1]=(r-mid)*(add[rt]-1);
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		add[rt]=0;
	}
}

void update(int rt,int l,int r,int L,int R,int val){
	if(l==L&&R==r){
		T[rt]=val*(r-l+1);
		add[rt]=val+1;
		return ;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,val);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,val);
	}
	else{
		update(rt<<1,l,mid,L,mid,val);
		update(rt<<1|1,mid+1,r,mid+1,R,val);
	}
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

int query(int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		return T[rt];
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return query(rt<<1,l,mid,L,mid)+query(rt<<1|1,mid+1,r,mid+1,R);
	}
}

void pre_handle(int x){
	for(int i=1;i<=n;i++){
		if(a[i]>=x){
			res[i]=1;
		}
		else{
			res[i]=0;
		}
	}
	create(1,1,n);
}

bool check(int x){
	pre_handle(x);
	int tmp,ret;
	for(int i=1;i<=m;i++){
		tmp=query(1,1,n,Q[i].l,Q[i].r);//number of 1
		ret=Q[i].r-Q[i].l+1-tmp;//number of 0
		if(Q[i].opt==0){
			if(Q[i].l<=Q[i].l+ret-1)
				update(1,1,n,Q[i].l,Q[i].l+ret-1,0);
			if(Q[i].l+ret<=Q[i].r)
				update(1,1,n,Q[i].l+ret,Q[i].r,1);
		}
		else{
			if(Q[i].l<=Q[i].l+tmp-1)
				update(1,1,n,Q[i].l,Q[i].l+tmp-1,1);
			if(Q[i].l+tmp<=Q[i].r)
				update(1,1,n,Q[i].l+tmp,Q[i].r,0);
		}	
	}
	if(query(1,1,n,k,k)==1)
		return 1;
	return 0;
}

void solve(){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(!check(l)){
		l--;
	}
	printf("%d\n",l);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&Q[i].opt,&Q[i].l,&Q[i].r);
		}
		scanf("%d",&k);
		solve();
	}
	return 0;
}
