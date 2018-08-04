#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=305;
int n,e,q,f[maxn][maxn];
int main(){
	scanf("%d%d%d",&n,&e,&q);
	cl(f,63);
	for (int i=1,x,y,z;i<=e;i++) scanf("%d%d%d",&x,&y,&z),f[x][y]=min(f[x][y],z);
	for (int k=1;k<=n;k++)
	 for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++) f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
	while (q--){
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",f[x][y]==0x3f3f3f3f?-1:f[x][y]);
	}
	return 0;
}
