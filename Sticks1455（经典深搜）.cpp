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
# include<limits.h>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=100;

int n;
int a[maxsize];
bool isv[maxsize];
int sum,Max,total;

bool check(int pos,int ss,int ee,int num){
    if(num==total)
        return true;
    if(ss==ee){
        if(check(0,0,ee,num+1))
            return true;
        else
            return false;
    }
    for(int i=pos;i<n;i++){
        if(!isv[i]&&ss+a[i]<=ee){
            isv[i]=true;
            if(check(i+1,ss+a[i],ee,num))
                return true;
            isv[i]=false;
            if(ss==0)
                return false;
            while(i+1<n&&a[i]==a[i+1])
                i++;
        }
    }
    return false;
}

void solve(){
    for(int i=Max;i<=sum;i++){
        if(sum%i!=0)
            continue;
        total=sum/i;
        memset(isv,false,sizeof(isv));
        if(check(0,0,i,0)){
            printf("%d\n",i);
            return ;
        }
    }
}

bool cmp(const int &a,const int &b){
    return a>b;
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        if(n==0)
            break;
        sum=0;
        Max=INT_MIN;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            Max=max(a[i],Max);
        }
        sort(a,a+n,cmp);
        solve();
    }
    return 0;
}
