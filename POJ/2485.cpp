#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=505;
int tst,n,a[maxn][maxn],dst[maxn],ans=0;
bool vis[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
void prim(){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) dst[i]=a[1][i];
	vis[1]=1;
	for (int i=1;i<n;i++){
		int k,Min=0x3f3f3f3f;
		for (int j=1;j<=n;j++)
		 if (!vis[j]&&Min>dst[j]) Min=dst[j],k=j;
		vis[k]=1;
		ans=max(ans,dst[k]);
		for (int j=1;j<=n;j++)
		 if (dst[j]>a[k][j]) dst[j]=a[k][j];
	}
}
int main(){
	tst=red();
	while (tst--){
		n=red();ans=0;
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=n;j++)
		  a[i][j]=red();
		prim();
		printf("%d\n",ans);
	}
	return 0;
}
