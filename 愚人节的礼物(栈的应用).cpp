# include<iostream>
# include<algorithm>
# include<cstring>
# include<cstdlib>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

using namespace std;

const int maxsize=1e3+10;

char str[maxsize]; 

stack<char> s;

void solve(){
	int i,ans=0;
	for(i=0;i<strlen(str);i++){
		if(str[i]==')'&&!s.empty()&&s.top()=='('){
			s.pop();
			ans--;
		}
		else if(str[i]=='('){
			s.push(str[i]);
			ans++;
		}
		else{
			break;
		}
	}
	while(!s.empty())
		s.pop();
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%s",str)!=EOF){
		solve();
	}
	return 0;
}
