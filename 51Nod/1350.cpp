#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=105;
typedef long long LL;
LL tst,n,nn,f[maxn],G[maxn];
LL sum(LL n){
	if (n<=3) return n;
	int i=upper_bound(f,f+1+nn,n)-f-1;
	return G[i]+sum(n-f[i])+n-f[i]+1;
}
int main(){
	f[0]=0;f[1]=f[2]=1;f[3]=2;
	G[1]=G[2]=0;G[3]=1;
	for (int i=4;;i++){
		f[i]=f[i-1]+f[i-2];
		G[i]=G[i-1]+G[i-2]+f[i-2];//printf("%lld\n",f[i]);
		if (f[i]>1e17) {nn=i;break;}
	}
	scanf("%lld",&tst);
	while (tst--)
	 scanf("%lld",&n),printf("%lld\n",sum(n));
	return 0;
}
