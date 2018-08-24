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
# include<map>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

int n;
string str;

void solve(){
	char ch=str[0],sum=1;
	for(int i=1;i<str.length();i++){
		if(str[i]==ch){
			sum++;
			continue;
		}
		if(sum>1){
			printf("%d",sum);
		}
		printf("%c",ch);
		sum=1;
		ch=str[i];
	}
	if(sum>1)
		printf("%d",sum);
	printf("%c",ch);
	cout<<endl; 
}

void solve1(){
	int sum=1;
	int i,j;
	for(i=0;i<str.length();){
		for(j=i+1;j<str.length();j++){
			if(str[i]==str[j]){
				sum++;
				continue;
			}
			else
				break;
		}
		if(sum>1)
			printf("%d",sum);
		printf("%c",str[i]);
		i=j;
		sum=1;
	}
	cout<<endl;
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		while(n--){
			cin>>str;
			//solve();
			solve1();
		}
	}
	return 0;
}
