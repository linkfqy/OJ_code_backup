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

const int maxn=100005,maxe=1000005,maxs=maxn+maxe;
int n,e,q;
struct edge{
	int x,y,w,id;
	edge () {}
	edge (int _x,int _y):x(_x),y(_y) {}
	bool operator<(const edge&b)const {return x<b.x||x==b.x&&y<b.y;}
}a[maxe];
inline bool cmpw(const edge&a,const edge&b) {return a.w<b.w;}
inline bool cmpid(const edge&a,const edge&b) {return a.id<b.id;}
struct query{
	int x,y,type;
}Q[maxn]; bool vis[maxe];
//LCT
int fa[maxs],s[maxs][2],ID[maxs],mx[maxs],w[maxs];
bool flp[maxs];
#define isroot(x) (s[fa[x]][0]!=x&&s[fa[x]][1]!=x)
inline void addflip(int x) {flp[x]^=1;swap(s[x][0],s[x][1]);}
inline void pushup(int x){
	ID[x]=x;mx[x]=w[x];
	if (mx[s[x][0]]>mx[x]) ID[x]=ID[s[x][0]],mx[x]=mx[s[x][0]];
	if (mx[s[x][1]]>mx[x]) ID[x]=ID[s[x][1]],mx[x]=mx[s[x][1]];
}
inline void pushdown(int x) {if (flp[x]) flp[x]^=1,addflip(s[x][0]),addflip(s[x][1]);}
inline void rotate(int x){
	int f=fa[x],g=fa[f],d=s[f][0]==x;
	if (!isroot(f)) s[g][s[g][1]==f]=x; fa[x]=g;
	s[f][d^1]=s[x][d]; fa[s[x][d]]=f; pushup(f);
	s[x][d]=f; fa[f]=x; pushup(x);
}
int stk[maxs],top;
inline void splay(int x){
	stk[top=1]=x;
	for (int i=x;!isroot(i);i=fa[i]) stk[++top]=fa[i];
	while (top) pushdown(stk[top--]);
	while (!isroot(x)){
		int f=fa[x],g=fa[f],d=s[f][0]==x,dd=s[g][0]==f;
		if (!isroot(f))
		 if (d==dd) rotate(f),rotate(x);else
		 rotate(x),rotate(x);
		else rotate(x);
	}
}
inline void access(int x) {for (int t=0;x;t=x,x=fa[x]) splay(x),s[x][1]=t,pushup(x);}
inline void mr(int x) {access(x);splay(x);addflip(x);}
inline void cut(int x,int y) {mr(x);access(y);splay(y);fa[x]=s[y][0]=0;/*printf("cut:%d %d\n",x,y);*/}
inline void join(int x,int y) {mr(x);fa[x]=y;/*printf("link:%d %d\n",x,y);*/}
inline int getrt(int x) {access(x);splay(x);while (s[x][0]) pushdown(x),x=s[x][0];splay(x);return x;}

int fat[maxn],ans[maxn];
inline int getfa(int x) {return fat[x]==x?x:fat[x]=getfa(fat[x]);}
inline void add(edge&E){
	if (getrt(E.x)==getrt(E.y)){
		mr(E.x);access(E.y);splay(E.y);
		int id=ID[E.y]; if (w[id]<=E.w) return;
		cut(id,a[id-n].x);cut(id,a[id-n].y);
	}
	int id=E.id+n;
	mx[id]=w[id]=E.w;ID[id]=id;
	join(id,E.x);join(id,E.y);
}
int main(){
	n=red(),e=red(),q=red();
	for (int i=1;i<=e;i++){
		a[i].x=red(),a[i].y=red(),a[i].w=red();a[i].id=i;
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	sort(a+1,a+1+e);
	for (int i=1;i<=q;i++){
		Q[i].type=red(); int x=red(),y=red(); if (x>y) swap(x,y);
		if (Q[i].type==1) Q[i].x=x,Q[i].y=y;
		 else Q[i].x=(*lower_bound(a+1,a+1+e,edge(x,y))).id,vis[Q[i].x]=1;
	}
	sort(a+1,a+1+e,cmpw);
	for (int i=1;i<=n;i++) fat[i]=i,ID[i]=i;
	for (int i=1;i<=e;i++)
	 if (!vis[a[i].id])
	 if (getfa(a[i].x)==getfa(a[i].y)) vis[a[i].id]=1;else fat[getfa(a[i].x)]=getfa(a[i].y);
	sort(a+1,a+1+e,cmpid);
	for (int i=1;i<=e;i++) if (!vis[a[i].id]) add(a[i]);
	for (int i=q;i;i--)
	 if (Q[i].type==1){
	 	mr(Q[i].x);access(Q[i].y);splay(Q[i].y);
	 	ans[++ans[0]]=mx[Q[i].y];
	 }else add(a[Q[i].x]);
	for (int i=ans[0];i>=1;i--) printf("%d\n",ans[i]);
	return 0;
}
