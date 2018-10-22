#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x));
using namespace std;

const int maxn=300005,maxe=1000005,INF=0x3f3f3f3f;
int n,m; char a[505][505];
#define ID(x,y) (((x)-1)*(m+1)+(y))
int son[maxe],nxt[maxe],lnk[maxn],tot,w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int S,T,dst[maxn],que[maxn];
bool vis[maxn];
void spfa(){
	cl(dst,63);cl(vis,0);
	int hed=0,til=1;
	que[1]=S;dst[S]=0;vis[S]=1;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]])
		 	 vis[que[til=(til+1)%maxn]=son[j]]=1;
		 }
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  if (a[i][j]=='/'){
	  	add(ID(i+1,j),ID(i,j+1),0),add(ID(i,j+1),ID(i+1,j),0),
	  	add(ID(i,j),ID(i+1,j+1),1),add(ID(i+1,j+1),ID(i,j),1);
	  }else{
	  	add(ID(i+1,j),ID(i,j+1),1),add(ID(i,j+1),ID(i+1,j),1),
	  	add(ID(i,j),ID(i+1,j+1),0),add(ID(i+1,j+1),ID(i,j),0);
	  }
	S=1,T=(n+1)*(m+1);
	spfa();
	if (dst[T]==INF) puts("NO SOLUTION");else printf("%d",dst[T]);
	return 0;
}
