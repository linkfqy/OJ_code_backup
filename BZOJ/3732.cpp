#include<cstdio>
#include<algorithm>
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

const int maxn=15005,maxe=30005;
int n,e,q,fa[maxn];
struct edge{
	int x,y,w;
	bool operator<(const edge&b)const {return w<b.w;}
}a[maxe];
int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
void kruskal(){
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=e;i++){
		if (getfa(a[i].x)==getfa(a[i].y)) continue;
		fa[getfa(a[i].x)]=getfa(a[i].y);
		add(a[i].x,a[i].y,a[i].w);add(a[i].y,a[i].x,a[i].w);
	}
}
int f[maxn][15],g[maxn][15],dep[maxn];
void dfs(int x,int fa){
	f[x][0]=fa;dep[x]=dep[fa]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) g[son[j]][0]=w[j],dfs(son[j],x);
}
void DP(){
	for (int j=1;j<15;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1],
	  g[i][j]=max(g[i][j-1],g[f[i][j-1]][j-1]);
}
int LCA(int x,int y){
	int res=0;
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=14;j>=0;j--)
	 if (dep[f[x][j]]>=dep[y]) res=max(res,g[x][j]),x=f[x][j];
	if (x==y) return res;
	for (int j=14;j>=0;j--)
	 if (f[x][j]!=f[y][j]) res=max(res,max(g[x][j],g[y][j])),x=f[x][j],y=f[y][j];
	return max(res,max(g[x][0],g[y][0]));
}
int main(){
	n=red(),e=red(),q=red();
	for (int i=1;i<=e;i++) a[i].x=red(),a[i].y=red(),a[i].w=red();
	sort(a+1,a+1+e); kruskal();
	dfs(1,1);DP();
	for (int i=1,x,y;i<=q;i++)
	 x=red(),y=red(),printf("%d\n",LCA(x,y));
	return 0;
}
