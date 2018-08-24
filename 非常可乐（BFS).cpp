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

const int maxsize=1e2+10;

int s,n,m;

bool isv[maxsize][maxsize][maxsize];

struct node{
	int a;//对于s 
	int b;//对应n 
	int c;//对应m 
	int step;
	node(const int &x):a(x),b(0),c(0),step(0){		};//constructor
	node(){		};
};

int solve(){
	int last;
	node xa(s);
	node tmp;
	queue<node> q;
	memset(isv,0,sizeof(isv));
	isv[s][0][0]=1;
	q.push(xa);
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		if((tmp.a==tmp.b&&tmp.c==0)||(tmp.a==tmp.c&&tmp.b==0)||(tmp.b==tmp.c&&tmp.a==0))
			return tmp.step;
		if(tmp.a>0){//杯子a向b和c倒可乐 
			if(tmp.b<n){//杯子b还没满 
				xa.a=tmp.a;
				xa.b=tmp.b;
				xa.c=tmp.c;
				xa.step=tmp.step;
				last=n-tmp.b;//还能装last容积的可乐 
				xa.b=(tmp.a>last?n:tmp.a+tmp.b);
				xa.a=(tmp.a>last?tmp.a-last:0);
				if(!isv[xa.a][xa.b][xa.c]){//这种状态之前没有出现过 
					xa.step++;
					isv[xa.a][xa.b][xa.c]=1;
					q.push(xa);
				}
			}
			if(tmp.c<m){//杯子c还没满 
				xa.a=tmp.a;
				xa.b=tmp.b;
				xa.c=tmp.c;
				xa.step=tmp.step;
				last=m-tmp.c;
				xa.c=(tmp.a>last?m:tmp.a+tmp.c);
				xa.a=(tmp.a>last?tmp.a-last:0);
				if(!isv[xa.a][xa.b][xa.c]){//这种状态之前没有出现过 
					xa.step++;
					isv[xa.a][xa.b][xa.c]=1;
					q.push(xa);
				}
			}
		}
		if(tmp.b>0){//杯子b向a和c倒可乐 
			if(tmp.a<s){
				xa.a=tmp.a;
				xa.b=tmp.b;
				xa.c=tmp.c;
				xa.step=tmp.step;
				last=s-tmp.a;
				xa.b=(tmp.b>last?tmp.b-last:0);
				xa.a=(tmp.b>last?s:tmp.b+tmp.a);
				if(!isv[xa.a][xa.b][xa.c]){//这种状态之前没有出现过 
					xa.step++;
					isv[xa.a][xa.b][xa.c]=1;
					q.push(xa);
				}
			}
			if(tmp.c<m){
				xa.a=tmp.a;
				xa.b=tmp.b;
				xa.c=tmp.c;
				xa.step=tmp.step;
				last=s-tmp.a;
				last=m-tmp.c;
				xa.b=(tmp.b>last?tmp.b-last:0);
				xa.c=(tmp.b>last?m:tmp.c+tmp.b);
				if(!isv[xa.a][xa.b][xa.c]){//这种状态之前没有出现过 
					xa.step++;
					isv[xa.a][xa.b][xa.c]=1;
					q.push(xa);
				}
			}
		}
		if(tmp.c>0){
			if(tmp.a<s){
				xa.a=tmp.a;
				xa.b=tmp.b;
				xa.c=tmp.c;
				xa.step=tmp.step;
				last=s-tmp.a;
				xa.a=(tmp.c>last?s:tmp.c+tmp.a);
				xa.c=(tmp.c>last?tmp.c-last:0);
				if(!isv[xa.a][xa.b][xa.c]){//这种状态之前没有出现过 
					xa.step++;
					isv[xa.a][xa.b][xa.c]=1;
					q.push(xa);
				}
			}
			if(tmp.b<n){
				xa.a=tmp.a;
				xa.b=tmp.b;
				xa.c=tmp.c;
				xa.step=tmp.step;
				last=n-tmp.b;
				xa.b=(tmp.c>last?n:tmp.c+tmp.b);
				xa.c=(tmp.c>last?tmp.c-last:0);
				if(!isv[xa.a][xa.b][xa.c]){//这种状态之前没有出现过 
					xa.step++;
					isv[xa.a][xa.b][xa.c]=1;
					q.push(xa);
				}
			}
		}
	}
	return 0;
}

int main(void){
	int i,x;
	while(scanf("%d %d %d",&s,&n,&m)!=EOF){
		if(s==0&&n==0&&m==0)
			break;
		if(s&1){
			printf("NO\n");
			continue;
		}
		x=solve();
		if(x){
			printf("%d\n",x);
		} 
		else{
			printf("NO\n");
		}
	}
	return 0;
}
