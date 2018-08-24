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

const int maxn=1e6+10;

int t;
char s[3][maxn];
int nxt[3][maxn];
int len[3];

void pre_kmp(int id){
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

int handle(char s1[],char s2[],int len1,int len2,int id){// id is the pattern string
	int i=0,j=0;
	while(i<len1&&j<len2){
		if(j==-1||s1[i]==s2[j]){
			i++;
			j++;
		}
		else{
			j=nxt[id][j];
		}
	}
	if(j==len2){
		return len1;
	}
	return len1+len2-j;
}

void solve(){
	pre_kmp(1);
	pre_kmp(2);
	int ans=handle(s[1],s[2],len[1],len[2],2);
	ans=min(ans,handle(s[2],s[1],len[2],len[1],1));
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%s %s",s[1],s[2]);
			len[1]=strlen(s[1]);
			len[2]=strlen(s[2]);
			solve();
		}
	}
	return 0;
}
