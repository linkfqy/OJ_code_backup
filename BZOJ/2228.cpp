#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=155;
int p,q,r,ans,f[maxn][maxn][maxn],que[maxn],L[maxn],R[maxn];
char s[maxn][maxn][maxn],t[maxn][maxn][maxn];
void doit(int *a){
	int til=0;
	for (int i=1;i<=r;i++){
		while (til&&a[que[til]]>=a[i]) til--;
		if (!til) L[i]=1;else L[i]=que[til]+1;
		que[++til]=i;
	}
	for (int i=r;i>=1;i--){
		while (til&&a[que[til]]>=a[i]) til--;
		if (!til) R[i]=r;else R[i]=que[til]-1;
		que[++til]=i;
	}
	for (int i=1;i<=r;i++) ans=max(ans,a[i]*(R[i]-L[i]+1));
}
void work(){
	for (int k=1;k<=r;k++)
	 for (int i=1;i<=p;i++)
	  for (int j=1;j<=q;j++)
	   if (s[i][j][k]=='N') f[i][j][k]=min(f[i-1][j-1][k],min(f[i][j-1][k],f[i-1][j][k]))+1;
	    else f[i][j][k]=0;
	for (int i=1;i<=p;i++)
	 for (int j=1;j<=q;j++) doit(f[i][j]);
}
int main(){
	scanf("%d%d%d",&q,&p,&r);
	for (int i=1;i<=p;i++)
	 for (int j=1;j<=q;j++) scanf("%s",s[i][j]+1);
	for (int z=1;z<=3;z++){
		work();
		for (int i=1;i<=p;i++)
		 for (int j=1;j<=q;j++)
		  for (int k=1;k<=r;k++) t[j][k][i]=s[i][j][k];
		int tt=p;p=q;q=r;r=tt;
		for (int i=1;i<=p;i++)
		 for (int j=1;j<=q;j++)
		  for (int k=1;k<=r;k++) s[i][j][k]=t[i][j][k];
	}
	printf("%d",ans*4);
	return 0;
}
