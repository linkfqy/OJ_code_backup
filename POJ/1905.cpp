#include<cstdio>
#include<cmath>
const double eps=1e-10;
double l,n,c,ll;
double abs_(double x){
	if (x<0) return -x;return x;
}
bool check(double x){
	double r=(l*l/4+x*x)/(2*x),LL=asin(l/r/2)*r*2;
	if (abs_(ll-LL)<eps) return 1;
	if (LL<ll) return 0;
	else return 1;
}
int main(){
	scanf("%lf%lf%lf",&l,&n,&c);
	while (l>=0){
		if (l==0||n==0||c==0) {printf("0.000\n");scanf("%lf%lf%lf",&l,&n,&c);continue;}
		ll=(1+n*c)*l;
		double L=0,R=l/2,ans=-1;
		while (R-L>1e-5){
			double mid=(L+R)/2;
			if (check(mid)) ans=mid,R=mid;else L=mid;
		}
		printf("%.3f\n",ans);
		scanf("%lf%lf%lf",&l,&n,&c);
	}
	return 0;
}


















/*
设伸长后的长度为ll，可以得到以下两个等式：
r^2=(l/2)^2+(r-x)^2即r=((l^2)/4+x^2)/(2*x)
sin^-1(l/(2r))*2*pi*r/180=ll  （程序中的asin返回值是弧度，因此有所变化） 
可以发现，ll的值随x增大而增大，可以二分x，判断ll的值是否合理 
*/
