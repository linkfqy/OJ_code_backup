#include<cstdio>
typedef long long ll;

const int maxn=1000005;
int tst,n,MOD,siz[2*maxn];
ll fac[maxn],inv[maxn],f[maxn];
void prepare(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=1;i<=MOD&&i<=n;i++) fac[i]=fac[i-1]*i%MOD;
	for (int i=2;i<=MOD&&i<=n;i++) inv[i]=-(MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=MOD&&i<=n;i++) (inv[i]*=inv[i-1])%=MOD;
}
ll C(int x,int y){
	if (x>y) return 0;
	if (x<MOD&&y<MOD)
	 return fac[y]*inv[x]%MOD*inv[y-x]%MOD;
	return C(x/MOD,y/MOD)*C(x%MOD,y%MOD)%MOD;
}
int main(){
	scanf("%d%d",&n,&MOD);
	prepare();
	for (int i=n;i;i--){
		siz[i]=siz[i<<1]+siz[i<<1|1]+1;
		f[i]=C(siz[i<<1],siz[i]-1);
		if ((i<<1)<=n) (f[i]*=f[i<<1])%=MOD;
		if ((i<<1|1)<=n) (f[i]*=f[i<<1|1])%=MOD;
	}
	printf("%lld",(f[1]+MOD)%MOD);
	return 0;
}
