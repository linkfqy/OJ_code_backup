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

const int maxn=30005,maxe=100005,maxs=120005;
int n,e,q,fa[maxn],ans[maxe];
bool dmg[maxe];
struct edge{
	int x,y;
	edge () {}
	edge (int _x,int _y):x(_x),y(_y) {}
	bool operator<(const edge&b)const {return x<b.x||x==b.x&&y<b.y;}
}a[maxe];
struct ask{
	int x,y,c;
}Q[maxe];
int son[maxe],lnk[maxn],nxt[maxe],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int dep[maxn],siz[maxn],Hson[maxn],top[maxn],dfn[maxn],times;
void getdep(int x){
	siz[x]=1;dep[x]=dep[fa[x]]+1;Hson[x]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]){
	 	fa[son[j]]=x; getdep(son[j]); siz[x]+=siz[son[j]];
	 	if (!Hson[x]||siz[Hson[x]]<siz[son[j]]) Hson[x]=son[j];
	 } 
}
void dfs(int x,int lst){
	top[x]=lst;dfn[x]=++times;
	if (Hson[x]) dfs(Hson[x],lst);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=Hson[x]&&son[j]!=fa[x]) dfs(son[j],son[j]);
}
int s[maxs],cv[maxs];
inline void pushup(int x) {s[x]=s[x<<1]+s[x<<1|1];}
inline void addcv(int x,int l,int r) {s[x]=r-l+1,cv[x]=1;}
inline void pushdown(int x,int l,int r,int mid){if (cv[x]) addcv(x<<1,l,mid),addcv(x<<1|1,mid+1,r),cv[x]=0;}
void ist(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return addcv(x,l,r);
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x,l,r,mid);
	ist(x<<1,l,mid,ql,qr); ist(x<<1|1,mid+1,r,ql,qr);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return s[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x,l,r,mid);
	return qry(x<<1,l,mid,ql,qr)+qry(x<<1|1,mid+1,r,ql,qr);
}
void insert(int x,int y){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ist(1,1,n,dfn[top[x]],dfn[x]); x=fa[top[x]];
	}
	if (dfn[x]>dfn[y]) swap(x,y);
	ist(1,1,n,dfn[x]+1,dfn[y]);
}
int query(int x,int y){
	int res=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res+=dfn[x]-dfn[top[x]]+1-qry(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if (dfn[x]>dfn[y]) swap(x,y);
	return res+dfn[y]-dfn[x]-qry(1,1,n,dfn[x]+1,dfn[y]);
}
int main(){
	n=red(),e=red();
	for (int i=1;i<=e;i++){
		a[i].x=red(),a[i].y=red();
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	sort(a+1,a+1+e);
	for (int c=red();c!=-1;c=red()){
		q++;Q[q].x=red(),Q[q].y=red(),Q[q].c=c;
		if (Q[q].x>Q[q].y) swap(Q[q].x,Q[q].y);
		if (c==0) dmg[lower_bound(a+1,a+1+e,edge(Q[q].x,Q[q].y))-a]=1;
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=e;i++)
	 if (!dmg[i]&&getfa(a[i].x)!=getfa(a[i].y)){
	 	fa[getfa(a[i].x)]=getfa(a[i].y);
	 	add(a[i].x,a[i].y); add(a[i].y,a[i].x);
	 	dmg[i]=1;
	 }
	fa[1]=1;getdep(1);dfs(1,1);
	for (int i=1;i<=e;i++)
	 if (!dmg[i]) insert(a[i].x,a[i].y);
	for (int i=q;i>=1;i--)
	 if (Q[i].c) ans[i]=query(Q[i].x,Q[i].y);else insert(Q[i].x,Q[i].y);
	for (int i=1;i<=q;i++)
	 if (Q[i].c) printf("%d\n",ans[i]);
	return 0;
}
