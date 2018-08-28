#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn=1005,t1[8]={1,0,-1,0,1,1,-1,-1},t2[8]={0,1,0,-1,1,-1,1,-1};
int n,ans1,ans2,w[maxn][maxn],f[maxn][maxn],q[maxn*maxn][2];
void bfs(int sx,int sy){
	int l=0,r=1,f1=1,f2=1; q[1][0]=sx,q[1][1]=sy,f[sx][sy]=true;
	while (l<r){
		int xx=q[++l][0],yy=q[l][1];
		for (int i=0;i<8;i++){
			int x=xx+t1[i],y=yy+t2[i];
			if (x&&x<=n&&y&&y<=n)
				if (w[xx][yy]>w[x][y]) f1=0;
				else if (w[xx][yy]==w[x][y]&&!f[x][y]){
					q[++r][0]=x,q[r][1]=y,f[x][y]=true;
				}
				else if (w[xx][yy]<w[x][y]) f2=0;
		}
	}
	if (!f1&&f2) ans1++;
	if (f1&&!f2) ans2++;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++) scanf("%d",&w[i][j]);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++) if (!f[i][j]) bfs(i,j);
	if (!ans1&&!ans2) ans1=ans2=1;
	return printf("%d %d\n",ans1,ans2),0;
}
