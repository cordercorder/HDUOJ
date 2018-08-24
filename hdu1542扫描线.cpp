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

const int maxn=505;

int add[maxn<<2];
double x[maxn<<2],sum[maxn<<2];
int n;
int cnt;

struct node{
	double l,r,h;
	int f;
	node(){}
	node(double a,double b,double c,int d):l(a),r(b),h(c),f(d){}
	bool operator<(const node &a)const{
		return h<a.h;
	}
}seg[maxn];

void push_up(int rt,int l,int r){
	if(add[rt]){
		sum[rt]=x[r+1]-x[l];
	}
	else if(l==r){
		sum[rt]=0;
	}
	else{
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}
}

void update(int rt,int l,int r,int L,int R,int val){
	if(l==L&&r==R){
		add[rt]+=val;
		push_up(rt,l,r);
		return ;
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,val);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,val);
	}
	else{
		update(rt<<1,l,mid,L,mid,val);
		update(rt<<1|1,mid+1,r,mid+1,R,val);
	}
	push_up(rt,l,r);
}

int main(void){
	double a,b,c,d;
	double ans;
	int len;
	int nl,nr;
	int kk=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		cnt=0;
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
			x[cnt]=a;
			seg[cnt++]=node(a,c,b,1);
			x[cnt]=c;
			seg[cnt++]=node(a,c,d,-1);
		}
		sort(x,x+cnt);
		sort(seg,seg+cnt);
		len=unique(x,x+cnt)-x;
		memset(add,0,sizeof(add));
		memset(sum,0,sizeof(sum));
		ans=0;
		for(int i=0;i<cnt-1;i++){
			nl=lower_bound(x,x+len,seg[i].l)-x;
			nr=lower_bound(x,x+len,seg[i].r)-x-1;
			update(1,0,len-1,nl,nr,seg[i].f);
			deb(nl);
			deb(nr);
			
			ans+=(sum[1]*(seg[i+1].h-seg[i].h));
		}
		printf("Test case #%d\n",++kk);
		printf("Total explored area: %.2lf\n",ans);
		puts("");
	}
	return 0;
}
