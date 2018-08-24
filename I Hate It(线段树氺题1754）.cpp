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

int n,m;
int a[maxn];

struct node{
	int l;
	int r;
	int Max;
}t[maxn<<2];

void create(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].Max=a[l];
		return;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	t[rt].Max=max(t[rt<<1].Max,t[rt<<1|1].Max);
}

int query(int rt,int l,int r){
	if(t[rt].l==l&&t[rt].r==r){
		return t[rt].Max;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(r<=mid){
		return query(rt<<1,l,r);
	}
	else if(l>mid){
		return query(rt<<1|1,l,r);
	}
	else{
		return max(query(rt<<1,l,mid),query(rt<<1|1,mid+1,r));
	}
}

void update(int rt,int x,int val){
	if(t[rt].l==x&&t[rt].r==x){
		t[rt].Max=val;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(x<=mid){
		update(rt<<1,x,val);
	}
	else{
		update(rt<<1|1,x,val);
	}
	t[rt].Max=max(t[rt<<1].Max,t[rt<<1|1].Max);
}

int main(void){
	int l,r;
	char s[10];
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		create(1,1,n);
		while(m--){
			scanf("%s %d %d",s,&l,&r);
			if(s[0]=='Q'){
				printf("%d\n",query(1,l,r));
			}
			else{
				update(1,l,r);
			}
		}
	}
	return 0;
}
