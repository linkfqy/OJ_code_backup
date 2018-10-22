#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=105;
int n,K,a[maxn],f[maxn][maxn][6];
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	cl(f,63);
	for (int i=1;i<=n;i++)
	 for (int k=0;k<K;k++)
	  f[i][i][k]=K-k-1,f[i][i-1][k]=0;
	for (int L=1;L<n;L++)
	 for (int l=1;l+L<=n;l++){
	 	int r=l+L;
	 	for (int k=K-1;~k;k--){
	 		if (k<K-1) f[l][r][k]=min(f[l][r][k],f[l][r][k+1]+1);
	 		if (k==K-1) f[l][r][k]=min(f[l][r][k],f[l][r-1][0]);
	 		for (int i=l;i<r;i++)
	 		if (a[r]==a[i]) 
	 		 f[l][r][k]=min(f[l][r][k],f[l][i][min(k+1,K-1)]+f[i+1][r-1][0]);
		}
	 }
	printf("%d\n",f[1][n][0]);
	return 0;
}
