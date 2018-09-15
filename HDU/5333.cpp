#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=100005,maxe=200005,maxs=300005;
int n,e,q,ans[maxn];
struct edge{
	int x,y,id;
	bool operator<(const edge&b)const {return y<b.y;}
}a[maxe],Q[maxn];

int s[maxs][2],fa[maxs],w[maxs],mn[maxs],ID[maxs];
bool flp[maxs];
#define isroot(x) (s[fa[x]][0]!=x&&s[fa[x]][1]!=x)
inline void addflip(int x) {swap(s[x][0],s[x][1]);flp[x]^=1;}
inline void pushup(int x){
	ID[x]=x;mn[x]=w[x];
	if (mn[s[x][0]]<mn[x]) ID[x]=ID[s[x][0]],mn[x]=mn[s[x][0]];
	if (mn[s[x][1]]<mn[x]) ID[x]=ID[s[x][1]],mn[x]=mn[s[x][1]];
}
inline void pushdown(int x) {if (flp[x]) flp[x]=0,addflip(s[x][0]),addflip(s[x][1]);}
inline void rotate(int x){
	int f=fa[x],g=fa[f],d=s[f][0]==x;
	if (!isroot(f)) s[g][s[g][1]==f]=x; fa[x]=g;
	s[f][d^1]=s[x][d]; fa[s[x][d]]=f;
	s[x][d]=f; fa[f]=x; pushup(f); pushup(x);
}
int top,stk[maxs];
inline void splay(int x){
	stk[top=1]=x;
	for (int i=x;!isroot(i);i=fa[i]) stk[++top]=fa[i];
	while (top) pushdown(stk[top--]);
	while (!isroot(x)){
		int f=fa[x],g=fa[f],d=s[f][0]==x,dd=s[g][0]==f;
		if (!isroot(f))
		 if (d==dd) rotate(f),rotate(x);else
		  rotate(x),rotate(x);else
		rotate(x);
	}
}
inline void access(int x) {for (int t=0;x;t=x,x=fa[x]) splay(x),s[x][1]=t,pushup(x);}
inline void mr(int x) {access(x);splay(x);addflip(x);}
inline void link(int x,int y) {mr(x);fa[x]=y;}
inline void cut(int x,int y) {mr(x);access(y);splay(y);s[y][0]=fa[x]=0;}
inline int getrt(int x) {access(x);splay(x);while (s[x][0]) pushdown(x),x=s[x][0];splay(x);return x;}

int BIT[maxn];
#define lowbit(x) ((x)&-(x))
void ist(int x,int w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
int qry(int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
void add(const edge&E){
	if (getrt(E.x)==getrt(E.y)){
		mr(E.x);access(E.y);splay(E.y);
		int id=ID[E.y]; if (w[id]>=E.x) return;
		cut(id,a[id-n].x);cut(id,a[id-n].y); ist(a[id-n].x,-1);
	}
	int id=E.id+n;
	mn[id]=w[id]=E.x;ID[id]=id;
	link(id,E.x);link(id,E.y); ist(E.x,1);
}
int main(){
	while (~scanf("%d%d%d",&n,&e,&q)){
		cl(fa,0);cl(s,0);cl(BIT,0);cl(flp,0);
		for (int i=1;i<=e;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
		}
		for (int i=1;i<=q;i++) scanf("%d%d",&Q[i].x,&Q[i].y),Q[i].id=i;
		sort(a+1,a+1+e);sort(Q+1,Q+1+q);
		for (int i=1;i<=e;i++) a[i].id=i;
		cl(w,63);cl(mn,63);
		for (int i=1,j=1;i<=q;i++){
			while (j<=e&&a[j].y<=Q[i].y) add(a[j++]);
			ans[Q[i].id]=n-(qry(n)-qry(Q[i].x-1));
		}
		for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
