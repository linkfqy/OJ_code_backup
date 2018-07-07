#include<cstdio>
#include<cmath>
#include<vector>
#define vit vector<int>::iterator
#define pb push_back
#include<algorithm>
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=300005,maxe=600005;
int n,q,lgn,up[maxe],down[maxe],ans[maxn],w[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int dep[maxn],f[maxn][20];
void getdep(int x,int fa){
	f[x][0]=fa;dep[x]=dep[fa]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) getdep(son[j],x);
}
void DP(){
	for (int j=1;j<=lgn;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1];
}
inline int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=lgn;j>=0;j--)
	 if (dep[f[x][j]]>=dep[y]) x=f[x][j];
	if (x==y) return x;
	for (int j=lgn;j>=0;j--)
	 if (f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return f[x][0];
}
vector<int> a[2][maxn],b[2][maxn];
void dfs(int x,int fa){
	int lu=up[dep[x]+w[x]],ld=down[dep[x]-w[x]+300000];
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) dfs(son[j],x);
	for (vit it=a[0][x].begin();it!=a[0][x].end();it++)
	 up[*it]++;
	for (vit it=b[0][x].begin();it!=b[0][x].end();it++)
	 down[*it]++;
	ans[x]+=up[dep[x]+w[x]]-lu + down[dep[x]-w[x]+300000]-ld; 
	for (vit it=a[1][x].begin();it!=a[1][x].end();it++)
	 up[*it]--;
	for (vit it=b[1][x].begin();it!=b[1][x].end();it++)
	 down[*it]--;
}
int main(){
	n=red(),q=red();lgn=log2(n);
	for (int i=1,x,y;i<n;i++) x=red(),y=red(),add(x,y),add(y,x);
	getdep(1,1);DP();
	for (int i=1;i<=n;i++) w[i]=red();
	while (q--){
		int x=red(),y=red(),lca=LCA(x,y),t=dep[x]+dep[y]-2*dep[lca];
		a[1][lca].pb(dep[x]),a[0][x].pb(dep[x]),
		b[1][lca].pb(dep[y]-t+300000),b[0][y].pb(dep[y]-t+300000);
		if (w[lca]==dep[x]-dep[lca]) ans[lca]--;
	}
	dfs(1,0);
	for (int i=1;i<n;i++) printf("%d ",ans[i]);printf("%d",ans[n]);
	return 0;
}
