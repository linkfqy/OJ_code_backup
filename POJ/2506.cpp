#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
const int maxl=105;
int n;
struct bignum{
	int s[maxl];
	bignum operator+(const bignum&b){
		bignum c;memset(c.s,0,sizeof(c.s));
		c.s[0]=max(s[0],b.s[0]);
		for (int i=1;i<=c.s[0];i++)
		 c.s[i]+=s[i]+b.s[i],
		 c.s[i+1]+=c.s[i]/10,
		 c.s[i]%=10;
		if (c.s[c.s[0]+1]) c.s[0]++;
		return c;
	}
	void print(){
		for (int i=s[0];i>=1;i--) putchar(s[i]+48);
		putchar(10);
	}
}f[255];
int main(){
	f[0].s[0]=1;f[0].s[1]=1;
	f[1].s[0]=1;f[1].s[1]=1;
	f[2].s[0]=1;f[2].s[1]=3;
	for (int i=3;i<=250;i++)
	 f[i]=f[i-2]+f[i-2]+f[i-1];
	while (scanf("%d",&n)==1) f[n].print();
	return 0;
}
