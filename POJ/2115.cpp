#include<cstdio>
#define LL long long
LL a,b,c,k;
LL exgcd(LL a,LL b,LL&x,LL&y){
	if (b==0) {x=1;y=0;return a;}
	LL d=exgcd(b,a%b,x,y),t=x;
	x=y;
	y=t-a/b*y;
	return d;
}
bool solve(LL a,LL b,LL c,LL&x,LL&y){
	LL d=exgcd(a,b,x,y);
	if (c%d>0) return 0;
	LL k=c/d;
	x*=k;y*=k;
	k=b/d;
	if (x<0) x+=(-x+k-1)/k*k;
	if (x>=0) x%=k;
	return 1;
}
int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
	while (k){
		k=(LL)1<<k;
		LL x,y;
		if (solve(c,-k,(b-a+k)%k,x,y)) printf("%lld\n",x);else printf("FOREVER\n");
		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
	}
	return 0;
}
//#include<cstdio>
//#define LL long long
//LL a,b,c,k;
//LL exgcd(LL a,LL b,LL&x,LL&y){
//	if (b==0) {x=1;y=0;return a;}
//	LL d=exgcd(b,a%b,x,y),t=x;
//	x=y;
//	y=t-a/b*y;
//	return d;
//}
//bool solve(LL a,LL b,LL n,LL&x){
//	LL y,d=exgcd(a,n,x,y);
//	if (b%d>0) return 0;
//	x=b/d*x%n;
//	LL k=n/d;
//	if (x<0) x+=(-x+k-1)/k*k;
//	if (x>=0) x%=k;
//	return 1;
//}
//int main(){
//	scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
//	while (k){
//		k=(LL)1<<k;
//		LL x;
//		if (solve(c,(b-a+k)%k,k,x)) printf("%lld\n",x);else printf("FOREVER\n");
//		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
//	}
//	return 0;
//}

















/*
题目其实就是要解a+cx≡b (mod 2^k)这个关于x的线性模方程
其实就是cx≡b-a (mod 2^k)
用扩展欧几里得解即可。 
*/
