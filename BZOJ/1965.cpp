#include<cstdio>
typedef long long ll;

ll n,m,l,MOD;
ll power(ll a,ll b){
	ll w=a%MOD,res=1;
	while (b){
		if (b&1) (res*=w)%=MOD;
		(w*=w)%=MOD;
		b>>=1;
	}
	return res;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&l);MOD=n+1;
	printf("%lld",l*power(n/2+1,m)%MOD);
	return 0;
}
