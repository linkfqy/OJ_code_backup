#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long LL;

const int maxn=10005,maxe=40005,INF=0x3f3f3f3f;
int n,m,a[maxn],S,T;
int tot,lnk[maxn],nxt[maxe],son[maxe],flw[maxe],cap[maxe],w[maxe];
inline void add(int x,int y,int f,int wi){//printf("%d %d %d %d\n",x,y,f,wi);
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;w[tot]=wi;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;w[tot]=-wi;
}
int dst[maxn],que[maxn],ed[maxn],fa[maxn];
bool vis[maxn];
LL ans=0;
bool spfa(){
	cl(vis,0);cl(dst,192);
	int hed=0,til=1;
	que[1]=S;dst[S]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (cap[j]>flw[j]&&dst[son[j]]<dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	fa[son[j]]=x;ed[son[j]]=j;
		 	if (!vis[son[j]])
		 	 vis[son[j]]=1,que[til=(til+1)%maxn]=son[j];
		 }
	}
	return dst[T]+INF!=-1;
}
int main(){
	scanf("%d%d",&n,&m);
	S=n+2;T=n+3;tot=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v+1,INF,w);
	}
	for (int i=1;i<=n;i++) add(i,i+1,INF,0);n++;
	for (int i=1;i<=n;i++)
	 if (a[i]-a[i-1]>0) add(S,i,a[i]-a[i-1],0);else
	  add(i,T,a[i-1]-a[i],0);
	while (spfa()){
		int Min=INF;
		for (int j=T;j!=S;j=fa[j]) Min=min(Min,cap[ed[j]]-flw[ed[j]]);
		for (int j=T;j!=S;j=fa[j]) flw[ed[j]]+=Min,flw[ed[j]^1]-=Min;
		ans+=(LL)Min*dst[T];
	}
	printf("%lld",ans);
	return 0;
}
