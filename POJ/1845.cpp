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
����Ȼ�ػ��뵽��a��ֳ����ɸ����������
a=p1^k1*p2^k2*����*pn^kn
����a^b= p1^(b*k1)*p2^(b*k2)*����*pn^(b*kn)
���������ӣ���һ���������ӣ�ע�⣡����������������������ϣ��˷�ԭ������Ϊ 
(p1^0+p1^1+p1^2+����+p^(b*k1))*(p2^0+p2^1+p2^2+����+p^(b*k2))*����*(pn^0+pn^1+pn^2+����+p^(b*kn))
�õȱ�������͹�ʽ���ɣ����ڳ����ķֲ�mod���ﲻ��׸��
ֵ��ע����ǣ����ܳ���p��1(mod tt)��ʱ�ȱ�������͹�ʽ�Ͳ������ˡ�
��Ȼ��ʱp^i��1(mod tt)�������һ��b��ĵȱ�����1,p,p^2,p^3����p^(b-1)��mod��Ϊ1,1,1����1����Ϊb*1 
*/
