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

struct node{
	int s;
	int e;
	bool operator>(const node &a)const{
		if(e>a.e)
			return 1;
		return 0;
	}
};

priority_queue<node,vector<node>,greater<node> > q;
int n;

void solve(){
	int ans=0,t=-1;
	node temp;
	while(!q.empty()){
		temp=q.top();
		q.pop();
		if(temp.s>=t){
			t=temp.e;
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int i;
	node temp;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(i=0;i<n;i++){
			scanf("%d %d",&temp.s,&temp.e);
			q.push(temp);
		}
		solve();
	}
	return 0;
}
