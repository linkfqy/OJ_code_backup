#include<cstdio>
#include<cstring>
const int maxn=30,p[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int tst,n,m,s,qx[maxn],qy[maxn];
bool suc,vis[maxn][maxn];
bool check(int x,int y){
	if (x<1||x>n||y<1||y>m) return 0;
	return !vis[x][y];
}
void dfs(int x,int y,int stp){
	if (suc) return;
	qx[stp]=x;qy[stp]=y;
	if (stp==s){suc=1;return;}
	for (int i=0;i<8;i++)
	 if (check(x+p[i][0],y+p[i][1]))
	  if (suc) break;else{
	  	vis[x+p[i][0]][y+p[i][1]]=1,
	  	dfs(x+p[i][0],y+p[i][1],stp+1),
	  	vis[x+p[i][0]][y+p[i][1]]=0;
	  }
}
int main(){
	scanf("%d",&tst);
	for (int t=1;t<=tst;t++){
		printf("Scenario #%d:\n",t);
		scanf("%d%d",&m,&n);
		s=n*m;suc=0;memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++)
		  if (suc) break;else vis[i][j]=1,dfs(i,j,1),vis[i][j]=0;
		if (!suc) printf("impossible\n");else{
			for (int i=1;i<=s;i++) printf("%c%d",qx[i]+'A'-1,qy[i]);
			putchar(10);
		}
		putchar(10);
	}
	return 0;
}
