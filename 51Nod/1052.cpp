#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
#define LL long long
using namespace std;

const int maxn=5005;
int n,m,a[maxn];
LL f[maxn][2],ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	cl(f,192);ans=f[0][0];
	f[0][0]=0;
	for (int j=1;j<=m;j++){
		LL w=f[0][(j&1)^1];
		for (int i=1;i<=n;i++)
		 f[i][j&1]=max(f[i-1][j&1],w)+a[i],
		 w=max(w,f[i][(j&1)^1]),ans=max(ans,f[i][j&1]);
	}
	printf("%lld",ans);
	return 0;
}