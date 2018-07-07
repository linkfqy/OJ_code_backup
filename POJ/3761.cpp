#include<cstdio>
typedef long long LL;

const int maxn=1000005,tt=20100713;
int tst,n,k;
LL fac[maxn];
LL power(int a,int b){
	LL w=a,res=1;
	while (b){
		if (b&1) res=res*w%tt;
		w=w*w%tt;
		b>>=1;
	}
	return res;
}
int main(){
	fac[0]=1;
	for (int i=1;i<=1000000;i++) fac[i]=fac[i-1]*i%tt;
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d",&n,&k);
		printf("%lld\n",fac[k]*(power(k+1,n-k)-power(k,n-k)+tt)%tt);
	}
	return 0;
}
