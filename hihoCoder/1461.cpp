#include<cstdio>
#include<algorithm>
using namespace std;

int tst,a,b,tot,stk[10000];
#define brand() ((long long)rand()*rand())
inline int gcd(int x,int y) {return y==0?x:(tot+=x/y,gcd(y,x%y));}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d",&a);
		int MIN=999,t;
		for (int i=1;i<=1000&&MIN>60;i++){
			tot=0;
			if (gcd(a,t=brand()%(a-1)+1)==1)
			 if (MIN>tot) MIN=tot,b=t;
		}
		stk[0]=0;
		while (a+b!=1)
		 if (a>b) a-=b,stk[++stk[0]]=0;
		 else b-=a,stk[++stk[0]]=1;
		if (a==0&&b==1) while (stk[0]) printf("%d",stk[stk[0]--]);
		 else while (stk[0]) printf("%d",1-stk[stk[0]--]);
		printf("\n");
	}
	return 0;
}
