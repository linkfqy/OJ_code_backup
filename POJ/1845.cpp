#include<cstdio>
const int maxn=7105,tt=9901;
int a,b,ans,p[maxn],num[maxn];
void get_prime(){
	for (int i=2;i*i<=a;i++)
	 if (a%i==0){
	 	int tot=0;
		do a/=i,tot++; while (a%i==0);
		p[++p[0]]=i;num[p[0]]=tot;
	 }
	if (a>1) p[++p[0]]=a,num[p[0]]=1;
}
int power(int a,int b){
	int res=1,w=a%tt;
	while (b){
		if (b&1) res=(res*w)%tt;
		w=(w*w)%tt;
		b>>=1;
	}
	return res;
}
int get_sum(int p,int b){
	int x=power(p,b)-1,y=(p-1)%tt;
	if (!y) return b;
	while (x%y) x+=tt;
	return x/y%tt;
}
int main(){
	scanf("%d%d",&a,&b);
	get_prime();
	ans=1;
	for (int i=1;i<=p[0];i++)
	 ans=(ans*get_sum(p[i],num[i]*b+1))%tt;
	printf("%d",ans);
	return 0;
}










/*
很自然地会想到把a拆分成若干个质因子相乘
a=p1^k1*p2^k2*……*pn^kn
所以a^b= p1^(b*k1)*p2^(b*k2)*……*pn^(b*kn)
其所有因子（不一定是素因子，注意！）就是所有素因子排列组合（乘法原理），和为 
(p1^0+p1^1+p1^2+……+p^(b*k1))*(p2^0+p2^1+p2^2+……+p^(b*k2))*……*(pn^0+pn^1+pn^2+……+p^(b*kn))
用等比数列求和公式即可，关于除法的分布mod这里不再赘述
值得注意的是，可能出现p≡1(mod tt)这时等比数列求和公式就不适用了。
显然此时p^i≡1(mod tt)，则对于一个b项的等比数列1,p,p^2,p^3……p^(b-1)，mod后为1,1,1……1即和为b*1 
*/
