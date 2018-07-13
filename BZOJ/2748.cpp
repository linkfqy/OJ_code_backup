#include<cstdio>

const int maxn=55,maxs=1005;
int n,begin,m;
bool f[maxn][maxs];
int main(){
	scanf("%d%d%d",&n,&begin,&m);
	f[0][begin]=1;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		for (int j=0;j<=m;j++){
			if (j-x>=0) f[i][j]|=f[i-1][j-x];
			if (j+x<=m) f[i][j]|=f[i-1][j+x];
		}
	}
	int ans=-1;
	for (int i=m;i>=0;i--) if (f[n][i]) {ans=i;break;}
	printf("%d",ans);
	return 0;
}
