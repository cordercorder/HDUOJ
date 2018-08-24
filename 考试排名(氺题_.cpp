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
# include<iomanip>

# define ll long long

using namespace std;

const int maxsize=20;
const int Max=1e3+10;

struct node{
	string name;
	char str[maxsize][maxsize];
	int ac;
	int ti;
}; 

node a[Max];

int m,n,cnt;

int check(char *str,char *s){
	int i,len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]=='('){
			s[i]='\0';
			return i+1;
		}
		s[i]=str[i];
	}
	return 0;
} 

void handle(char *str,const int &loc,char *s){
	int i,len=strlen(str),j=0;
	for(i=loc;i<len&&str[i]!=')';i++){
		s[j++]=str[i];
	}
	 s[j]='\0';
}

void solve(){
	int i,j;
	int x,loc,y;
	char s[maxsize];
	for(i=0;i<cnt;i++){
		for(j=1;j<=n;j++){
			if(a[i].str[j][0]=='-'){
				continue;
			}
			loc=check(a[i].str[j],s);
			if(loc){
				x=atoi(s);
				handle(a[i].str[j],loc,s);
				y=m*atoi(s);
			}
			else{
				x=atoi(a[i].str[j]);
				y=0;
			}
			//cout<<"the name is :"<<a[i].name<<endl;
			//printf("str=%s\n",a[i].str[j]);
			//printf("x=%d  y=%d\n",x,y);
			//printf("%d\n",a[i].ac);
			if(x!=0){
				a[i].ac++;
				a[i].ti=a[i].ti+x+y;
			}
		}
	}
}

bool cmp(const node &a,const node &b){
	if(a.ac>b.ac)
		return 1;
	if(a.ac==b.ac&&a.ti<b.ti)
		return 1;
	if(a.ac==b.ac&&a.ti==b.ti&&a.name<b.name){
		return 1;
	}
	return 0;
}

int main(void){
	int i;
	string temp;
	while(scanf("%d %d",&n,&m)!=EOF){
		cnt=0;
		while(cin>>a[cnt].name){
			for(i=1;i<=n;i++){
				scanf("%s",a[cnt].str[i]);
				a[cnt].ac=0;
				a[cnt].ti=0;
			}
			cnt++;
		}
		solve();
		sort(a,a+cnt,cmp);
		cout.setf(ios::left);
		for(i=0;i<cnt;i++){
			cout.width(10);
			cout<<a[i].name;
			printf(" %2d",a[i].ac);
			printf(" %4d\n",a[i].ti);
		}
	}
	return 0;
}
