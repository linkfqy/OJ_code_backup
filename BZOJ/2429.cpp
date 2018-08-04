#include<cstdio>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;

const int maxn=1005;
int n,m,L[maxn],x[maxn],y[maxn];
int d[maxn][maxn],dst[maxn],maxdst;
bool vis[maxn];
int main(){
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&L[i]);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		for (int j=1;j<=i;j++) d[i][j]=d[j][i]=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
	}
	for (int i=1;i<=n;i++) dst[i]=d[1][i];
	for (int i=1;i<=n;i++){
		int k=0,MIN=0x3f3f3f3f;
		for (int j=1;j<=n;j++)
		 if (!vis[j]&&MIN>dst[j]) MIN=dst[k=j];
		vis[k]=1;maxdst=max(maxdst,MIN);
		for (int j=1;j<=n;j++)
		 if (dst[j]>d[j][k]) dst[j]=d[j][k];
	}
	int ans=0;
	for (int i=1;i<=m;i++) ans+=(sqr(L[i])>=maxdst);
	printf("%d",ans);
	return 0;
}
