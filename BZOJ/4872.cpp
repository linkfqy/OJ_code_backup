#include<cstdio>
#include<cmath>
typedef long long ll;

const int maxn=100005,MOD=100003;
int n,m,K,d[maxn];
ll f[maxn];
ll power(int a,int b){
	ll res=1,w=a;
	while (b){
		if (b&1) (res*=w)%=MOD;
		(w*=w)%=MOD;
		b>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=n;i>=1;i--)
	 if (d[i]){
	 	int tj=sqrt(i);d[i]=0;m++;
	 	for (int j=1;j<=tj;j++)
	 	 if (i%j==0){
	 	 	d[j]^=1;
	 	 	if (j*j!=i) d[i/j]^=1;
		 }
	 }
	if (m<=K){
		ll ans=m;
		for (int i=1;i<=n;i++) (ans*=i)%=MOD;
		printf("%lld",ans);
		return 0;
	}
	ll ans=K;
	f[n]=1;
	for (int i=n-1;i>K;i--)
	 f[i]=((n-i)*f[i+1]+n)%MOD*power(i,MOD-2)%MOD;
	for (int i=m;i>K;i--) (ans+=f[i])%=MOD;
	for (int i=1;i<=n;i++) (ans*=i)%=MOD;
	printf("%lld",ans);
	return 0;
}
