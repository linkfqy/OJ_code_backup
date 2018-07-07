#include<cstdio>
#define LL long long
const int tt=1000003,maxe=10005;
LL a1,a2,a3,a4,a5,dat[maxe],ans=0;
int lnk[tt],son[maxe],nxt[maxe],tot,num[maxe];
int cube(int x){
	return x*x*x;
}
LL abs_(LL x){
	if (x<0) return -x;return x;
}
void ist(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int fnd(int x,LL sim){
	for (int j=lnk[x];j;j=nxt[j])
	 if (dat[son[j]]==sim) return son[j];
	return -1;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&a1,&a2,&a3,&a4,&a5);
	for (int x4=-50;x4<=50;x4++)
	 for (int x5=-50;x5<=50;x5++)
	  if (x4!=0&&x5!=0){
	  	LL sum=a4*cube(x4)+a5*cube(x5);
		int x=fnd(abs_(sum)%tt,sum);
		if (x>0) num[x]++;
		 else dat[++dat[0]]=sum,ist(abs_(sum)%tt,dat[0]),num[dat[0]]=1;
	  }
	for (int x1=-50;x1<=50;x1++)
	 for (int x2=-50;x2<=50;x2++)
	  for (int x3=-50;x3<=50;x3++)
	   if (x1!=0&&x2!=0&&x3!=0){
	  	LL sum=a1*cube(x1)+a2*cube(x2)+a3*cube(x3);sum=-sum;
	  	int x=fnd(abs_(sum)%tt,sum);
	  	if (x>0) ans+=num[x];
	  }
	printf("%lld",ans);
	return 0;
}




















/*
先预处理出两个未知数，并记录这两项之和的组合种数：hsh[a4*x4^3+a5*x5^3]++
然后枚举三个未知数，三项之和为：a1*x1^3+a2*x2^3+a3*x3^3，要使方程成立，则后两项的值必须为其相反数
将之前统计过的表计入答案即可
（当然，我们不可能开这么大的数组，哈希过） 
*/
