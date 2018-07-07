#include<cstdio>
#include<cstring>
const int maxn=45,maxp=405,maxe=1005,p[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int tst,n,m,con[maxp],num[2],hsh[maxn][maxn];
int son[maxe],lnk[maxp],nxt[maxe],tot;
char a[maxn][maxn];
bool vis[maxp];
inline char fstchar(){
	char ch=getchar();
	while (ch!='*'&&ch!='o') ch=getchar();
	return ch;
}
void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
bool check(int x,int y){
	if (x<1||y<1||x>n||y>m) return 0;
	return a[x][y]=='*';
}
bool fnd(int x){
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]){
	 	vis[son[j]]=1;
	 	if (!con[son[j]]||fnd(con[son[j]])){
	 		con[son[j]]=x;return 1;
		 }
	 }
	return 0;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		memset(con,0,sizeof(con));
		memset(lnk,0,sizeof(lnk));
		memset(hsh,0,sizeof(hsh));
		tot=num[0]=num[1]=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++){
			a[i][1]=fstchar();
			for (int j=2;j<=m;j++) a[i][j]=getchar();
		}
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++)
		  if (a[i][j]=='*') hsh[i][j]=++num[(i+j)&1];
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++)
		  if ((i+j)&1&&a[i][j]=='*'){
		   for (int t=0;t<4;t++)
		    if (check(i+p[t][0],j+p[t][1])) add(hsh[i][j],hsh[i+p[t][0]][j+p[t][1]]);
		  }
		int ans=0;
		for (int i=1;i<=num[1];i++){
			memset(vis,0,sizeof(vis));
			ans+=fnd(i);
		}
		printf("%d\n",num[0]+num[1]-ans);
	}
	return 0;
}







/*
可以制造01奇偶矩阵，0位和1位分别为二分图的两个点集
那么答案就是：总'*'数-最大匹配次数 
*/
