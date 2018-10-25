#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=250505,maxe=1600005,INF=0x3f3f3f3f;
int n,N,S,T,b[505][505],c[505],id[505][505];
int son[maxe],nxt[maxe],lnk[maxn],flw[maxe],cap[maxe],tot;
inline void add(int x,int y,int f){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;
}
int d[maxn],pos[maxn],que[maxn];
bool bfs(){
	cl(d,63);
	int hed=0,til=1;
	que[1]=S;d[S]=0;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j])
		 if (d[son[j]]==INF&&cap[j]>flw[j])
		  d[son[j]]=d[x]+1,que[++til]=son[j];
	}
	return d[T]!=INF;
}
int dfs(int x,int flow){
	if (x==T||flow==0) return flow;
	int f,res=0;
	for (int &j=pos[x];j;j=nxt[j])
	 if (d[son[j]]==d[x]+1&&(f=dfs(son[j],min(flow,cap[j]-flw[j])))>0){
	 	flw[j]+=f; flw[j^1]-=f;
	 	res+=f; flow-=f;
	 	if (flow==0) return res;
	 }
	return res;
}
int main(){
	scanf("%d",&n);
	S=++N;T=++N;tot=1; int sum=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  scanf("%d",&b[i][j]),id[i][j]=++N,add(S,N,b[i][j]),sum+=b[i][j];
	for (int i=1;i<=n;i++) scanf("%d",&c[i]),add(i+N,T,c[i]);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  add(id[i][j],i+N,INF),add(id[i][j],j+N,INF);
	int ans=0;
	while (bfs()){
		memcpy(pos,lnk,sizeof(pos)); 
		ans+=dfs(S,INF);
	}
	printf("%d",sum-ans);
	return 0;
}
