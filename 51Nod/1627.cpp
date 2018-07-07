#include<cstdio>
typedef long long ll;

const int maxn=100005,tt=1e9+7;
int n,m;
ll fac[maxn],inv[maxn],ans;
ll power(ll a,int b){
	ll w=a,res=1;
	while (b){
		if (b&1) res=res*w%tt;
		w=w*w%tt;
		b>>=1;
	}
	return res;
}
void make(){
	fac[0]=1;inv[0]=1;
	for (int i=1;i<=100000;i++) fac[i]=fac[i-1]*i%tt,inv[i]=power(fac[i],tt-2);
}
inline ll C(int y,int x){
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
}
int main(){
	scanf("%d%d",&n,&m);
	if (n==2||m==2) return printf("1"),0;
	make();ans=0;
	for (int i=1;i<n&&i<m;i++)
	 (ans+=C(i-1,n-2)*C(i-1,m-2)%tt)%=tt;
	printf("%lld",ans);
	return 0;
} 
