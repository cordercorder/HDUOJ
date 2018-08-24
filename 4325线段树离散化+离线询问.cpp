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

const int maxn=1e5+10;
const int maxn_n=3*maxn;

int t;
int st[maxn],ed[maxn];
int n,m;
int res[maxn_n];
int cnt;
int ask[maxn];
int T[maxn_n<<2],add[maxn_n<<2];

void pushdown(int rt,int l,int r){
	if(add[rt]){
		int mid=(l+r)>>1;
		T[rt<<1]+=(mid-l+1)*add[rt];
		T[rt<<1|1]+=(r-mid)*add[rt];
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		add[rt]=0;
	}
}

void update(int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		T[rt]+=(r-l+1);
		add[rt]+=1;
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
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

int query(int rt,int l,int r,int pos){
	if(l==r){
		return T[rt];
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(pos<=mid){
		return query(rt<<1,l,mid,pos);
	}
	else{
		return query(rt<<1|1,mid+1,r,pos);
	}
}

void solve(){
	memset(T,0,sizeof(T));
	memset(add,0,sizeof(add));
	sort(res+1,res+1+cnt);
	int len=unique(res+1,res+1+cnt)-res-1,tmp;
	int nl,nr;
	for(int i=1;i<=n;i++){
		nl=lower_bound(res+1,res+1+len,st[i])-res;
		nr=lower_bound(res+1,res+1+len,ed[i])-res;
		update(1,1,len,nl,nr);
	}
	int pos;
	for(int i=1;i<=m;i++){
		pos=lower_bound(res+1,res+1+len,ask[i])-res;
		printf("%d\n",query(1,1,len,pos));
	}
}

int main(void){
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d %d",&n,&m);
		cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&st[i],&ed[i]);
			res[++cnt]=st[i];
			res[++cnt]=ed[i];
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&ask[i]);
			res[++cnt]=ask[i];
		}
		printf("Case #%d:\n",k);
		solve();
	}
	return 0;
}
