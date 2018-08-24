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

const int maxsize=1e5+10;

struct node{
	ll l;
	ll r;
	ll sum;
};

node t[maxsize<<2];

ll a[maxsize];
ll n,m;

void create(ll num,ll l,ll r){
	t[num].l=l;
	t[num].r=r;
	if(l==r){
		t[num].sum=a[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(num<<1,l,mid);
	create(num<<1|1,mid+1,r);
	t[num].sum=t[num<<1].sum+t[num<<1|1].sum;
}

void update(ll num,ll l,ll r){
	if(t[num].l==t[num].r){
		t[num].sum=sqrt(t[num].sum);
		return ;
	}
	if(t[num].sum<=t[num].r-t[num].l+1)
		return ;
	ll mid=(t[num].l+t[num].r)>>1;
	if(r<=mid){
		update(num<<1,l,r);
	}
	else if(l>mid){
		update(num<<1|1,l,r);
	}
	else{
		update(num<<1,l,mid);
		update(num<<1|1,mid+1,r);
	}
	t[num].sum=t[num<<1].sum+t[num<<1|1].sum;
}

ll query(ll num,ll l,ll r){
	if(t[num].l==l&&t[num].r==r){
		return t[num].sum;
	}
	ll mid=(t[num].l+t[num].r)>>1;
	if(r<=mid){
		return query(num<<1,l,r);
	}
	else if(l>mid){
		return query(num<<1|1,l,r);
	}
	else{
		return query(num<<1,l,mid)+query(num<<1|1,mid+1,r);
	}
}


int main(void){
	ll tmp,l,r;
	ll sum=0;
	while(scanf("%lld",&n)!=EOF){
		sum++;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		create(1,1,n);
		scanf("%lld",&m);
		printf("Case #%d:\n",sum);
		while(m--){
			scanf("%lld %lld %lld",&tmp,&l,&r);
			if(tmp==0){
				update(1,min(l,r),max(l,r));
			}
			else{
				printf("%lld\n",query(1,min(l,r),max(l,r)));
			}
		}
		printf("\n");
	}
	return 0;
}
