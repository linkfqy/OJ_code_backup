#include<cstdio>
#define LL long long
const int tt=100003;
LL n,m;
LL power(LL a,LL b){
	LL w=a%tt,ans=1;
	while (b>0){
		if (b&1) (ans*=w)%=tt;
		b>>=1;
		(w*=w)%=tt;
	}
	return ans;
}
int main(){
	scanf("%lld%lld",&m,&n);
	printf("%lld",(power(m,n)-power(m-1,n-1)*m%tt+tt)%tt);
	return 0;
}
