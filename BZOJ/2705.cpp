#include<cstdio>
#include<cmath>
typedef long long ll;

ll n,N,ans;
ll phi(int x){
	int res=x,ti=sqrt(x);
	for (int i=2;i<=ti;i++)
	 if (x%i==0){
	 	res=res/i*(i-1);
	 	while (x%i==0) x/=i;
	 }
	if (x>1) res=res/x*(x-1);
	return res;
}
int main(){
	scanf("%lld",&n);N=sqrt(n);
	for (int i=1;i<=N;i++)
	 if (n%i==0){
		ans+=i*phi(n/i);
		if ((ll)i*i<n) ans+=(n/i)*phi(i);
	 }
	printf("%lld",ans);
	return 0;
}
