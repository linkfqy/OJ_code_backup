#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005,maxe=200005,maxs=4*maxn;
int n,N,w[maxn],id[maxn];
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int mx[maxs],ad[maxs],cv[maxs];
inline void pushup(int x) {mx[x]=max(mx[x<<1],mx[x<<1|1]);}
inline void addad(int x,int w) {mx[x]+=w,ad[x]+=w;if (cv[x]) cv[x]+=w;}
inline void addcv(int x,int w) {mx[x]=w;cv[x]=w;ad[x]=0;}
inline void pushdown(int x){
	if (ad[x]) {addad(x<<1,ad[x]);addad(x<<1|1,ad[x]);ad[x]=0;}
	if (cv[x]) {addcv(x<<1,cv[x]);addcv(x<<1|1,cv[x]);cv[x]=0;}
}
void ist(int x,int l,int r,int ql,int qr,int w){  //+w:add    -w:cover 
	if (ql<=l&&r<=qr) {if (w>0) addad(x,w);else addcv(x,-w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	ist(x<<1,l,mid,ql,qr,w); ist(x<<1|1,mid+1,r,ql,qr,w);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mx[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x);
	return max(qry(x<<1,l,mid,ql,qr),qry(x<<1|1,mid+1,r,ql,qr));
}
int H_son[maxn],siz[maxn],fa[maxn],dep[maxn],in[maxn],out[maxn],top[maxn],times;
void getH(int x){
	siz[x]=1;dep[x]=dep[fa[x]]+1;H_son[x]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]){
		id[j+1>>1]=son[j];fa[son[j]]=x; getH(son[j]); siz[x]+=siz[son[j]];
		if (!H_son[x]||siz[H_son[x]]<siz[son[j]]) H_son[x]=son[j];
	 }
}
void dfs(int x,int lst){
	top[x]=lst;in[x]=++times;
	if (H_son[x]) dfs(H_son[x],lst);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]&&son[j]!=H_son[x]) dfs(son[j],son[j]);
	out[x]=times;
}
void cao(int x,int y,int w){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ist(1,1,N,in[top[x]],in[x],w); x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	ist(1,1,N,in[x]+1,in[y],w);
}
int ask(int x,int y){
	int res=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res=max(res,qry(1,1,N,in[top[x]],in[x])); x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	return max(res,qry(1,1,N,in[x]+1,in[y]));
}
char s[20];
int main(){
	scanf("%d",&n); N=n;
	for (int i=1,x,y;i<n;i++) scanf("%d%d%d",&x,&y,&w[i]),add(y,x),add(x,y);
	fa[1]=1;getH(1); dfs(1,1);
	for (int i=1;i<n;i++) ist(1,1,N,in[id[i]],in[id[i]],-w[i]);
	for (scanf("%s",s);s[0]!='S';scanf("%s",s))
	 if (s[1]=='h'){
	 	int x,w;scanf("%d%d",&x,&w);
	 	ist(1,1,N,in[id[x]],in[id[x]],-w);
	 }else
	 if (s[1]=='o'){
	 	int x,y,w;scanf("%d%d%d",&x,&y,&w);
	 	cao(x,y,-w);
	 }else
	 if (s[1]=='d'){
	 	int x,y,w;scanf("%d%d%d",&x,&y,&w);
	 	cao(x,y,w);
	 }else{
	 	int x,y;scanf("%d%d",&x,&y);
	 	printf("%d\n",ask(x,y));
	 }
	 return 0;
}
