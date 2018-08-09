#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=100005,maxe=600005;
int n,e,fa[maxn],dep[maxn],f[maxn][20];
bool vis[maxe];
struct edge{
	int x,y,w;
	inline bool operator<(const edge&b)const {return w<b.w;}
}a[maxe];
struct data{
	int mx,cd;
	data () {}
	data (int _mx,int _cd):mx(_mx),cd(_cd) {}
}g[maxn][20];
inline data Max(data a,data b){
	if (a.mx==b.mx) return data(a.mx,max(a.cd,b.cd));
	if (a.mx<b.mx) return data(b.mx,max(a.mx,b.cd));
	return data(a.mx,max(b.mx,a.cd));
}
int tot,son[maxe],lnk[maxn],nxt[maxe],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void dfs(int x,int fa){
	f[x][0]=fa; dep[x]=dep[fa]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) g[son[j]][0]=data(w[j],0),dfs(son[j],x);
}
data LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	data res(0,0);
	for (int j=19;j>=0;j--)
	 if (dep[f[x][j]]>=dep[y]) res=Max(res,g[x][j]),x=f[x][j];
	if (x==y) return res;
	for (int j=19;j>=0;j--)
	 if (f[x][j]!=f[y][j]) res=Max(res,Max(g[x][j],g[y][j])),x=f[x][j],y=f[y][j];
	return Max(res,Max(g[x][0],g[y][0]));
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1;i<=e;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	sort(a+1,a+1+e);
	for (int i=1;i<=n;i++) fa[i]=i;
	ll sum=0;
	for (int i=1;i<=e;i++)
	 if (getfa(a[i].x)!=getfa(a[i].y)){
	 	fa[getfa(a[i].x)]=getfa(a[i].y);
	 	sum+=a[i].w; vis[i]=1;
		add(a[i].x,a[i].y,a[i].w); add(a[i].y,a[i].x,a[i].w);
	 }
	dfs(1,1);
	for (int j=1;j<=19;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1],
	  g[i][j]=Max(g[i][j-1],g[f[i][j-1]][j-1]);
	ll ans=1e17;
	for (int i=1;i<=e;i++)
	 if (!vis[i]){
	 	data t=LCA(a[i].x,a[i].y);
	 	if (t.mx<a[i].w) ans=min(ans,sum-t.mx+a[i].w);
	 	else ans=min(ans,sum-t.cd+a[i].w);
	 }
	printf("%lld",ans);
	return 0;
}
