#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
#define ins(x,y) (x[i]=x[i-1]+y)

const int maxn=100005;
const double eps=1e-8;
int n,A,B,num_a[maxn],num_b[maxn];
double a[maxn],b[maxn],f[maxn];
void work(double w1,double w2){
	f[0]=0;num_a[0]=num_b[0]=0;
	for (int i=1;i<=n;i++){
		ins(f,0);ins(num_a,0);ins(num_b,0);
		if (f[i-1]+a[i]-w1>f[i])
		 f[i]=f[i-1]+a[i]-w1,ins(num_a,1),ins(num_b,0);
		if (f[i-1]+b[i]-w2>f[i])
		 f[i]=f[i-1]+b[i]-w2,ins(num_a,0),ins(num_b,1);
		if (f[i-1]+1-(1-a[i])*(1-b[i])-w1-w2>f[i])
		 f[i]=f[i-1]+1-(1-a[i])*(1-b[i])-w1-w2,
		 ins(num_a,1),ins(num_b,1);
	}
}
int main(){
	while (scanf("%d%d%d",&n,&A,&B)==3){
		for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
		for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
		double l1=0,r1=1,l2=0,r2=1;
		while (r1-l1>=eps){
			double mid1=(l1+r1)/2;
			l2=0,r2=1;
			while (r2-l2>=eps){
				double mid2=(l2+r2)/2;
				if ((work(mid1,mid2),num_b[n])>B) l2=mid2;else r2=mid2;
			}
			if (work(mid1,r2),num_a[n]>A) l1=mid1;else r1=mid1;
		}
		work(r1,r2);
		printf("%.5lf\n",f[n]+r1*A+r2*B);
	}
	return 0;
}
