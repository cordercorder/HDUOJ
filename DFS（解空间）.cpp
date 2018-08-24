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

int a[10];

void handle(){
	int i;
	a[0]=1;
	a[1]=1; 
	for(i=2;i<10;i++){
		a[i]=a[i-1]*i;
	}
}

bool check(const int &x){
	int m=1,sum=0;
	while(m<=x){
		sum+=a[(x/m)%10];
		if(sum>x)
			return 0;
		m=m*10;
	}
	if(sum==x)
		return 1;
	return 0;
}

int main(void){
	int i;
	handle();
	for(i=1;i<=9*a[9];i++){
		if(check(i))
			printf("%d\n",i);
	}
	return 0;
}
