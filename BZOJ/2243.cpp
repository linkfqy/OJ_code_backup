#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=100005,maxe=200005,maxs=4*maxn;
int n,q,c[maxn],id[maxn];
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
struct node{
	int x,l,r,cv;
	node () {cv=-1;}
	node (int _x,int _l,int _r):x(_x),l(_l),r(_r),cv(-1) {}
	inline void addcv(int w) {l=r=cv=w;x=1;}
}tre[maxs];
inline node operator+(const node&a,const node&b) {return node(a.x+b.x-(a.r==b.l),a.l,b.r);}
inline void pushdown(int x){
	if (tre[x].cv>=0){
		tre[x<<1].addcv(tre[x].cv);
		tre[x<<1|1].addcv(tre[x].cv);
		tre[x].cv=-1;
	}
}
void buildtree(int x,int l,int r){
	if (l==r) {tre[x].addcv(c[id[l]]);return;}
	int mid=l+r>>1;
	buildtree(x<<1,l,mid); buildtree(x<<1|1,mid+1,r);
	tre[x]=tre[x<<1]+tre[x<<1|1];
}
void ist(int x,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr) {tre[x].addcv(w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	ist(x<<1,l,mid,ql,qr,w); ist(x<<1|1,mid+1,r,ql,qr,w);
	tre[x]=tre[x<<1]+tre[x<<1|1];
}
node qry(int x,int l,int r,int ql,int qr){
	if (ql==l&&r==qr) return tre[x];
	int mid=l+r>>1; pushdown(x);
	if (qr<=mid) return qry(x<<1,l,mid,ql,qr);else
	if (ql>mid) return qry(x<<1|1,mid+1,r,ql,qr);else
	return qry(x<<1,l,mid,ql,mid)+qry(x<<1|1,mid+1,r,mid+1,qr);
}
int H_son[maxn],siz[maxn],fa[maxn],dep[maxn],in[maxn],out[maxn],top[maxn],times;
void getH(int x){
	siz[x]=1;dep[x]=dep[fa[x]]+1;H_son[x]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]){
		fa[son[j]]=x; getH(son[j]); siz[x]+=siz[son[j]];
		if (!H_son[x]||siz[H_son[x]]<siz[son[j]]) H_son[x]=son[j];
	 }
}
void dfs(int x,int lst){
	top[x]=lst;in[x]=++times;id[times]=x;
	if (H_son[x]) dfs(H_son[x],lst);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]&&son[j]!=H_son[x]) dfs(son[j],son[j]);
	out[x]=times;
}
int LCA(int x,int y){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	return x;
}
void cao(int x,int y,int w){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ist(1,1,n,in[top[x]],in[x],w); x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	ist(1,1,n,in[x],in[y],w);
}
int ask(int x,int y){
	node res;bool fir=1;
	while (top[x]!=top[y]){
		if (fir) res=qry(1,1,n,in[top[x]],in[x]),fir=0;
		 else res=qry(1,1,n,in[top[x]],in[x])+res;
		x=fa[top[x]];
	}
	if (fir) res=qry(1,1,n,in[y],in[x]),fir=0;
	 else res=qry(1,1,n,in[y],in[x])+res;
	return res.x;
}
char s[20];
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(y,x),add(x,y);
	fa[1]=1;getH(1); dfs(1,1);
	buildtree(1,1,n);
	while (q--){
		scanf("%s",s);
		if (s[0]=='C'){
			int x,y,c;scanf("%d%d%d",&x,&y,&c);
			cao(x,y,c);
		}else{
			int x,y,lca;scanf("%d%d",&x,&y);
			lca=LCA(x,y);
			printf("%d\n",ask(x,lca)+ask(y,lca)-1);
		}
	}
	return 0;
}
