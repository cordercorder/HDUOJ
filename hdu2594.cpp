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

const int maxn=5e4+10; 

char s1[maxn<<1],s2[maxn];
int len1,len2;
int nxt[maxn<<1];

void pre_kmp(){
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<len1){
		if(j==-1||s1[i]==s1[j]){
			i++;
			j++;
			nxt[i]=j;
		}
		else{
			j=nxt[j];
		}
	}
}

void solve(){
	//handle();
	len1=strlen(s1);
	len2=strlen(s2);
	strcat(s1,s2);
	len1+=len2;
	pre_kmp();
	int cnt=nxt[len1];
	len1-=len2;
	while(cnt>len1||cnt>len2){
		cnt=nxt[cnt];
	}
	if(cnt>0){
		s1[cnt]='\0';
		printf("%s %d\n",s1,cnt);
		return ;
	}
	puts("0");
}

int main(void){
	while(scanf("%s %s",s1,s2)!=EOF){
		solve();
	}
	return 0;
}
