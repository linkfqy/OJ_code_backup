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
典型的C(m+n,n)但是不能由杨辉三角求得，因为不知道空间要多大 
由公式得答案其实就是((m+1)*(m+2)*……*(m+n))/n!那么跑循环就能得到了 
*/
