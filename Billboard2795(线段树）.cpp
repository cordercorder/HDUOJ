# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=2e5+10;

struct node{
	int l;
	int r;
	int Max;
	int mid(){
		return (l+r)>>1;
	}
}t[maxn<<2];

int h,w,n;

void create(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].Max=w;
		return ;
	}
	int mid=t[rt].mid();
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	t[rt].Max=t[rt<<1].Max;
}

int query(int rt,int x){
	if(t[rt].l==t[rt].r){
		t[rt].Max-=x;
		return t[rt].l;
	}
	int mid=t[rt].mid();
	int res;
	if(t[rt<<1].Max>=x){
		res=query(rt<<1,x);
	}
	else{
		res=query(rt<<1|1,x);
	}
	t[rt].Max=max(t[rt<<1].Max,t[rt<<1|1].Max);
	return res;
}

int main(void){
	int x;
	while(scanf("%d %d %d",&h,&w,&n)!=EOF){
		create(1,1,min(h,n));
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(t[1].Max<x){
				puts("-1");
				continue;
			}
			printf("%d\n",query(1,x));
		}
	}
	return 0;
}
