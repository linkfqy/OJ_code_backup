#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
LL n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	while (n||m){
		if (m<n) swap(n,m);
		LL res=1;
		for (LL i=1;i<=n;i++)
		 res=res*(i+m)/i;
		printf("%lld\n",res);
		scanf("%lld%lld",&n,&m);
	}
	return 0;
}






























/*
���͵�C(m+n,n)���ǲ��������������ã���Ϊ��֪���ռ�Ҫ��� 
�ɹ�ʽ�ô���ʵ����((m+1)*(m+2)*����*(m+n))/n!��ô��ѭ�����ܵõ��� 
*/
