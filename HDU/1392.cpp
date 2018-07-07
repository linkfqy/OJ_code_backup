#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-7;
const int maxn=105;
int n;
struct point{
	double x,y;
	point() {}
	point(double a,double b):x(a),y(b) {}
	bool operator<(const point&b)const{
		if (x<b.x) return 1;
		if (x>b.x) return 0;
		return y<b.y;
	}
	point operator-(const point&b) {return point(x-b.x,y-b.y);}
}a[maxn],que[maxn];
typedef point vec;
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	return x>0?1:-1;
}
double getdst(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cross(vec a,vec b){
	return a.x*b.y-a.y*b.x;
}
int Andrew(){
	sort(a+1,a+1+n);
	int len=0;
	for (int i=1;i<=n;i++){
		while (len>1&&dcmp(cross(que[len]-que[len-1],a[i]-que[len-1]))==-1) len--;
		que[++len]=a[i];
	}
	int k=len;
	for (int i=n-1;i>=1;i--){
		while (len>k&&dcmp(cross(que[len]-que[len-1],a[i]-que[len-1]))==-1) len--;
		que[++len]=a[i];
	}
	return len;
}
int main(){
	for (scanf("%d",&n);n;scanf("%d",&n)){
		for (int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
		int t=Andrew();
		double ans=0;
		for (int i=1;i<t;i++) ans+=getdst(que[i],que[i+1]);
		printf("%.2lf\n",n==2?ans/2:ans);
	}
	return 0;
}
