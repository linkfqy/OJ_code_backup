#include<cstdio>
const int maxn=10005;
const double pi=3.1415926535897932384626433832795;
int tst,n,m;
double a[maxn];
bool check(double x){
	int tot=0;
	for (int i=1;i<=n;i++){
		double ai=a[i];
		while (tot<m&&ai>x) ai-=x,tot++;
	}
	return tot>=m;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d",&n,&m);m++;
		for (int i=1,r;i<=n;i++)
		 scanf("%d",&r),a[i]=r*r*pi;
		double L=0,R=(1e8)*pi,ans=-1;
		while (R-L>=1e-5){
			double mid=(L+R)/2;
			if (check(mid)) ans=L=mid;else R=mid;
		}
		printf("%.4f\n",ans);
	}
	return 0;
}
