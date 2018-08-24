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

const int maxsize=2e3+10;

struct node{
	int id;
	int w;
	bool operator<(const node &a)const{
		if(this->w>a.w){
			return 1;
		}
		else  if(this->w==a.w&&this->id<a.id){
			return 1;
		}
		return 0;
	}
};

int n,cnt1;
int a,b;
char str[10];

vector<node> p[4];

int main(void){
	int i;
	node s;
	while(scanf("%d",&n)!=EOF){
		cnt1=1;
		for(i=1;i<=4;i++){
			p[i].clear();
		}
		for(i=1;i<=n;i++){
			scanf("%s",str);
			if(!strcmp(str,"IN")){
				scanf("%d %d",&a,&b);
				s.id=cnt1++;
				s.w=b;
				p[a].push_back(s);
			}
			else{
				scanf("%d",&a);
				if(p[a].empty()){
					printf("EMPTY\n");
					continue;
				}
				sort(p[a].begin(),p[a].end());
				printf("%d\n",p[a][0].id);
				p[a].erase(p[a].begin());
			}
		}
	}
	return 0;
}
