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

const int maxsize=1e6+10;

struct node{
	int l;
	int r;
	int Max;
	int add;
}t[maxsize<<3]; 

int k,q,T;
vector<int> p;

void create(int num,int l,int r){
	t[num].l=l;
	t[num].r=r;
	t[num].add=0;
	if(l==r){
		t[num].Max=0;
		return ;
	}
	int mid=(l+r)>>1;
	create(num<<1,l,mid);
	create(num<<1|1,mid+1,r);
	t[num].Max=max(t[num<<1].Max,t[num<<1|1].Max);
}

void pushdown(int num){
	if(t[num].add){
		t[num<<1].Max+=t[num].add;
		t[num<<1|1].Max+=t[num].add;
		t[num<<1].add+=t[num].add;
		t[num<<1|1].add+=t[num].add;
		t[num].add=0;
	}
}

void update(int num,int l,int r,int val){
	if(l==t[num].l&&t[num].r==r){
		t[num].add+=val;
		t[num].Max+=val;
		return ;
	}
	pushdown(num);//顺便向底层更新
	int mid=(t[num].l+t[num].r)>>1;
	if(r<=mid){
		update(num<<1,l,r,val);
	}
	else if(l>mid){
		update(num<<1|1,l,r,val);
	}
	else{
		update(num<<1,l,mid,val);
		update(num<<1|1,mid+1,r,val);
	}
	 t[num].Max=max(t[num<<1].Max,t[num<<1|1].Max);//向上返回，更新父节点区间 
}

int query(int num,int l,int r){
	if(t[num].l==l&&t[num].r==r){
		return t[num].Max;
	}
	pushdown(num);
	int mid=(t[num].l+t[num].r)>>1;
	if(r<=mid){
		return query(num<<1,l,r);
	}
	else if(l>mid){
		return query(num<<1|1,l,r);
	}
	else{
		return max(query(num<<1,l,mid),query(num<<1|1,mid+1,r));
	}
}

int main(void){
	int sum,tmp;
	int a,b;
	while(scanf("%d",&T)!=EOF){
		sum=0;
		while(T--){
			sum++;
			scanf("%d %d",&k,&q);
			create(1,1,1000000);
			for(int i=1;i<=q;i++){
				scanf("%d %d",&a,&b);
				tmp=query(1,a,b-1);
				if(tmp<k){
					p.push_back(i);
					update(1,a,b-1,1);
				}
			}
			printf("Case %d:\n",sum);;
			for(int i=0;i<p.size();i++){
				printf("%d ",p[i]);
			}
			printf("\n\n");
			p.clear();
		}
	}
	return 0;
}
