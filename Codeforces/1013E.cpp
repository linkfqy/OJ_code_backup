#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=5005;
int n,a[maxn],f[maxn][maxn][2];
inline int w(int x,int y){
	return max(0,x-y);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	cl(f,63);
	f[0][0][0]=0;
	for (int i=1;i<=n;i++)
	 for (int j=0;j<=i;j++){
	 	f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]);
	 	if (i==1&&j>0) f[i][j][1]=w(a[i+1],a[i]-1);
	 	if (i>1&&j>0) f[i][j][1]=min(f[i-2][j-1][0]+w(a[i-1],a[i]-1),f[i-2][j-1][1]+w(min(a[i-2]-1,a[i-1]),a[i]-1))+w(a[i+1],a[i]-1);
	 }
	for (int i=1;i<=(n+1)/2;i++) printf("%d ",min(f[n][i][0],f[n][i][1]));
	return 0;
}
