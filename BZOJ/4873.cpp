#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=11005,maxe=62005,INF=0x3f3f3f3f;
int n,N,S,T,m,ans,a[105],d[105][105],id[105][105];
int son[maxe],nxt[maxe],lnk[maxn],tot=1,flw[maxe],cap[maxe];
inline void add(int x,int y,int f){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;
}
int pos[maxn],que[maxn],D[maxn];
bool bfs(){
	cl(D,63);
	int hed=0,til=1;
	que[1]=S;D[S]=0;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j])
		 if (D[son[j]]==INF&&flw[j]<cap[j])
		  que[++til]=son[j],D[son[j]]=D[x]+1;
	}
	return D[T]!=INF;
}
int dfs(int x,int flow){
	if (x==T||flow==0) return flow;
	int res=0,f;
	for (int &j=pos[x];j;j=nxt[j])
	 if (D[son[j]]==D[x]+1&&(f=dfs(son[j],min(flow,cap[j]-flw[j])))>0){
	 	flw[j]+=f; flw[j^1]-=f;
	 	res+=f; flow-=f;
	 }
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	 for (int j=i;j<=n;j++) scanf("%d",&d[i][j]);
	S=++N;T=++N;
	for (int i=1;i<=n;i++)
	 for (int j=i;j<=n;j++){
	 	id[i][j]=++N;int w=(i==j?d[i][j]-a[i]:d[i][j]);
	 	if (w>0) add(S,N,w),ans+=w;else add(N,T,-w);
	 }
	for (int i=1;i<=1000;i++) add(i+N,T,m*i*i);
	for (int i=1;i<=n;i++)
	 for (int j=i;j<=n;j++)
	  if (i==j) add(id[i][j],N+a[i],INF);
	  else{
	  	if (i<n) add(id[i][j],id[i+1][j],INF);
	  	if (j>1) add(id[i][j],id[i][j-1],INF);
	  }
	while (bfs()){
		memcpy(pos,lnk,sizeof(lnk));
		ans-=dfs(S,INF);
	}
	printf("%d",ans);
	return 0;
}
