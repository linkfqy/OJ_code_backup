#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=250005,maxe=500005;
int n,q,K,h[maxn],stk[maxn],top;
int son[maxe],lnk[maxn],nxt[maxe],tot;
ll  w[maxe]; bool imp[maxn];
inline void add(int x,int y,ll z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int dfn[maxn],fa[maxn][18],times,dep[maxn];
ll g[maxn][18],f[maxn];
void dfs(int x,int Fa){
	fa[x][0]=Fa; dep[x]=dep[Fa]+1; dfn[x]=++times;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=Fa) g[son[j]][0]=w[j],dfs(son[j],x);
}
void DP(){
	for (int j=1;j<18;j++)
	 for (int i=1;i<=n;i++)
	  fa[i][j]=fa[fa[i][j-1]][j-1],
	  g[i][j]=min(g[i][j-1],g[fa[i][j-1]][j-1]);
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=17;~j;j--)
	 if (dep[fa[x][j]]>=dep[y]) x=fa[x][j];
	if (x==y) return x;
	for (int j=17;~j;j--)
	 if (fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
	return fa[x][0];
}
ll dst(int x,int y){
	ll res=1e18;
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=17;~j;j--)
	 if (dep[fa[x][j]]>=dep[y]) res=min(res,g[x][j]),x=fa[x][j];
	if (x==y) return res;
	for (int j=17;~j;j--)
	 if (fa[x][j]!=fa[y][j]) res=min(res,min(g[x][j],g[y][j])),x=fa[x][j],y=fa[y][j];
	return min(res,min(g[x][0],g[y][0]));
}
void insert(int x){
	if (!top) {stk[++top]=x;return;}
	int lca=LCA(x,stk[top]);
	while (top>1&&dfn[stk[top-1]]>dfn[lca]) add(stk[top-1],stk[top],dst(stk[top-1],stk[top])),top--;
	if (dfn[stk[top]]>dfn[lca]) add(lca,stk[top],dst(lca,stk[top])),top--;
	if (!top||dfn[stk[top]]<dfn[lca]) stk[++top]=lca;
	stk[++top]=x;
}
void treedp(int x){
	f[x]=0;
	for (int j=lnk[x];j;j=nxt[j]){
		treedp(son[j]);
		if (imp[son[j]]) f[x]+=w[j];else f[x]+=min(w[j],f[son[j]]);
	}
	lnk[x]=0;
}
inline bool cmp(const int&x,const int&y) {return dfn[x]<dfn[y];}
int main(){
	scanf("%d",&n);
	for (int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	g[1][0]=1e18; dfs(1,1); DP(); cl(lnk,0);
	scanf("%d",&q);
	while (q--){
		scanf("%d",&K);
		for (int i=1;i<=K;i++) scanf("%d",&h[i]);h[++K]=1;
		sort(h+1,h+1+K,cmp); tot=top=0;
		for (int i=1;i<=K;i++) insert(h[i]),imp[h[i]]=1;
		while (top>1) add(stk[top-1],stk[top],dst(stk[top-1],stk[top])),top--;
		treedp(stk[1]);
		for (int i=1;i<=K;i++) imp[h[i]]=0;
		printf("%lld\n",f[1]);
	}
	return 0;
}
