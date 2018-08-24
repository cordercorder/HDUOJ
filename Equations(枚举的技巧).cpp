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

typedef long long ll;

using namespace std;

const int maxsize=1e6+50;

int a,b,c,d; 

int num1[maxsize],num2[maxsize];

int main(void){
	int i,j,x,ans;
	while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF){
		if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0)){
			printf("0\n");
			continue;
		}
		ans=0;
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		for(i=-100;i<=100;i++){
			if(i==0)
				continue;
			for(j=-100;j<=100;j++){
				if(j==0)
					continue;
				x=a*i*i+b*j*j;
				if(x<0){
					num2[-x]++;
				}
				else{
					num1[x]++;
				}
			}
		}
		for(i=-100;i<=100;i++){
			if(i==0)
				continue;
			for(j=-100;j<=100;j++){
				if(j==0)
					continue;
				x=c*i*i+d*j*j;
				if(x<=0){
					ans+=num1[-x];//非负数的一边和非正数的一边配对 
				}
				else{
					ans+=num2[x];//负数和正数配对 
				}
			}
		}
		printf("%d\n",ans);	
	}
	return 0;
}
