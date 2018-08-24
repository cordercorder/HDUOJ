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

int n,m; 
double Min;

int main(void){
	int i;
	double a,b;
	while(scanf("%d %d",&n,&m)!=EOF){
		Min=101;
		for(i=0;i<n;i++){
			scanf("%lf %lf",&a,&b);
			if(a/b<Min){
				Min=a/b;
			}
		}
		printf("%.8lf\n",Min*m);	
	}
	return 0;
}
