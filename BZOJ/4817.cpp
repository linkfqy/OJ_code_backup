#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005,maxe=200005,maxs=400005;
int n,q;
int tot,son[maxe],lnk[maxn],nxt[maxe];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int H_son[maxn],siz[maxn],f[maxn],dep[maxn],in[maxn],out[maxn],times,top[maxn],id[maxn];
void getdep(int x){
	dep[x]=dep[f[x]]+1;siz[x]=1;H_son[x]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=f[x]){
	 	f[son[j]]=x; getdep(son[j]); siz[x]+=siz[son[j]];
	 	if (!H_son[x]||siz[H_son[x]]<siz[son[j]]) H_son[x]=son[j];
	 }
}
void dfs(int x,int pre){
	in[x]=++times;top[x]=pre;id[times]=x;
	if (H_son[x]) dfs(H_son[x],pre);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=f[x]&&son[j]!=H_son[x]) dfs(son[j],son[j]);
	out[x]=times;
}
int LCA(int x,int y){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=f[top[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	return x;
}
int mx[maxs],ad[maxs];
inline void pushup(int x) {mx[x]=max(mx[x<<1],mx[x<<1|1]);}
inline void addad(int x,int w) {mx[x]+=w;ad[x]+=w;}
inline void pd(int x) {if (ad[x]) addad(x<<1,ad[x]),addad(x<<1|1,ad[x]),ad[x]=0;}
void build(int x,int l,int r){
	if (l==r) {mx[x]=dep[id[l]];return;}
	int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr) {addad(x,w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pd(x);
	ist(x<<1,l,mid,ql,qr,w); ist(x<<1|1,mid+1,r,ql,qr,w);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mx[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pd(x);
	return max(qry(x<<1,l,mid,ql,qr),qry(x<<1|1,mid+1,r,ql,qr));
}
int s[maxn][2],fa[maxn];
bool flp[maxn];
#define isroot(x) (s[fa[x]][0]!=x&&s[fa[x]][1]!=x)
inline void addflip(int x) {swap(s[x][0],s[x][1]);flp[x]^=1;}
inline void pushdown(int x) {if (flp[x]) addflip(s[x][0]),addflip(s[x][1]),flp[x]=0;}
inline void rotate(int x){
	int f=fa[x],g=fa[f],d=s[f][0]==x;
	if (!isroot(f)) s[g][s[g][1]==f]=x; fa[x]=g;
	s[f][d^1]=s[x][d]; fa[s[x][d]]=f;
	s[x][d]=f; fa[f]=x;
}
int stk[maxn];
inline void splay(int x){
	stk[stk[0]=1]=x;
	for (int i=x;!isroot(i);i=fa[i]) stk[++stk[0]]=fa[i];
	while (stk[0]) pushdown(stk[stk[0]--]);
	while (!isroot(x)){
		int f=fa[x],g=fa[f],d=s[f][0]==x,dd=s[g][0]==f;
		if (!isroot(f))
		 if (d==dd) rotate(f),rotate(x);else
		  rotate(x),rotate(x);else
		rotate(x);
	}
}
inline void work(int x,int w){
	if (!x) return;
	while (s[x][0]) x=s[x][0];
	ist(1,1,n,in[x],out[x],w);
}
inline void access(int x){
	for (int t=0;x;t=x,x=fa[x]){splay(x);work(s[x][1],1);work(t,-1);s[x][1]=t;}
}
#define val(x) qry(1,1,n,in[x],in[x])
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	f[1]=1;getdep(1);dfs(1,1);
	build(1,1,n); for (int i=2;i<=n;i++) fa[i]=f[i];
	while (q--){
		int c,x,y;scanf("%d%d",&c,&x);
		if (c==1) access(x);else
		if (c==2){
			scanf("%d",&y);
			printf("%d\n",val(x)+val(y)-2*val(LCA(x,y))+1);
		}else printf("%d\n",qry(1,1,n,in[x],out[x]));
	}
	return 0;
}
