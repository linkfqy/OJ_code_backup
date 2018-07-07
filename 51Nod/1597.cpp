#include<cstdio>
#include<cmath>
#include<cstring>
typedef long long ll;

const int maxn=100005,maxs=320,tt=23333333;
int n,s,f[2][maxn],g[2][maxn],tem[maxn];
inline void Madd(int &x,int y) {if ((x+=y)>=tt) x-=tt;}
int main(){
	scanf("%d",&n);s=sqrt(n);
	f[0][0]=1;
	for (int i=1;i<=s;i++){
		memset(tem,0,sizeof(tem));
		for (int j=0;j<=n;j++){
			Madd(tem[j%i],f[i&1^1][j]);
			f[i&1][j]=tem[j%i];
			if (j-i*i>=0) Madd(tem[j%i],tt-f[i&1^1][j-i*i]);
		}
	}
	g[0][0]=1;int ans=f[s&1][n];
	for (int i=1;i<=s;i++){
		for (int j=0;j<i;j++) g[i&1][j]=0;
		for (int j=i;j<=n;j++){
			g[i&1][j]=g[i&1][j-i];
			if (j>s) Madd(g[i&1][j],g[i&1^1][j-s-1]);
			Madd(ans,(ll)g[i&1][j]*f[s&1][n-j]%tt);
		}
	}
	printf("%d",ans);
	return 0;
}
