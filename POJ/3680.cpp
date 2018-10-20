#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=405,maxe=6*maxn,INF=0x3f3f3f3f;
int tst,n,N,K,S,T,b[maxn];
struct data{
	int l,r,w;
}a[maxn];
int son[maxe],nxt[maxe],lnk[maxn],tot,flw[maxe],cap[maxe],w[maxe];
inline void add(int x,int y,int f,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;w[tot]=z;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;w[tot]=-z;
}
int que[maxn],dst[maxn],fa[maxn],ed[maxn];
bool vis[maxn];
bool spfa(){
	cl(vis,0);cl(dst,192);
	int hed=0,til=1;
	que[1]=S;dst[S]=0;vis[S]=1;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (cap[j]>flw[j]&&dst[son[j]]<dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	fa[son[j]]=x; ed[son[j]]=j;
		 	if (!vis[son[j]]) vis[que[til=(til+1)%maxn]=son[j]];
		 }
	}
	return dst[T]!=0xc0c0c0c0;
}
int main(){
	tst=red();
	while (tst--){
		n=red(),K=red();N=0;
		for (int i=1;i<=n;i++) b[++N]=a[i].l=red(),b[++N]=a[i].r=red(),a[i].w=red();
		sort(b+1,b+1+N); N=unique(b+1,b+1+N)-b-1;
		tot=1;cl(lnk,0);S=0;T=N+1;
		for (int i=0;i<=N;i++) add(i,i+1,K,0);
		for (int i=1;i<=n;i++){
			a[i].l=lower_bound(b+1,b+1+N,a[i].l)-b;
			a[i].r=lower_bound(b+1,b+1+N,a[i].r)-b;
			add(a[i].l,a[i].r,1,a[i].w);
		}
		int ans=0;
		while (spfa()){
			int Min=INF;
			for (int x=T;x!=S;x=fa[x]) Min=min(Min,cap[ed[x]]-flw[ed[x]]);
			for (int x=T;x!=S;x=fa[x]) flw[ed[x]]+=Min,flw[ed[x]^1]-=Min;
			ans+=Min*dst[T];
		}
		printf("%d\n",ans);
	}
	return 0;
}
