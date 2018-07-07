#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long LL;
using namespace std;

const int maxn=1005,maxe=40005;
const LL INF=0x3f3f3f3f3f3f3f3fll;
int n,m,a[maxn],S,T;
int tot,lnk[maxn],son[maxe],nxt[maxe];
LL flw[maxe],cap[maxe],w[maxe];
inline void add(int x,int y,LL f,int wi){// printf("%d %d %lld %d\n",x,y,f,wi);
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;w[tot]=wi;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;w[tot]=-wi;
}
int que[maxn],ed[maxn],fa[maxn];
LL dst[maxn],ans;
bool vis[maxn];
bool spfa(){
	cl(dst,63);cl(vis,0);
	int hed=0,til=1;
	que[1]=S;dst[S]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (cap[j]>flw[j]&&dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	fa[son[j]]=x,ed[son[j]]=j;
		 	if (!vis[son[j]])
		 	 vis[son[j]]=1,que[til=(til+1)%maxn]=son[j];
		 }
	}
	if (dst[T]==INF) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);tot=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1,s,t,w;i<=m;i++)
	 scanf("%d%d%d",&s,&t,&w),add(s,t+1,INF,w);
	for (int i=1;i<=n;i++) add(i+1,i,INF,0);
	n++;S=n+1;T=n+2;
	for (int i=1;i<=n;i++)
	 if (a[i-1]<a[i]) add(S,i,a[i]-a[i-1],0);else add(i,T,a[i-1]-a[i],0);
	
	while (spfa()){
		LL Min=INF;
		for (int j=T;j!=S;j=fa[j]) Min=min(Min,cap[ed[j]]-flw[ed[j]]);
		for (int j=T;j!=S;j=fa[j]) flw[ed[j]]+=Min,flw[ed[j]^1]-=Min;
		ans+=dst[T]*Min;
	}
	printf("%lld",ans);
	return 0;
}
