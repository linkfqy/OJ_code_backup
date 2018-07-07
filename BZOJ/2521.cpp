#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=805,maxe=1000005,INF=0x3f3f3f3f;
int n,e,id,x[maxn],y[maxn],w[maxn],S,T;
int tot,son[maxe],nxt[maxe],lnk[maxn],flw[maxe],cap[maxe];
inline void add(int x,int y,int w){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=w;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;
}
int d[maxn],que[maxn],pos[maxn];
bool bfs(){
	cl(d,-1);
	int hed=0,til=1;
	que[1]=S;d[S]=0;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j])
		 if (d[son[j]]<0&&flw[j]<cap[j])
		  que[++til]=son[j],d[son[j]]=d[x]+1;
	}
	return d[T]>=0;
}
int dfs(int x,int flow){
	if (x==T||flow==0) return flow;
	int res=0,f;
	for (int &j=pos[x];j;j=nxt[j])
	 if (d[son[j]]==d[x]+1&&(f=dfs(son[j],min(flow,cap[j]-flw[j])))>0){
	 	flw[j]+=f;flw[j^1]-=f;
	 	res+=f;flow-=f;
	 	if (flow==0) break;
	 }
	return res;
}
int Dinic(){
	int res=0;
	while (bfs()){
		memcpy(pos,lnk,sizeof(lnk));
		res+=dfs(S,INF);
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&e,&id);
	for (int i=1;i<=e;i++) scanf("%d%d%d",&x[i],&y[i],&w[i]);
	tot=1;S=x[id];T=y[id];
	for (int i=1;i<=e;i++)
	 if (i!=id&&w[i]<=w[id])
	  add(x[i],y[i],w[id]-w[i]+1),add(y[i],x[i],w[id]-w[i]+1);
	printf("%d",Dinic());
	return 0;
}
