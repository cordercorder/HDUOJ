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
int n,m;
int a[maxn],b[maxn];
int nxt[maxn];

void pre_kmp(){
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<m){
		while(j!=-1&&b[i]!=b[j]){
			j=nxt[j];
		}
		nxt[++i]=++j;
	}
}

int solve(){
	int i=0,j=0;
	pre_kmp();
	while(i<n&&j<m){
		if(j==-1||a[i]==b[j]){
			i++;
			j++;
		}
		else{
			j=nxt[j];
		}
	}
	if(j==m){
	return i-j+1;
	}
	return -1;
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
		}
		printf("%d\n",solve());
	}
	return 0;
}
