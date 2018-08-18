#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005,maxe=200005,maxs=400005;
int n,q,Root,w[maxn],id[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int mn[maxs],cv[maxs];
inline void pushup(int x) {mn[x]=min(mn[x<<1],mn[x<<1|1]);}
inline void addcv(int x,int w) {mn[x]=cv[x]=w;}
inline void pushdown(int x) {if (cv[x]) {addcv(x<<1,cv[x]);addcv(x<<1|1,cv[x]);cv[x]=0;}}
void build(int x,int l,int r){
	if (l==r) {mn[x]=w[id[l]];cv[x]=0;return;}
	int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr) {addcv(x,w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	ist(x<<1,l,mid,ql,qr,w); ist(x<<1|1,mid+1,r,ql,qr,w);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mn[x];
	if (qr<l||r<ql) return 0x7fffffff;
	int mid=l+r>>1; pushdown(x);
	return min(qry(x<<1,l,mid,ql,qr),qry(x<<1|1,mid+1,r,ql,qr));
}
int in[maxn],out[maxn],dep[maxn],H_son[maxn],siz[maxn],top[maxn],fa[maxn],times,f[maxn][18];
void getdep(int x){
	dep[x]=dep[fa[x]]+1;siz[x]=1;H_son[x]=0;f[x][0]=fa[x];
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]){
	 	fa[son[j]]=x; getdep(son[j]); siz[x]+=siz[son[j]];
	 	if (!H_son[x]||siz[H_son[x]]<siz[son[j]]) H_son[x]=son[j];
	 }
}
void dfs(int x,int lst){
	top[x]=lst; in[x]=++times; id[times]=x;
	if (H_son[x]) dfs(H_son[x],lst);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]&&son[j]!=H_son[x]) dfs(son[j],son[j]);
	out[x]=times;
}
void insert(int x,int y,int w){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ist(1,1,n,in[top[x]],in[x],w); x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	ist(1,1,n,in[x],in[y],w);
}
int lca(int x,int y){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	return x;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	scanf("%d",&Root);
	fa[1]=1;getdep(1); dfs(1,1); build(1,1,n);
	for (int j=1;j<=17;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1];
	while (q--){
		int c;scanf("%d",&c);
		if (c==1) scanf("%d",&Root);else
		if (c==2){
			int x,y,w;scanf("%d%d%d",&x,&y,&w);
			insert(x,y,w);
		}else{
			int x,res;scanf("%d",&x);
			if (x==Root) res=qry(1,1,n,1,n);else
			if (lca(x,Root)!=x) res=qry(1,1,n,in[x],out[x]);else{
				int v=Root;
				for (int j=17;~j;j--)
				 if (dep[f[v][j]]>dep[x]) v=f[v][j];
				res=min(qry(1,1,n,1,in[v]-1),qry(1,1,n,out[v]+1,n));
			}
			printf("%d\n",res);
		}
	}
}
