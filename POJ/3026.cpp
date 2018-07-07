#include<cstdio>
#include<cstring>
const int maxn=55,maxe=10005,maxa=105,p[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int tst,n,m,ans,x[maxa],y[maxa],tot,hsh[maxn][maxn];
int cst[maxa][maxa],dst[maxa];
bool vis[maxa],usd[maxn][maxn];
char a[maxn][maxn];
struct ha{
	int x,y,s;
}que[2505];
bool check(int x,int y){
	return !usd[x][y]&&a[x][y]!='#';
}
void bfs(int x,int y,int id){
	memset(usd,0,sizeof(usd));
	int hed=0,til=1;
	que[til]=(ha){x,y,0};usd[x][y]=1;
	while (hed!=til){
		x=que[++hed].x;y=que[hed].y;
		for (int i=0;i<4;i++)
		 if (check(x+p[i][0],y+p[i][1])){
		 	que[++til]=(ha){x+p[i][0],y+p[i][1],que[hed].s+1};
		 	usd[x+p[i][0]][y+p[i][1]]=1;
		 	if (hsh[que[til].x][que[til].y]) cst[id][hsh[que[til].x][que[til].y]]=que[til].s;
		 }
	}
}
void prim(){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=tot;i++) dst[i]=cst[1][i];
	vis[1]=1;
	for (int i=1;i<tot;i++){
		int k,Min=0x3f3f3f3f;
		for (int j=1;j<=tot;j++)
		 if (!vis[j]&&Min>dst[j]) Min=dst[j],k=j;
		vis[k]=1;ans+=Min;
		for (int j=1;j<=tot;j++)
		 if (dst[j]>cst[k][j]) dst[j]=cst[k][j];
	}
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		memset(hsh,0,sizeof(hsh));
		memset(cst,63,sizeof(cst));
		tot=0;ans=0;
		scanf("%d%d%*[^\n]",&m,&n);getchar();
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				a[i][j]=getchar();
				if (a[i][j]=='A'||a[i][j]=='S') x[++tot]=i,y[tot]=j,hsh[i][j]=tot;
			}
			scanf("%*[^\n]");getchar();
		}
		for (int i=1;i<=tot;i++) bfs(x[i],y[i],i),cst[i][i]=0;
//		for (int i=1;i<=tot;i++){
//			for (int j=1;j<=tot;j++) printf("%d ",cst[i][j]);
//			putchar(10);
//		}
		prim();
		printf("%d\n",ans);
	}
	return 0;
}






/*
这题行末可能会有多余空格……
scanf("%*[^\n]")貌似与"%*c"不太配……只能用getchar()

*/
