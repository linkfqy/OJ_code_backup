#include<cstdio>
typedef long long ll;

const int tt=1e9+7;
ll power(ll a,ll b){
	ll w=a,res=1;
	while (b){
		if (b&1) res=res*w%tt;
		w=w*w%tt;
		b>>=1;
	}
	return res;
}
ll a,b,c;
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld",power(2,c));
	return 0;
}
