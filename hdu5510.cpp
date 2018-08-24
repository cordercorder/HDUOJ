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

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=5e2+10;

char s[maxn][2005];
int t,n;
int nxt[maxn][2005];
int len[maxn];
bool isv[maxn];
bool is[maxn];

void pre_kmp(int id){
	if(is[id])
		return ;
	is[id]=1;
	int i=0,j=-1;
	nxt[id][0]=-1;
	while(i<len[id]){
		if(j==-1||s[id][i]==s[id][j]){
			i++;
			j++;
			nxt[id][i]=j;
		}
		else{
			j=nxt[id][j];
		}
	}
}

bool check(int id1,int id2){
	pre_kmp(id2);
	int i=0,j=0;
	while(i<len[id1]&&j<len[id2]){
		if(j==-1||s[id1][i]==s[id2][j]){
			i++;
			j++;
		}
		else{
			j=nxt[id2][j];
		}
	}
	return j==len[id2];
}

void solve(){
	memset(isv,0,sizeof(isv));
	memset(is,0,sizeof(is));
	int ans=-1;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(!isv[j]){
				if(check(i,j)){
					isv[j]=1;
				}
				else{
					ans=max(ans,i);
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main(void){
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
			len[i]=strlen(s[i]);
		}	
		printf("Case #%d: ",k);
		solve();
	}
	return 0;
}
