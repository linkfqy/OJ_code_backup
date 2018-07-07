#include<cstdio>
#include<cmath>
typedef long long LL;

const double s=1.6180339887498948482045868343656;
int n;
LL f[25];
int main(){
	f[0]=0;f[1]=1;
	for (int i=2;i<=20;i++) f[i]=f[i-1]+f[i-2];
	while (~scanf("%d",&n)){
		if (n<=20) {printf("%d\n",f[n]);continue;}
		double ans=-0.5*log10(5)+n*log10(s);
		ans-=(int)ans;
		ans=pow(10,ans);
		while (ans<1000) ans*=10;
		printf("%d\n",(int)ans);
	}
	return 0;
}
