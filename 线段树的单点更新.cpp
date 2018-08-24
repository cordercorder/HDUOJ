# include<iostream>
# include<algorithm>
# include<cstdlib>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

using namespace std;

const int maxsize=5e4+10;

struct node{
	int l;
	int r;
	int sum;
}; 

node t[maxsize*4];
int a[maxsize];
int T,N;
char str[20];

void create(int num,int l,int r){//线段树的构造 
	t[num].l=l;
	t[num].r=r;
	if(l==r){
		t[num].sum=a[l];
		return ;
	}
	int mid=(l+r)/2;
	create(num*2,l,mid);
	create(num*2+1,mid+1,r);
	t[num].sum=t[num*2].sum+t[num*2+1].sum;
}

void add(int num,int x,int a){//线段树的单点更新 
	t[num].sum=t[num].sum+a;
	if(t[num].l==x&&t[num].r==x){
		return ;
	}
	int mid=(t[num].l+t[num].r)/2;
	if(x<=mid){
		add(num*2,x,a);
	}
	else{
		add(num*2+1,x,a);
	}
}

int query(int num,int l,int r){//线段树的区间求和 
	if(t[num].l==l&&t[num].r==r){
		return t[num].sum;
	}
	int mid=(t[num].l+t[num].r)/2;
	if(r<=mid){
		return query(num*2,l,r);
	}
	else if(l>mid){
		return query(num*2+1,l,r);
	}
	else{
		return query(num*2,l,mid)+query(num*2+1,mid+1,r);
	}
}

int main(void){
	int i,x,b,l,r,cnt;
	while(scanf("%d",&T)!=EOF){
		cnt=0;
		while(T--){
			scanf("%d",&N);
			for(i=1;i<=N;i++)
				scanf("%d",&a[i]);
			create(1,1,N);
			cnt++;
			printf("Case %d:\n",cnt);
			while(scanf("%s",str)!=EOF){
				if(!strcmp(str,"End"))
					break;
				else if(!strcmp(str,"Query")){
					scanf("%d %d",&l,&r);
					printf("%d\n",query(1,l,r));
				}
				else if(!strcmp(str,"Add")){
					scanf("%d %d",&x,&b);
					add(1,x,b);
				}
				else if(!strcmp(str,"Sub")){
					scanf("%d %d",&x,&b);
					add(1,x,-b);
				}
			}
		}
	}
	return 0;
}
