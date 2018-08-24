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

const int maxn=100000+10;
int len1,len2; 

void pre_kmp(char s[],int m,int nxt[]){
	int i=0,j;
	j=nxt[0]=-1;
	while(i<m){
		while(j!=-1&&s[i]!=s[j]){
			j=nxt[j];
		}
		nxt[++i]=++j;
	}
}

bool check(char s1[],char s2[],int nxt[]){
	int i=0,j=0;
	pre_kmp(s2,len2,nxt);
	while(i<len1&&j<len2){
		if(j==-1||s1[i]==s2[j]){
			i++;
			j++;
		}
		else{
			j=nxt[j];
		}
	}
	return j==len2;
}

int main(void){
	char s1[maxn<<1],s2[maxn];
	int nxt[maxn];
	while(scanf("%s %s",s1,s2)!=EOF){
		len1=strlen(s1);
		len2=strlen(s2);
		for(int i=len1;i<2*len1;i++){
			s1[i]=s1[i-len1];
		}
		len1<<=1;
		if(check(s1,s2,nxt)){
			puts("yes");
		}
		else{
			puts("no");
		}
	}
	return 0;
}
