#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=80005,maxe=320005,INF=0x3f3f3f3f;
int n,N,S,T,m,a[205][205],id[205][205];
int son[maxe],nxt[maxe],lnk[maxn],tot=1,flw[maxe],cap[maxe],w[maxe];
inline void add(int x,int y,int f,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;w[tot]=z;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;w[tot]=-z;
}
int dst[maxn],que[maxn],fa[maxn],ed[maxn];
bool vis[maxn];
bool spfa(){
	cl(vis,0);cl(dst,192);
	int hed=0,til=1;
	que[1]=S;dst[S]=0;
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
	scanf("%d%d",&m,&n);
	S=1,T=2;N=2;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++){
	 	scanf("%d",&a[i][j]);
	 	id[i][j]=(N+=2);
	 }
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++){
	 	add(id[i][j],id[i][j]^1,1,0); add(id[i][j],id[i][j]^1,1,a[i][j]);
	 	if (i>1) add(id[i-1][j]^1,id[i][j],1,0);
		if (j>1) add(id[i][j-1]^1,id[i][j],1,0);
	 }
	add(S,id[1][1],2,0); add(id[n][m]^1,T,2,0);
	int ans=0;
	while (spfa()){
		int Min=INF;
		for (int x=T;x!=S;x=fa[x]) Min=min(Min,cap[ed[x]]-flw[ed[x]]);
		for (int x=T;x!=S;x=fa[x]) flw[ed[x]]+=Min,flw[ed[x]^1]-=Min;
		ans+=Min*dst[T];
	}
	printf("%d",ans);
	return 0;
}
