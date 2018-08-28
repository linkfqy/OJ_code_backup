#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
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

const int maxn=500005,maxe=1000005;
int n,K,e,fa[maxn],f[maxn],g[maxn],dep[maxn];
bool usd[maxn];
struct edge{
	int x,y,w;
	inline bool operator<(const edge&b)const {return w<b.w;}
}a[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void dfs(int x){
	dep[x]=dep[f[x]]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=f[x]) f[son[j]]=x,g[son[j]]=w[j],dfs(son[j]);
}
int main(){
	n=red(),K=red(),e=red();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1,x,y;i<=K;i++)
	 x=red(),y=red(),add(x,y,-1),add(y,x,-1),
	 fa[getfa(x)]=getfa(y);
	for (int i=1;i<=e;i++) a[i].x=red(),a[i].y=red(),a[i].w=red();
	sort(a+1,a+1+e);
	for (int i=1;i<=e;i++)
	 if (getfa(a[i].x)!=getfa(a[i].y)){
	 	fa[getfa(a[i].x)]=getfa(a[i].y);
	 	add(a[i].x,a[i].y,a[i].w),add(a[i].y,a[i].x,a[i].w);
	 	usd[i]=1;
	 }
	f[1]=1;dfs(1);
	for (int i=1;i<=n;i++) fa[i]=i;
	ll ans=0;
	for (int i=1;i<=e;i++)
	 if (!usd[i]){
	 	int x=getfa(a[i].x),y=getfa(a[i].y),w=a[i].w;
	 	while (x!=y){
	 		if (dep[x]<dep[y]) swap(x,y);
	 		if (g[x]<0) ans+=w,g[x]=w;
	 		fa[x]=getfa(f[x]); x=getfa(x);
		}
	 }
	for (int i=2;i<=n;i++)
	 if (g[i]<0) return puts("-1"),0;
	printf("%lld",ans);
	return 0;
}
