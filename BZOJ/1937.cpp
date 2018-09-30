#include<cstdio>
#include<cstring>
#include<algorithm>
#define X first
#define Y second
#define mp make_pair
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=805,maxe=160005,INF=0x3f3f3f3f;
int n,e,S,T,a[55][55],b[55][55],id[55][55],fa[maxn];
pair<int,int> E[maxn];
int tot=1,son[maxe],nxt[maxe],lnk[maxn],flw[maxe],cap[maxe],w[maxe];
inline void add(int x,int y,int f,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;w[tot]=z;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;w[tot]=-z;
}
void dfs(int x,int f){
	fa[x]=f;
	for (int j=1;j<=n;j++)
	 if (b[x][j]&&f!=j) dfs(j,x);
}
int que[maxn],dst[maxn],ed[maxn];
bool vis[maxn];
bool spfa(){
	cl(vis,0);cl(dst,192);
	int hed=0,til=1;que[1]=S;dst[S]=0;fa[S]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (flw[j]<cap[j]&&dst[son[j]]<dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	fa[son[j]]=x; ed[son[j]]=j;
		 	if (!vis[son[j]]) vis[que[til=(til+1)%maxn]=son[j]]=1;
		 }
	}
	return dst[T]!=dst[0];
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1;i<=e;i++){
		int x,y;
		scanf("%d%d",&x,&y);scanf("%d",&a[x][y]);
		a[y][x]=a[x][y]; id[x][y]=id[y][x]=i; E[i]=mp(x,y);
	}
	for (int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		b[x][y]=b[y][x]=a[x][y]; a[x][y]=a[y][x]=0;
	}
	for (int i=1;i<=e;i++) if (a[E[i].X][E[i].Y]){
		dfs(E[i].X,0);
		for (int x=E[i].Y;x!=E[i].X;x=fa[x])
		 if (b[fa[x]][x]>a[E[i].X][E[i].Y]) add(id[fa[x]][x],i,1,b[fa[x]][x]-a[E[i].X][E[i].Y]);
	}
	S=e+1;T=S+1;
	for (int i=1;i<=e;i++)
	 if (a[E[i].X][E[i].Y]) add(i,T,1,0);else add(S,i,1,0);
	int ans=0;
	while (spfa()&&dst[T]>0){
		int Min=INF;
		for (int x=T;x!=S;x=fa[x]) Min=min(Min,cap[ed[x]]-flw[ed[x]]);
		for (int x=T;x!=S;x=fa[x]) flw[ed[x]]+=Min,flw[ed[x]^1]-=Min;
		ans+=Min*dst[T];
	}
	printf("%d",ans);
	return 0;
}
