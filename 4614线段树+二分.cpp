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

int t,n,m;
int sum[maxn<<2];
int isv[maxn<<2];

void pushdown(int rt,int l,int r){
	if(isv[rt]==1){
		int mid=(l+r)>>1;
		sum[rt<<1]=(mid-l+1);
		sum[rt<<1|1]=(r-mid);
		isv[rt<<1]=isv[rt];
		isv[rt<<1|1]=isv[rt];
		isv[rt]=0;
	}
	else if(isv[rt]==-1){
		sum[rt<<1]=0;
		sum[rt<<1|1]=0;
		isv[rt<<1]=isv[rt];
		isv[rt<<1|1]=isv[rt];
		isv[rt]=0;
	}
}

int query(int rt,int l,int r,int L,int R){
	if(L==l&&R==r){
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

void update(int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		sum[rt]=(r-l+1);
		isv[rt]=1;
		return ;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R);
	}
	else{
		update(rt<<1,l,mid,L,mid);
		update(rt<<1|1,mid+1,r,mid+1,R);
	}
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int clear_(int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		int res=sum[rt];
		sum[rt]=0;
		isv[rt]=-1;
		return res;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	int res;
	if(R<=mid){
		res=clear_(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		res=clear_(rt<<1|1,mid+1,r,L,R);
	}
	else{
		res=clear_(rt<<1,l,mid,L,mid)+clear_(rt<<1|1,mid+1,r,mid+1,R);
	}
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	return res;
}

int Find(int l,int val){
	int nl=l,nr=n;
	int mid;
	while(nl<nr){
		mid=(nl+nr)>>1;
		if((mid-l+1-query(1,1,n,l,mid))>=val){
			nr=mid;
		}
		else{
			nl=mid+1;
		}
	}
	return nl;
}

int main(void){
	int K,A,B;
	int st,ed;
	int tmp;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		memset(sum,0,sizeof(sum));
		memset(isv,0,sizeof(isv));
		while(m--){
			scanf("%d %d %d",&K,&A,&B);
			++A;
			if(K==1){
				tmp=query(1,1,n,A,n);
				if(tmp==(n-A+1)){
					puts("Can not put any one.");
					continue;
				}
				st=Find(A,1);
				//deb(tmp);
				if(n-A+1-tmp<B){
					ed=Find(A,n-A+1-tmp);
				}
				else{
					ed=Find(A,B);
				}
				update(1,1,n,st,ed);
				--st;
				--ed;
				printf("%d %d\n",st,ed);
			}
			else{
				++B;
				printf("%d\n",clear_(1,1,n,A,B));
			}
		}
		puts("");
	}
	return 0;
}
