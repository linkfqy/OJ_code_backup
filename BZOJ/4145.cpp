#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=105,maxs=65540;
int n,m,c[maxn][maxn],f[maxn][maxs],d[maxn];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for (int j=0;j<m;j++) scanf("%d",&c[i][j]);
	}
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int s=0;s<(1<<m);s++)
		 f[i][s]=f[i-1][s]+d[i];
		for (int j=0;j<m;j++)
		 for (int s=0;s<(1<<m);s++)
		  if (((s>>j)&1)==0)
		   f[i][s|(1<<j)]=min(f[i][s|(1<<j)],f[i][s]+c[i][j]);
		for (int s=0;s<(1<<m);s++)
		 f[i][s]=min(f[i][s],f[i-1][s]);
	}
	printf("%d",f[n][(1<<m)-1]);
	return 0;
}
