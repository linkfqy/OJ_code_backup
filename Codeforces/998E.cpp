#include<cstdio>
typedef long long ll;

const int maxn=1000005,MOD=998244353;
int n; ll fac[maxn],inv[maxn];
inline ll ksm(ll a,ll b){
	ll res=1,w=a;
	while (b){
		if (b&1) (res*=w)%=MOD;
		(w*=w)%=MOD;
		b>>=1;
	}
	return res;
}
inline ll C(ll x,ll y){
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int main(){
	scanf("%d",&n);
	fac[0]=1;for (int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%MOD;
	inv[n]=ksm(fac[n],MOD-2);for (int i=n;i;i--) inv[i-1]=(inv[i]*i)%MOD;
	ll ans=(ksm(3,(ll)n*n)-ksm(ksm(3,n)-3,n))%MOD;
	for (int i=1;i<=n;i++){
		ll del=3*C(n,i)%MOD*ksm(ksm(3,n-i)-1,n)%MOD+C(n,i)*(ksm(3,i)-3)%MOD*ksm(3,(ll)n*(n-i))%MOD;del%=MOD;
		if (i&1) (ans+=del)%=MOD;else (ans-=del)%=MOD;
	}
	printf("%lld",(ans+MOD)%MOD);
	return 0;
} 
