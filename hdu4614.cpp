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

const int maxn=5e4+10;

int t;
int n,m;
int sum[maxn<<2],add[maxn<<2];

void create(int rt,int l,int r){
	add[rt]=0;
	if(l==r){
		sum[rt]=1;
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,int l,int r){
	if(add[rt]==1){
		int mid=(l+r)>>1;
		sum[rt<<1]=(mid-l+1);
		sum[rt<<1|1]=(r-mid);
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		add[rt]=0;
	}
	else if(add[rt]==-1){
		int mid=(l+r)>>1;
		sum[rt<<1]=0;
		sum[rt<<1|1]=0;
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		add[rt]=0;
	}
}

int query(int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		return sum[rt];
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

void update(int rt,int l,int r,int L,int R,bool f){
	if(l==L&&R==r){
		if(f){
			sum[rt]=(r-l+1);
			add[rt]=1;
		}
		else{
			sum[rt]=0;
			add[rt]=-1;
		}
		return ;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,f);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,f);
	}
	else{
		update(rt<<1,l,mid,L,mid,f);
		update(rt<<1|1,mid+1,r,mid+1,R,f);
	}
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

bool check(int st,int ed,int val){
	if(query(1,1,n,st,ed)>=val)
		return 1;
	return 0;
}

int Find(int st,int val){
	int l=st,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(st,mid,val)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}

int main(void){
	int k;
	int A,B,F;
	int tmp,pos;
	int L,R;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		create(1,1,n);
		while(m--){
			scanf("%d",&k);
			if(k==1){
				scanf("%d %d",&A,&F);
				++A;
				tmp=query(1,1,n,A,n);
				if(tmp==0){
					puts("Can not put any one.");
					continue;
				}
				if(tmp<F){
					F=tmp;
				}
				L=Find(A,1);
				R=Find(A,F);
				update(1,1,n,L,R,0);
				printf("%d %d\n",--L,--R);
			}
			else{
				scanf("%d %d",&A,&B);
				++A;
				++B;
				tmp=B-A+1-query(1,1,n,A,B);
				printf("%d\n",tmp);
				update(1,1,n,A,B,1);
			}
		}
		printf("\n");
	}
	return 0;
}
