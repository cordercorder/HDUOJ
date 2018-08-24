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
# include<deque>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

class Bigint{
	private:
		char num[10001];
		int len;
	public:
		void input();
		void print();
		void print_();
		Bigint operator+(const Bigint &);
		Bigint operator*(const Bigint &);
		Bigint operator-(const Bigint &);
		Bigint operator=(const Bigint &);
		bool operator<(const Bigint &)const;
		bool operator>(const Bigint &)const;
}; 

void Bigint::input(){
	scanf("%s",num);
	len=strlen(num);
	reverse(num,num+len);
}

void Bigint::print(){
	string tmp=num;
	reverse(tmp.begin(),tmp.end());
	cout<<tmp<<endl;
}

void Bigint::print_(){
	string tmp=num;
	reverse(tmp.begin(),tmp.end());
	cout<<tmp;
}

Bigint Bigint::operator+(const Bigint &a){
	int res,out=0;
	int i;
	for(i=0;i<a.len&&i<this->len;i++){
		res=a.num[i]-'0'+this->num[i]-'0'+out;
		out=res/10;
		this->num[i]=res%10+'0';
	}
	while(i<a.len){
		res=a.num[i]-'0'+out;
		out=res/10;
		this->num[i]=res%10+'0';
		i++;
	}
	while(i<this->len){
		res=this->num[i]-'0'+out;
		out=res/10;
		this->num[i]=res%10+'0';
		i++;
	}
	if(out){
		this->num[i++]=out+'0';
	}
	this->len=i;
	this->num[len]='\0';
	return *this;
}

Bigint Bigint::operator=(const Bigint &a){
	len=a.len;
	strcpy(num,a.num);
	return *this;
}

int main(void){
	Bigint a,b,c;
	int t,sum=0;
	scanf("%d",&t);
	while(t--){
		a.input();
		b.input();
		sum++;
		printf("Case %d:\n",sum);
		a.print_();
		printf(" + ");
		b.print_();
		printf(" = ");
		c=a+b;
		c.print();
		if(t)
			puts("");
	}
	return 0;
}
