#include<cstdio>

const int maxn=1005;
const long double eps=1e-9;
int n,m,a[maxn],b[maxn];
bool check(long double fuel){
	for (int i=2;i<=n+1;i++){
		double del=(fuel+m)/a[i-1];
		if (del-fuel>=eps) return 0;
		fuel-=del;
		del=(fuel+m)/b[i];
		if (del-fuel>=eps) return 0;
		fuel-=del;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	long double ans=-1,l=0,r=1e9;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),l+=(double)m/a[i];
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),l+=(double)m/b[i];
	a[n+1]=a[1],b[n+1]=b[1];
	while (r-l>=eps){
		long double mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid;else l=mid;
	}
	if (ans<0) return puts("-1"),0;
	printf("%.10lf",(double)ans);
	return 0;
}
