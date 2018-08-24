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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+100;

struct node{
	int l;
	int r;
	int add;//ÑÓ³Ù±ê¼Ç 
	int sum;
}t[maxsize<<3];

int n;

void create(int num,int l,int r){
	t[num].l=l;
	t[num].r=r;
	t[num].add=0;
	if(l==r){
		t[num].sum=0;
		return ;
	}
	int mid=(l+r)>>1;
	create(num<<1,l,mid);
	create(num<<1|1,mid+1,r);
	t[num].sum=t[num<<1].sum+t[num<<1|1].sum;
}

void pushdown(int num){
	if(t[num].add){
		t[num<<1].sum+=(t[num<<1].r-t[num<<1].l+1)*t[num].add;
		t[num<<1|1].sum+=(t[num<<1|1].r-t[num<<1|1].l+1)*t[num].add;
		t[num<<1].add+=t[num].add;
		t[num<<1|1].add+=t[num].add;
		t[num].add=0;
	}
}

void update(int num,int l,int r,int val){
	if(l<=t[num].l&&r>=t[num].r){
		t[num].sum+=(t[num].r-t[num].l+1)*val;
		t[num].add+=val;
		return ;
	}
	pushdown(num);
	if(l>t[num].r||r<t[num].l){
		return ;
	}
	update(num<<1,l,r,val);
	update(num<<1|1,l,r,val);
	t[num].sum=t[num<<1].sum+t[num<<1|1].sum;
}

int query(int num,int l,int r){
	if(l<=t[num].l&&r>=t[num].r){
		return t[num].sum;
	}
	pushdown(num);
	if(l>t[num].r||r<t[num].l){
		return 0;
	}
	return query(num<<1,l,r)+query(num<<1|1,l,r);
}

int main(void){
	int a,b;
	while(scanf("%d",&n)){
		if(n==0)
			break;
		create(1,1,n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			update(1,a,b,1);
		}
		printf("%d",query(1,1,1));
		for(int i=2;i<=n;i++){
			printf(" %d",query(1,i,i));
		}
		printf("\n");
	}
	return 0;
}
