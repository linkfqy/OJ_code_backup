#include<cstdio>
typedef long long ll;

const int maxn=1e6+5,MOD=1e6+3;
int tst;
ll fac[maxn],inv[maxn];
void prepare(){
	fac[0]=1;inv[0]=inv[1]=1;
	for (int i=1;i<=MOD;i++) fac[i]=fac[i-1]*i%MOD;
	for (int i=2;i<=MOD;i++) inv[i]=-(MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=MOD;i++) (inv[i]*=inv[i-1])%=MOD;
}
ll C(int x,int y){
	if (x>y) return 0;
	if (x<MOD&&y<MOD)
	 return fac[y]*inv[x]%MOD*inv[y-x]%MOD;
	return C(x/MOD,y/MOD)*C(x%MOD,y%MOD)%MOD;
}
int main(){
	prepare();
	scanf("%d",&tst);
	while (tst--){
		int n,m,l,r;scanf("%d%d%d",&n,&l,&r);
		m=r-l+1;
		printf("%lld\n",(C(m,n+m)-1+MOD)%MOD);
	}
	return 0;
}
