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

const int maxn=10005,maxe=10005,INF=0x3f3f3f3f;
int n,m,S,T,win[maxn],los[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
int son[maxe],nxt[maxe],lnk[maxn],tot,flw[maxe],cap[maxe],w[maxe];
inline void add(int x,int y,int f,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;w[tot]=z;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;w[tot]=-z;
}
int que[maxn],dst[maxn],fa[maxn],ed[maxn];
bool vis[maxn];
bool spfa(){
	cl(dst,63);cl(vis,0);
	int hed=0,til=1;
	que[1]=S;vis[S]=1;dst[S]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (flw[j]<cap[j]&&dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	fa[son[j]]=x; ed[son[j]]=j;
		 	if (!vis[son[j]]) vis[que[til=(til+1)%maxn]=son[j]]=1;
		 }
	}
	return dst[T]!=INF;
}
int main(){
	n=red(),m=red();
	for (int i=1;i<=n;i++)
	 win[i]=red(),los[i]=red(),c[i]=red(),d[i]=red();
	for (int i=1;i<=m;i++)
	 a[i]=red(),b[i]=red(),los[a[i]]++,los[b[i]]++;
	int ans=0;
	for (int i=1;i<=n;i++)
	 ans+=c[i]*win[i]*win[i]+d[i]*los[i]*los[i];
	tot=1;S=n+m+1;T=S+1;
	for (int i=1;i<=m;i++){
		add(S,i+n,1,0); add(i+n,a[i],1,0); add(i+n,b[i],1,0);
		add(a[i],T,1,c[a[i]]*(win[a[i]]*2+1)-d[a[i]]*(los[a[i]]*2-1));
		win[a[i]]++;los[a[i]]--;
		add(b[i],T,1,c[b[i]]*(win[b[i]]*2+1)-d[b[i]]*(los[b[i]]*2-1));
		win[b[i]]++;los[b[i]]--;
	}
	while (spfa()){
		int Min=INF;
		for (int x=T;x!=S;x=fa[x]) Min=min(Min,cap[ed[x]]-flw[ed[x]]);
		for (int x=T;x!=S;x=fa[x]) flw[ed[x]]+=Min,flw[ed[x]^1]-=Min;
		ans+=Min*dst[T];
	}
	printf("%d",ans);
	return 0;
}
