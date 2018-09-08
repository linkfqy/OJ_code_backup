#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=1005,maxe=500005,INF=0x3f3f3f3f;
int n,e,S,T;
int tot,son[maxe],nxt[maxe],pos[maxn],lnk[maxn],flw[maxe],cap[maxe];
inline void add(int x,int y,int z){ //printf("%d %d %d\n",x,y,z);
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=z;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;
}
int cst[maxn][maxn]; ll dst[maxn];
bool vis[maxn];
void DIJ(){
	cl(dst,63);
	dst[1]=0;
	for (int i=1;i<=n;i++){
		int k;ll MIN=INF;
		for (int j=1;j<=n;j++)
		 if (!vis[j]&&dst[j]<MIN) MIN=dst[k=j];
		vis[k]=1;
		for (int j=1;j<=n;j++) dst[j]=min(dst[j],dst[k]+cst[k][j]);
	}
}
int d[maxn],que[maxn];
bool bfs(){
	cl(d,63);
	int hed=0,til=1;
	d[S]=0;que[1]=S;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j])
		 if (d[son[j]]==INF&&flw[j]<cap[j])
		  que[++til]=son[j],d[son[j]]=d[x]+1;
	}
	return d[T]!=INF;
}
ll dfs(int x,ll flow){
	if (x==T||flow==0) return flow;
	ll res=0,f;
	for (int &j=pos[x];j;j=nxt[j])
	 if (d[son[j]]==d[x]+1&&(f=dfs(son[j],min(flow,(ll)cap[j]-flw[j])))>0){
	 	flw[j]+=f; flw[j^1]-=f;
	 	res+=f; flow-=f;
	 }
	return res;
}
int main(){
	scanf("%d%d",&n,&e); S=1+n,T=n;
	cl(cst,63);
	for (int i=1,x,y,z;i<=e;i++)
	 scanf("%d%d%d",&x,&y,&z),cst[x][y]=cst[y][x]=min(cst[x][y],z);
	DIJ(); tot=1;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  if (dst[i]+cst[i][j]==dst[j]) add(i+n,j,INF);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),add(i,i+n,x),add(i+n,i,x);
	ll ans=0;
	while (bfs()){
		memcpy(pos,lnk,sizeof(lnk));
		ans+=dfs(S,1e18);
	}
	printf("%lld",ans);
	return 0;
}
