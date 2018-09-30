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

const int maxn=150005;
int n,q,f[maxn];//ff[maxn];
inline int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
//inline int getff(int x) {return ff[x]==x?x:ff[x]=getff(ff[x]);}
int fa[maxn],s[maxn][2],sum[maxn],w[maxn],val[maxn];
bool flp[maxn];
#define fa(x) (getf(fa[x]))
#define isroot(x) (s[fa(x)][0]!=x&&s[fa(x)][1]!=x)
inline void pushup(int x) {sum[x]=sum[s[x][0]]+sum[s[x][1]]+val[x];}
inline void addflip(int x) {swap(s[x][0],s[x][1]),flp[x]^=1;}
inline void pushdown(int x) {if (flp[x]) addflip(s[x][0]),addflip(s[x][1]),flp[x]^=1;}
inline void rotate(int x){
	int f=fa(x),g=fa(f),d= s[f][0]==x;
	if (!isroot(f)) s[g][s[g][1]==f]=x; fa[x]=g;
	s[f][d^1]=s[x][d]; fa[s[x][d]]=f;
	s[x][d]=f; fa[f]=x; pushup(f); pushup(x);
}
int stk[maxn],top;
inline void splay(int x){
	stk[top=1]=x;
	for (int i=x;!isroot(i);i=fa(i)) stk[++top]=fa(i);
	while (top) pushdown(stk[top--]);
	while (!isroot(x)){
		int f=fa(x),g=fa(f),d= s[f][0]==x,dd= s[g][0]==f;
		if (!isroot(f))
		 if (d==dd) rotate(f),rotate(x);
		 else rotate(x),rotate(x);
		else rotate(x);
	}
}
inline void access(int x) {for (int t=0;x;t=x,x=fa(x)) splay(x),s[x][1]=t,pushup(x);}
inline void mr(int x) {access(x);splay(x);addflip(x);}
inline void link(int x,int y) {mr(x);fa[x]=y;}
inline int getrt(int x) {access(x);splay(x);while (s[x][0]) pushdown(x),x=s[x][0];splay(x);return x;}
void dfs(int x,int rt){
	if (s[x][0]) val[rt]+=val[s[x][0]],dfs(s[x][0],rt);
	if (s[x][1]) val[rt]+=val[s[x][1]],dfs(s[x][1],rt);
	f[x]=rt;s[x][0]=s[x][1]=0;
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) val[i]=w[i]=red(),f[i]=i;
	while (q--){
		int c=red(),x=red(),y=red();
		if (c==1){
			x=getf(x);y=getf(y);
			if (getrt(x)!=getrt(y)) link(x,y);else
			if (x!=y){
				mr(x);access(y);splay(x);
				dfs(x,x);pushup(x);
			}
		}else
		if (c==2){
			int fx=getf(x);
			mr(fx);access(fx);val[fx]+=y-w[x];w[x]=y;pushup(fx);
		}else{
			x=getf(x);y=getf(y);
			if (getrt(x)!=getrt(y)) puts("-1");
			else mr(x),access(y),splay(y),printf("%d\n",sum[y]);
		}
	}
	return 0;
}
