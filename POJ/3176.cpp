#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=355;
int n,a[maxn][maxn],f[maxn][maxn],ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=i;j++)
	  scanf("%d",&a[i][j]);
	f[1][1]=a[1][1];
	for (int i=2;i<=n;i++)
	 for (int j=1;j<=i;j++)
	  f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
	for (int i=1;i<=n;i++) ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}
