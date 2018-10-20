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

const int maxn=200005,maxe=800005;
int n,s,e,q,c[maxn];
int son[maxe],nxt[maxe],lnk1[maxn],lnk2[maxn],w[maxe],tot;
inline void add(int x,int y,int z,int *lnk){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int que[maxn],dst[maxn],frm[maxn];
bool vis[maxn];
void spfa(){
	cl(dst,63);
	int hed=0,til=0;
	for (int i=1;i<=s;i++) que[++til]=c[i],dst[c[i]]=0,vis[c[i]]=1,frm[c[i]]=c[i];
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk1[x];j;j=nxt[j])
		 if (dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	frm[son[j]]=frm[x];
		 	if (!vis[son[j]])
		 	 vis[que[til=(til+1)%maxn]=son[j]]=1;
		 }
	}
}
struct edge{
	int x,y,w;
	bool operator<(const edge&b)const {return w<b.w;}
}a[maxn],b[maxn];
int fa[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int f[maxn][18],g[maxn][18],dep[maxn];
void dfs(int x){
	vis[x]=1;dep[x]=dep[f[x][0]]+1;
	for (int j=lnk2[x];j;j=nxt[j])
	 if (!vis[son[j]]) f[son[j]][0]=x,g[son[j]][0]=w[j],dfs(son[j]);
}
void DP(){
	for (int j=1;j<=17;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1],
	  g[i][j]=max(g[i][j-1],g[f[i][j-1]][j-1]);
}
int LCA(int x,int y){
	int res=0;
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=17;~j;j--)
	 if (dep[f[x][j]]>=dep[y]) res=max(res,g[x][j]),x=f[x][j];
	if (x==y) return res;
	for (int j=17;~j;j--)
	 if (f[x][j]!=f[y][j]) res=max(res,max(g[x][j],g[y][j])),x=f[x][j],y=f[y][j];
	return max(res,max(g[x][0],g[y][0]));
}
int main(){
	n=red(),s=red(),e=red();
	for (int i=1;i<=s;i++) c[i]=red();
	for (int i=1,x,y,z;i<=e;i++) a[i].x=x=red(),a[i].y=y=red(),a[i].w=z=red(),add(x,y,z,lnk1),add(y,x,z,lnk1);
	spfa();
	for (int i=1;i<=e;i++) b[i].x=frm[a[i].x],b[i].y=frm[a[i].y],b[i].w=dst[a[i].x]+dst[a[i].y]+a[i].w;
	sort(b+1,b+1+e);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=e;i++)
	 if (getfa(b[i].x)!=getfa(b[i].y)){
	 	fa[getfa(b[i].x)]=getfa(b[i].y);
	 	add(b[i].x,b[i].y,b[i].w,lnk2); add(b[i].y,b[i].x,b[i].w,lnk2);
	 }
	cl(vis,0);
	for (int i=1;i<=s;i++)
	 if (!vis[c[i]]) f[c[i]][0]=0,g[c[i]][0]=0,dfs(c[i]);
	DP();
	q=red();
	while (q--){
		int x=red(),y=red(),d=red();
		if (getfa(x)!=getfa(y)) puts("NIE");else
		puts(LCA(x,y)<=d?"TAK":"NIE");
	}
	return 0;
}
