#include<cstdio>
#include<cstring> 
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=500005;
const double eps=1e-3; 
int n,K,a[maxn],g[maxn];
double f[maxn];
void check(double w){
	f[0]=0;f[1]=min(a[1]+w,0.0);
	for (int i=2;i<=n;i++)
	 if (f[i-1]>f[i-2]+a[i]+w)
	  f[i]=f[i-2]+a[i]+w,g[i]=g[i-2]+1;else
	  f[i]=f[i-1],g[i]=g[i-1];
}
int main(){
	scanf("%d%d",&K,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++) a[i]=a[i+1]-a[i];n--;
	double l=-1e9,r=1e9,mid;
	while (r-l>eps){
		mid=(l+r)/2;
		if (check(mid),g[n]<K) r=mid;else l=mid;
	}
	check(mid=(l+r)/2);
	printf("%.0lf",f[n]-K*mid);
	return 0;
}
