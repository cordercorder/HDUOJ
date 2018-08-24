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

# define deb(x) printf("# x=%d\n",x)


typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

struct node{
	int s;
	int e;
	bool operator<(const node &a)const{
		if(e<a.e)
			return 1;
		return 0;
	}	
};

node a[maxsize];
int n;

void solve(){
	sort(a,a+n);
	int ans=1,temp=a[0].e,i;
	for(i=1;i<n;i++){
		if(a[i].s>=temp){
			temp=a[i].e;
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i].s,&a[i].e);
		solve();
	}
	return 0;
}
