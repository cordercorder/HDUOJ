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

typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

int t;
int n;

string str[maxsize];

bool cmp(const string &a,const string &b){
	return a.size()<b.size();
}

bool check(const string &s1,const string &s2){
	int pos1,pos2;
	for(int i=1;i<n;i++){
		pos1=str[i].find(s1);
		pos2=str[i].find(s2);
		if(pos1==string::npos&&pos2==string::npos)
			return 0;
	}
	return 1;
}

void solve(){
	string min_str=str[0];
	string s1,s2;
	for(int len=min_str.length();len>0;len--){//i为最小字符串的长度 
		for(int i=0;i<=min_str.length()-len;i++){
			s1=min_str.substr(i,len);//从第一个字符串中取样本 
			s2=s1;
			reverse(s2.begin(),s2.end());
			if(check(s1,s2)){
				printf("%d\n",len);
				return ;
			}
		}
	}
	printf("0\n");
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				cin>>str[i];
			}
			sort(str,str+n,cmp);
			solve();
		}
	}
	return 0;
}
