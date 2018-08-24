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
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

typedef long long ll;

using namespace std;

const int maxn=1e5+10;

int a[maxn];
int n;
stack<int> s;

int main(void){
	int sum=0,ans;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				while(!s.empty())
					s.pop();
			}
			else{
				while(s.size()&&a[s.top()]>a[i]){
					s.pop();
				}
				if(s.empty()||a[s.top()]<a[i])
					ans++;
				s.push(i);
			}
		}
		printf("Case %d: %d\n",++sum,ans);
		while(!s.empty())
			s.pop();
	}
	return 0;
}
