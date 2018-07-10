#include<cstdio>
typedef long long ll;
ll p,q,b;
int tst;
ll gcd(ll x,ll y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%lld%lld%lld",&p,&q,&b);
		if (p==0) {printf("Finite\n");continue;}
		ll t=gcd(p,q);p/=t;q/=t;
		while (q>1){
			t=gcd(q,b);
			if (t==1) break;
			while (q%t==0) q/=t;
		}
		if (q==1) printf("Finite\n");else printf("Infinite\n");
	}
	return 0;
}
