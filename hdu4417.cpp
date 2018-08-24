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

int t;
int n,m;
int a[maxn];
int ans[maxn];

struct node{
	int num;
	int id;
	bool operator<(const node &a)const{
		return num<a.num;
	}
}res[maxn];

struct node2{
	int L;
	int R;
	int h;
	bool operator<(const node2 &a)const{
		return h<a.h;
	}
	int id;
}qur[maxn];

void update(vector<int> &sum,int rt,int l,int r,int pos){
	if(l==r){
		sum[rt]++;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(sum,rt<<1,l,mid,pos);
	}
	else{
		update(sum,rt<<1|1,mid+1,r,pos);
	}
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int query(vector<int> &sum,int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		return sum[rt];
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(sum,rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(sum,rt<<1|1,mid+1,r,L,R);
	}
	else{
		return query(sum,rt<<1,l,mid,L,mid)+query(sum,rt<<1|1,mid+1,r,mid+1,R);
	}
}

void solve(){
	vector<int>sum((n<<2),0);
	sort(res+1,res+1+n);
	sort(qur+1,qur+1+m);
	int cnt=1;
	for(int i=1;i<=m;i++){
		while(cnt<=n&&res[cnt].num<=qur[i].h){
			update(sum,1,1,n,res[cnt].id);
			cnt++;
		}
		ans[qur[i].id]=query(sum,1,1,n,qur[i].L+1,qur[i].R+1);
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		for(int k=1;k<=t;k++){
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i]);
				res[i].num=a[i];
				res[i].id=i;
			}
			for(int i=1;i<=m;i++){
				scanf("%d %d %d",&qur[i].L,&qur[i].R,&qur[i].h);
				qur[i].id=i;
			}
			printf("Case %d:\n",k);
			solve();
		}
	}
	return 0;
}
