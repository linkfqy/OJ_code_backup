#include<cstdio>
#define LL long long
LL a,b,m,n,l,x,y;
LL exgcd(LL a,LL b,LL&x,LL&y){
	if (b==0) {x=1,y=0;return a;}
	LL d=exgcd(b,a%b,x,y),x0=x;
	x=y;y=x0-a/b*y;
	return d;
}
bool solve(LL a,LL b,LL c,LL&x,LL&y){
	LL d=exgcd(a,b,x,y);
	if (c%d>0) return 0;
	x*=c/d,y*=c/d;
	LL k=b/d;
	if (x<=0) x+=(-x+k-1)/k*k;
	if (x>0) x%=k;
	return 1;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&a,&b,&m,&n,&l);
	if (solve(m-n,-l,b-a,x,y)) printf("%lld",x);else printf("Impossible");
	return 0;
}


































/*
其实就是要求a+xm≡b+xn的解，套扩展欧几里得就可以了 
*/
