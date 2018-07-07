#include<cstdio>

const int maxn=1000005,tt=1000000007;
int n,f[maxn];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);f[1]=1;
	for (int i=2;i<=n;i++)
	 if (i&1) f[i]=f[i-1];else
	 f[i]=(f[i-1]+f[i>>1])%tt;
	printf("%d",f[n]);
	return 0;
} 
