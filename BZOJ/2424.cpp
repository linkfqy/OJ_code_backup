#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=55,maxs=10005;
int n,m,S,u[maxn],d[maxn];
ll f[maxn][maxs],MN[maxs];
int main(){
	scanf("%d%d%d",&n,&m,&S);
	for (int i=1;i<=n;i++) scanf("%d",&u[i]);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	cl(f,63);cl(MN,63); f[0][0]=0;MN[0]=0;
	for (int i=1;i<=n;i++){
		MN[0]=f[i-1][0];
		for (int j=1;j<=S;j++) MN[j]=min(MN[j-1],f[i-1][j]-j*d[i]);
		for (int j=0;j<=S;j++) f[i][j]=MN[min(S,j+u[i])]+j*(m+d[i])+u[i]*d[i];
	} 
	printf("%lld",f[n][0]);
	return 0;
}
