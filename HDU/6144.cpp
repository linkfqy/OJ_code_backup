#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int tt=1000000007,maxn=100005;
int tst,n,len;
LL res;
char s[maxn],ans[maxn],tem[maxn];
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%s",s);
		len=0;
		for (int i=0;s[i];i++)
		 if (s[i]=='('){
			i++;
			int top=0;
			while ('0'<=s[i]&&s[i]<='9') tem[top++]=s[i++];
			i+=3;int t=s[i]-48;
			while (t--){
				for (int j=0;j<top;j++)
				 ans[len++]=tem[j];
			}i++;
		 }else ans[len++]=s[i];
		res=0;
		for (int i=0;i<len;i++) res=(res*10+ans[i]-48)%tt;
		printf("%lld\n",res);
	}
	return 0;
}
