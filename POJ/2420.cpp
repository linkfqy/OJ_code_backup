#include<cstdio>
#include<cmath>
#include<cstdlib>
#define sqr(x) ((x)*(x))
const int maxn=105;
const double eps=0.01,coe=0.99,PI=3.1415926535897932384626433832795;
int n;
struct point{
	double x,y;
	point() {}
	point(double a,double b):x(a),y(b) {}
}a[maxn],now(0,0);
double dis(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double getans(point x){
	double res=0;
	for (int i=1;i<=n;i++) res+=dis(x,a[i]);
	return res;
}
bool check(double delta,double T){
	if (delta<=0) return 1;
	return rand()<=exp(-delta/T)*RAND_MAX;
}
int main(){
	srand(23333);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	 scanf("%lf%lf",&a[i].x,&a[i].y),
	 now.x+=a[i].x,now.y+=a[i].y;
	now.x/=n;now.y/=n;
	for (double tem=100000;tem>eps;tem*=coe)
	 for (int i=1;i<=100;i++){
		double alpha=PI*2*rand()/RAND_MAX;
		point xx(now.x+cos(alpha)*tem,now.y+sin(alpha)*tem);
		if (check(getans(xx)-getans(now),tem)) now=xx;
	 }
	printf("%.0lf\n",getans(now));
	return 0;
}
