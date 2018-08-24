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
char W[maxn],T[maxn];
int nxt[maxn];
int len1,len2;

void pre_kmp(){
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<len2){
		if(j==-1||W[i]==W[j]){
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
	len2=strlen(W);
	len1=strlen(T);
	pre_kmp();
	int i=0,j=0,ans=0;
	while(i<len1&&j<len2){
		if(j==-1||T[i]==W[j]){
			i++;
			j++;
		}
		else{
			j=nxt[j];
		}
		if(j>=len2){
			ans++;
			j=nxt[j];
		}
	}
	printf("%d\n",ans);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%s %s",W,T);
		solve();
	}
	return 0;
}
