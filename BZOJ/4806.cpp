#include<cstdio>
#include<cstring>
#define C(x) ((x)*((x)-1)/2)
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long ll;

const int maxn=105,MOD=999983;
ll f[maxn][maxn][maxn];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	cl(f,0);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	 for(int j=0;j<=m;j++)
	  for(int k=0;j+k<=m;k++){
		f[i][j][k]=f[i-1][j][k];
		if(j-1>=0) (f[i][j][k]+=f[i-1][j-1][k]*(m-(j-1)-k))%=MOD;
		if(j+1<=m&&k-1>=0) (f[i][j][k]+=f[i-1][j+1][k-1]*(j+1))%=MOD;
		if(j-2>=0) (f[i][j][k]+=f[i-1][j-2][k]*C(m-k-(j-2)))%=MOD;
		if(k-1>=0) (f[i][j][k]+=f[i-1][j][k-1]*(m-j-(k-1))*j)%=MOD;
		if(j+2<=m&&k-2>=0) (f[i][j][k]+=f[i-1][j+2][k-2]*C(j+2))%=MOD;
	  }
	ll ans = 0;
	for(int i=0;i<=m;i++)
	 for(int j=0;j+i<=m;j++)
	  ans=(ans+f[n][i][j])%MOD;
	printf("%lld",ans);
	return 0;
}
