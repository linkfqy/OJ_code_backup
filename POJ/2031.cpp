#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;
const int maxn=105;
int n;
bool vis[maxn];
double x[maxn],y[maxn],z[maxn],r[maxn],cst[maxn][maxn],dst[maxn],ans;
double getdist(int i,int j){
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]));
}
void prim(){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) dst[i]=cst[1][i];
	for (int i=1;i<n;i++){
		int k;double Min=1e100;
		for (int j=2;j<=n;j++)
		 if (!vis[j]&&Min>dst[j]) Min=dst[j],k=j;
		vis[k]=1;ans+=dst[k];
		for (int j=1;j<=n;j++)
		 if (dst[j]>cst[k][j]) dst[j]=cst[k][j];
	}
}
int main(){
	scanf("%d",&n);
	while (n){
		for (int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);
			for (int j=1;j<i;j++)
			 cst[i][j]=cst[j][i]=max(0.0,getdist(i,j)-r[i]-r[j]);
			cst[i][i]=0;
		}
		ans=0;prim();
		printf("%.3f\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
