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

const int maxn=5e4+10;

struct node{
	int l;
	int r;
	int l_len;
	int r_len;
	int t_len;
}t[maxn<<2];

int n,m;
int st[maxn],cnt;

void create(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	t[rt].l_len=t[rt].r_len=t[rt].t_len=r-l+1;
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
}

void update(int rt,int x,int val){
	if(t[rt].l==t[rt].r){
		if(val==1){
			t[rt].l_len=t[rt].r_len=t[rt].t_len=1;
		}
		else{
			t[rt].l_len=t[rt].r_len=t[rt].t_len=0;
		}
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(x<=mid){
		update(rt<<1,x,val);
	}
	else{
		update(rt<<1|1,x,val);
	}
	t[rt].t_len=max(t[rt<<1].t_len,t[rt<<1|1].t_len);
	t[rt].t_len=max(t[rt].t_len,t[rt<<1].r_len+t[rt<<1|1].l_len);
	t[rt].l_len=t[rt<<1].l_len;
	t[rt].r_len=t[rt<<1|1].r_len;
	if(t[rt<<1].l_len==t[rt<<1].r-t[rt<<1].l+1){//左区间完全可用 
		t[rt].l_len=t[rt<<1].l_len+t[rt<<1|1].l_len;
	}
	if(t[rt<<1|1].r_len==t[rt<<1|1].r-t[rt<<1|1].l+1){
		t[rt].r_len=t[rt<<1|1].r_len+t[rt<<1].r_len;
	}
}

int query(int rt,int x){
	if(t[rt].l==t[rt].r||t[rt].t_len==0||t[rt].t_len==t[rt].r-t[rt].l+1)
		return t[rt].t_len;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(x<=mid){
		int index=mid-t[rt<<1].r_len+1;
		if(index<=x){
			return query(rt<<1,x)+query(rt<<1|1,mid+1);
		}
		else{
			return query(rt<<1,x);
		}
	}
	else{
		int index=mid+t[rt<<1|1].l_len;
		if(index>=x){
			return query(rt<<1|1,x)+query(rt<<1,mid);
		}
		else{
			return query(rt<<1|1,x);
		}
	}
}

int main(void){
	char s[10];
	int x;
	while(scanf("%d %d",&n,&m)!=EOF){
		create(1,1,n);
		cnt=0;
		while(m--){
			scanf("%s",s);
			if(s[0]=='D'){
				scanf("%d",&x);
				st[cnt++]=x;
				update(1,x,0);
			}
			else if(s[0]=='Q'){
				scanf("%d",&x);
				printf("%d\n",query(1,x));
			}
			else{
				x=st[--cnt];
				update(1,x,1);
			}
		}
	}
	return 0;
}
