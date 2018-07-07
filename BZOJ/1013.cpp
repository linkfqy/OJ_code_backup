#include<cstdio>
#include<algorithm>
#define _abs(x) ((x)>0?(x):-(x))
using namespace std;

const int maxn=15;
const double eps=1e-5;
int n;
double x[maxn][maxn],a[maxn][maxn],ans[maxn];
int fcmp(double x){
	if (_abs(x)<=eps) return 0;
	return x>0?1:-1;
}
void Gauss(int n){
	for (int i=1;i<=n;i++){
		int where=-1;
		for (int j=i;j<=n;j++)
		 if (fcmp(a[j][i]-0)!=0) {where=j;break;}
		swap(a[where],a[i]);
		//if where<0 нч╫Б
		for (int j=i+1;j<=n;j++){
			double w=a[j][i]/a[i][i];
			for (int k=i;k<=n+1;k++) a[j][k]-=a[i][k]*w;
		}
	}
	for (int i=n;i>=1;i--){
		ans[i]=a[i][n+1]/a[i][i];
		for (int j=1;j<i;j++) a[j][n+1]-=ans[i]*a[j][i];
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n+1;i++)
	 for (int j=1;j<=n;j++) scanf("%lf",&x[i][j]);
	for (int i=2;i<=n+1;i++)
	 for (int j=1;j<=n;j++) a[i-1][j]=2*(x[1][j]-x[i][j]),a[i-1][n+1]+=x[1][j]*x[1][j]-x[i][j]*x[i][j];
	Gauss(n);
	for (int i=1;i<n;i++) printf("%.3lf ",ans[i]);printf("%.3lf",ans[n]);
	return 0;
}
