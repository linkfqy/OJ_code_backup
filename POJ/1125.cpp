#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
int n,g[maxn][maxn];
int main(){
	scanf("%d",&n);
	while (n){
		memset(g,63,sizeof(g));
		for (int i=1;i<=n;i++){
			int k;scanf("%d",&k);g[i][i]=0;
			for (int j=1,x,w;j<=k;j++)
			 scanf("%d%d",&x,&w),g[i][x]=min(g[i][x],w);
		}
		for (int k=1;k<=n;k++)
		 for (int i=1;i<=n;i++)
		  for (int j=1;j<=n;j++)
		   if (g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
		int ans=0x3f3f3f3f,id;
		for (int i=1;i<=n;i++){
			int Max=0;
			for (int j=1;j<=n;j++)
			 if (Max<g[i][j]) Max=g[i][j];
			if (Max<ans) ans=Max,id=i;
		}
		if (ans==0x3f3f3f3f) printf("disjoint\n");else printf("%d %d\n",id,ans);
		scanf("%d",&n);
	}
	return 0;
}
