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

const int maxsize=1e5+10;

struct node{
	int l;
	int r;
	int add;
	int sum;
	int mid(){
		return (l+r)>>1;
	}
}t[maxsize<<2];

int T;
int n,q;

void create(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	t[rt].add=0;
	if(l==r){
		t[rt].sum=1;
		return ;
	}
	create(rt<<1,l,t[rt].mid());
	create(rt<<1|1,t[rt].mid()+1,r);
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
}

void pushdown(int rt){
	if(t[rt].add){
		t[rt<<1].sum=(t[rt<<1].r-t[rt<<1].l+1)*t[rt].add;
		t[rt<<1|1].sum=(t[rt<<1|1].r-t[rt<<1|1].l+1)*t[rt].add;
		t[rt<<1].add=t[rt].add;
		t[rt<<1|1].add=t[rt].add;
		t[rt].add=0;
	}
}

void update(int rt,int l,int r,int val){
	if(l==t[rt].l&&r==t[rt].r){
		t[rt].sum=(t[rt].r-t[rt].l+1)*val;
		t[rt].add=val;
		return ;
	}
	pushdown(rt);
	if(r<=t[rt].mid()){
		update(rt<<1,l,r,val);
	}
	else if(l>t[rt].mid()){
		update(rt<<1|1,l,r,val);
	}
	else{
		update(rt<<1,l,t[rt].mid(),val);
		update(rt<<1|1,t[rt].mid()+1,r,val);
	}
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
}

int query(int rt,int l,int r){
	if(l==t[rt].l&&r==t[rt].r){
		return t[rt].sum;
	} 
	else if(r<=t[rt].mid()){
		return query(rt<<1,l,r);
	}
	else if(l>t[rt].mid()){
		return query(rt<<1|1,l,r);
	}
	else{
		return query(rt<<1,l,t[rt].mid())+query(rt<<1|1,t[rt].mid(),r);
	}
}

int main(void){
	int x,y,z,q;
	while(scanf("%d",&T)!=EOF){
		for(int i=1;i<=T;i++){
			scanf("%d",&n);
			scanf("%d",&q);
			create(1,1,n);
			while(q--){
				scanf("%d %d %d",&x,&y,&z);
				update(1,x,y,z);
			}
			printf("Case %d: The total value of the hook is %d.\n",i,t[1].sum);
		}
	}
	return 0;
}
