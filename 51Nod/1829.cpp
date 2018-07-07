#include<cstdio>
typedef long long ll;

const int maxn=1000005,tt=1e9+7;
int n,m;
ll fac[maxn],inv[maxn];
ll power(int a,int b){
	ll w=a,res=1;
	while (b){
		if (b&1) res=res*w%tt;
		w=w*w%tt;
		b>>=1;
	}
	return res;
}
void make(){
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%tt,inv[i]=power(fac[i],tt-2);
}
inline ll C(int y,int x){
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
}
int main(){
	scanf("%d%d",&n,&m);
	if (n<m) return printf("0"),0;
	make();ll ans=0;
	for (int i=0;i<=m;i++)
	 (ans+=power(m-i,n)*C(i,m)*((i&1)?-1:1))%=tt;
	printf("%lld",(ans+tt)%tt);
	return 0;
} 
