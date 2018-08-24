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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e2+10;

int a[4][maxn];
int k;
int len[4]; 
int s;
int num[maxn*maxn+10],cnt;

bool check(){
	int pos;
	for(int i=1;i<=len[3];i++){
		pos=lower_bound(num+1,num+cnt,k-a[3][i])-num;
	//	deb(pos);
		if(pos!=cnt&&num[pos]==(k-a[3][i]))
			return 1;
	}
	return 0;
}

int main(void){
	int t=0;
	while(scanf("%d %d %d",&len[1],&len[2],&len[3])!=EOF){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=len[i];j++){
				scanf("%d",&a[i][j]);
			}
		}
		cnt=1;
		for(int i=1;i<=len[1];i++){
			for(int j=1;j<=len[2];j++){
				num[cnt++]=a[1][i]+a[2][j];
			}
		}
		sort(num+1,num+cnt);
		scanf("%d",&s);
		t++;
		printf("Case %d:\n",t);
		while(s--){
			scanf("%d",&k);
			if(check()){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}
