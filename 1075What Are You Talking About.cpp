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

const int maxsize=4e3+10;

map<string,string> mm;
map<string,string>::iterator it;
string str[maxsize];
int cnt;

void Find(const string &s){
	it=mm.find(s);
	if(it!=mm.end()){
		cout<<it->second;
	}
	else{
		cout<<s;
	}
}

int main(void){
	int i,len,j;
	char tmp[maxsize];
	string str1,str2,ss;
	while(scanf("%s",tmp)){
		if(strcmp(tmp,"START")==0)
			continue;
		if(strcmp(tmp,"END")==0)
			break; 
		str1=tmp;
		scanf("%s",tmp);
		str2=tmp;
		mm.insert(pair<string,string>(str2,str1));
	}
	getchar();
	cnt=0;
	while(gets(tmp)){
		if(strcmp(tmp,"START")==0)
			continue;
		if(strcmp(tmp,"END")==0)
			break; 
		if(strcmp(tmp,"\n")==0)
			continue;
		str[cnt++]=tmp;
	}
	for(i=0;i<cnt;i++){
		len=0;
		for(j=0;j<str[i].size();j++){
			if(str[i][j]>='a'&&str[i][j]<='z'){
				tmp[len++]=str[i][j];
			}
			else{
				tmp[len]='\0';
				ss=tmp;
				if(len){
					Find(ss);
					//cout<<endl<<"ss="<<ss<<endl;
				}
				printf("%c",str[i][j]);
				len=0;
			}
		}
		printf("\n");
	}
	mm.clear();
	return 0;
}
