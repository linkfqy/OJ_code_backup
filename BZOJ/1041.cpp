#include<cstdio>
#include<cmath>
#define LL long long

LL r,ans;
LL gcd(LL x,LL y) {return y==0?x:gcd(y,x%y);}
void work(LL Q){
	for (LL a=1,ta=sqrt(Q/2);a<=ta;a++){
		LL b=sqrt(Q-a*a),A=a*a,B=b*b;
		if (A+B!=Q) continue;
		if (A==B||gcd(A,B)!=1) continue;
		ans++;
	}
}
int main(){
	scanf("%lld",&r);LL rr=r*2;
	for (int d=1,td=sqrt(rr);d<=td;d++)
	 if (rr%d==0) work(d),work(rr/d);
	printf("%lld",ans*4+4);
	return 0;
} 
