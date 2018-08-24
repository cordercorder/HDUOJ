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

# define ll long long 

using namespace std;

const int maxsize=1e3+10;

char str[maxsize],temp[maxsize];
int num[maxsize];
int cnt;

int main(void){
	int i,j;
	while(scanf("%s",str)!=EOF){
		cnt=0;
		j=0;
		for(i=0;i<strlen(str);i++){
			if(str[i]=='5'&&i>0&&j!=0){
				temp[j]='\0';
				num[cnt++]=atoi(temp);
				//printf("i=%d  j=%d  num=%d\n",i,j,num[cnt-1]); 
				j=0;
			}
			else if(str[i]!='5'){
				temp[j++]=str[i];
			}
		}
		if(j!=0){
			temp[j]='\0';
			num[cnt++]=atoi(temp);
		}
		sort(num,num+cnt);
		printf("%d",num[0]);
		for(i=1;i<cnt;i++){
			printf(" %d",num[i]);
		}
		printf("\n");
	}
	return 0;
}
