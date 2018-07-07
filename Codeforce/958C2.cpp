#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=20005;
int n,K,p,a[maxn];
int f[maxn][55][105],dp[maxn][55];
int main(){
	scanf("%d%d%d",&n,&K,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]%=p;
	memset(f,0xc0,sizeof(f));
	memset(dp,0xc0,sizeof(dp));
	f[0][0][0]=0;dp[0][0]=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=K&&j<=i;j++){
	 	f[i][j][a[i]]=max(f[i-1][j][0]+a[i],dp[i-1][j-1]+a[i]);
	 	for (int m=1;m<p;m++)
	 	 f[i][j][(a[i]+m)%p]=max(f[i][j][(a[i]+m)%p],f[i-1][j][m]-m+(a[i]+m)%p);
	 	for (int k=0;k<p;k++) dp[i][j]=max(dp[i][j],f[i][j][k]);
	 }
	printf("%d",dp[n][K]);
	return 0;
}
