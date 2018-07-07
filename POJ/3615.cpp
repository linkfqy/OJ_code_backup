#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=305,INF=0x3f3f3f3f;
int n,e,q,f[maxn][maxn];
#define nc getchar
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}
int main(){
	n=red(),e=red(),q=red();
	memset(f,63,sizeof(f));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=e;i++){
		int x=red(),y=red(),z=red();
		f[x][y]=min(f[x][y],z);
	}
	for (int k=1;k<=n;k++)
	 for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	   f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
	while (q--){
		int x=red(),y=red();
		printf("%d\n",f[x][y]==INF?-1:f[x][y]);
	}
	return 0;
}
