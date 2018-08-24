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
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

typedef long long ll;

using namespace std;

class Bigint{
	private:
		char num[100001];
		int len;
		bool f;
	public:
		Bigint():len(1),f(1){num[0]='0',num[len]='\0';			};
		Bigint(const int &);//将一个int类型的变量转化为大数
		void input();
		void print();
		Bigint operator+(const Bigint &);
		Bigint operator+(const int &);
		Bigint operator*(const Bigint &);
		Bigint operator*(const int &);
		Bigint operator-(const Bigint &);
		Bigint operator/(const Bigint &);
		Bigint operator=(const Bigint &);
		Bigint operator=(const int &);
		bool operator<(const Bigint &)const;
		bool operator<(const int &)const;
		bool operator==(const Bigint &)const;
		bool operator==(const int &)const;
		bool operator>(const Bigint &)const;
		bool operator>(const int &)const;
}; 

void Bigint::input(){
	scanf("%s",num);
	len=strlen(num);
	if(num[0]=='-'){//负数的情况 
		f=0;
		for(int i=1;i<len;i++)
			num[i-1]=num[i];
		len--;
		num[len]='\0';
	}
	reverse(num,num+len);
} 

void Bigint::print(){
	char tmp[len+5];
	strcpy(tmp,num);
	reverse(tmp,tmp+len);
	if(!f)
		putchar('-');
	puts(tmp);
}

Bigint::Bigint(const int &x){
	int m=1;
	int tmp=x;
	len=0;
	f=1;
	if(x<0){//负数的情况 
		tmp=-x;
		f=0;
	}
	else if(x==0){
		num[len++]='0';
		num[len]='\0';
		return ;
	}
	while(m<=tmp){
		num[len++]=(tmp/m)%10+'0';
		m=m*10;
	}
	num[len]='\0';
}

bool Bigint::operator>(const Bigint &a)const{
	if(len>a.len)
		return 1;
	else if(len==a.len){
		for(int i=len-1;i>=0;i--){
			if(num[i]>a.num[i])
				return 1;
			else if(num[i]<a.num[i])
				return 0;
		}
		return 0;
	}
	else{
		return 0;
	}
}

bool Bigint::operator>(const int &a)const{
	Bigint tmp(a);
	if((*this)>tmp)
		return 1;
	return 0;
}

bool Bigint::operator==(const Bigint &a)const{
	if(len<a.len)
		return 0;
	else if(len>a.len)
		return 0;
	else{
		for(int i=len-1;i>=0;i--){
			if(num[i]==a.num[i])
				continue;
			return 0;
		}
		return 1;
	}
}

bool Bigint::operator==(const int &a)const{
	Bigint tmp(a);
	if((*this)==tmp)
		return 1;
	return 0;
}

bool Bigint::operator<(const Bigint &a)const{
	if(len<a.len)
		return 1;
	else if(len==a.len){
		for(int i=len-1;i>=0;i--){
			if(num[i]<a.num[i])
				return 1;
			else if(num[i]>a.num[i])
				return 0;
		}
		return 0;
	}
	else{
		return 0;
	}
}

bool Bigint::operator<(const int &a)const{
	Bigint tmp(a);
	if((*this)<tmp)
		return 1;
	return 0;
}

Bigint Bigint::operator+(const Bigint &a){
	int res,out=0;
	int i;
	Bigint ans;
	for(i=0;i<a.len&&i<this->len;i++){
		res=a.num[i]-'0'+this->num[i]-'0'+out;
		out=res/10;
		ans.num[i]=res%10+'0';
	}
	while(i<a.len){
		res=a.num[i]-'0'+out;
		out=res/10;
		ans.num[i]=res%10+'0';
		i++;
	}
	while(i<this->len){
		res=this->num[i]-'0'+out;
		out=res/10;
		ans.num[i]=res%10+'0';
		i++;
	}
	if(out){
		ans.num[i++]=out+'0';
	}
	ans.len=i;
	ans.num[len]='\0';
	return (ans);
}

Bigint Bigint::operator*(const Bigint &a){
	int num1[len+10],num2[a.len+10],res[len+a.len+20];
	Bigint ans;
	for(int i=0;i<len;i++){
		num1[i]=(int)(num[i]-'0');
	}
	for(int i=0;i<a.len;i++){
		num2[i]=(int)(a.num[i]-'0');
	}
	memset(res,0,sizeof(res));
	for(int i=0;i<len;i++){
		for(int j=0;j<a.len;j++){
			res[i+j]+=num1[i]*num2[j];
		}
	}
	for(int i=0;i<(len+a.len+5);i++){
		if(res[i]>=10){
			res[i+1]+=res[i]/10;
			res[i]%=10;
		}
	}
	int cnt=len+a.len+5;
	while(cnt>0&&res[cnt]==0)
		cnt--;
	for(int i=0;i<=cnt;i++){
		ans.num[i]=(char)(res[i]+'0');
	}
	if((f==1&&a.f==0)||(f==0&&a.f==1))//相乘为负数的情况 
		ans.f=0;
	ans.len=cnt+1;
	ans.num[cnt+1]='\0';
	return (ans);
}

Bigint Bigint::operator*(const int &a){
	Bigint tmp(a);
	return (*this)*tmp;
}

Bigint Bigint::operator=(const Bigint &a){
	len=a.len;
	strcpy(num,a.num);
	return *this;
}

Bigint Bigint::operator=(const int &a){
	Bigint tmp(a);
	(*this)=tmp;
	return (*this);
}

int main(void){
	//clock_t start_time=clock();
	Bigint ans;
	int n;
	while(scanf("%d",&n)!=EOF){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i);
		}
		ans.print();
	}
	//clock_t end_time=clock();
	//cout<<"the time is:"<<(end_time-start_time)<<endl;
	return 0;
}
