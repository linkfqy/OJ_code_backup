#include<cstdio>
#define LL long long

const int maxn=10005,tt=1000000007;
int tst,n;
LL a[maxn],b[maxn];
int main(){
	n=10000;b[1]=1;a[1]=1;a[2]=6;
	for (int i=2;i<=n;i++) b[i]=b[i-1]*2%tt;
	for (int i=3;i<=n;i++) a[i]=(b[i]+a[i-1]*2+a[i-2]*4)%tt;
	scanf("%d",&tst);
	while (tst--){
		scanf("%d",&n);
		if (n==1) {printf("2\n");continue;}
		LL ans=a[n]*4%tt;
		for (int i=2;i<n;i++) ans=(ans+8*(a[i-1]*b[n-i]%tt + b[i-1]*a[n-i]%tt))%tt;
		printf("%lld\n",ans);
	}
	return 0;
}
