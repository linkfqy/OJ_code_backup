#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=105,p[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-1000}};
const char s[6]={"ACGT-"};
int tst,n,m,f[maxn][maxn],g[128][128];
char a[maxn],b[maxn];
int main(){
	for (int i=0;i<5;i++)
	 for (int j=0;j<5;j++)
	  g[s[i]][s[j]]=p[i][j];
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%*c",&n);for (int i=1;i<=n;i++) a[i]=getchar();
		scanf("%d%*c",&m);for (int i=1;i<=m;i++) b[i]=getchar();
		memset(f,192,sizeof(f));
		f[0][0]=0;
		for (int i=1;i<=n;i++) f[i][0]=f[i-1][0]+g[a[i]]['-'];
		for (int i=1;i<=m;i++) f[0][i]=f[0][i-1]+g[b[i]]['-'];
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++)
		  f[i][j]=max(f[i-1][j-1]+g[a[i]][b[j]],max(f[i-1][j]+g[a[i]]['-'],f[i][j-1]+g['-'][b[j]]));
		printf("%d\n",f[n][m]);
	}
	return 0;
}
