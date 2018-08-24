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

# define ll long long 

using namespace std;

const int maxsize=1e5+10;

struct node{
	string str;
	string f;
};

string temp;

node a[maxsize];
int n,cnt;

void solve1(){
	int i;
	for(i=0;i<cnt;i++){
		if(a[i].str==temp){
			cout<<a[i].f<<endl;
			return ;
		}
	}
	printf("what?\n");
}

void solve2(){
	int i;
	for(i=0;i<cnt;i++){
		if(a[i].f==temp){
			cout<<a[i].str.substr(1,a[i].str.length()-2)<<endl;
			return ;
		}
	}
	printf("what?\n");
}

int main(void){
	int i=0,pos;
	string p;
	while(getline(cin,p)){
		if(p=="@END@")
			break;
		pos=p.find("]");
		a[i].str=p.substr(0,pos+1);
		a[i].f=p.substr(pos+2,80);
		//cout<<"str="<<a[i].str<<"    function is="<<a[i].f<<endl;
		i++;
	}
	cnt=i;
	scanf("%d",&n);
	getchar();
	while(n--){
		getline(cin,temp);
		if(temp[0]=='[')
			solve1();
		else
			solve2();
	}
	return 0;
}
