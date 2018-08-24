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

const int maxn=110000+10;

char s[maxn];
int nxt[maxn],len;

void pre_kmp(){
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<len){
		if(j==-1||s[i]==s[j]){
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
	pre_kmp();
	for(int i=1;i<=len;i++){
		printf("%d ",nxt[i]);
	}
	puts("");
}


int main(void){
	
	while(scanf("%s",s)!=EOF){
		len=strlen(s);
		solve();
		
		
		
	}
	
	return 0;
}
