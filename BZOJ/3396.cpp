#include<cstdio>
#include<cstring>
#include<algorithm>
#define nc getchar
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
inline char fstchar(){
	char ch=nc();while (ch<=32) ch=nc();
	return ch;
}

const int maxn=255,maxe=2005,INF=0x3f3f3f3f;
int e,S,T;
int tot,son[maxe],nxt[maxe],lnk[maxn],cap[maxe],flw[maxe],pos[maxn];
inline void add(int x,int y,int w){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=w;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;
}
int que[maxn],d[maxn];
bool bfs(){
	cl(d,63);
	int hed=0,til=1;
	que[til]=S;d[S]=0;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j])
		 if (d[son[j]]==INF&&flw[j]<cap[j])
		  que[++til]=son[j],d[son[j]]=d[x]+1;
	}
	return d[T]!=INF;
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
int main(){
	scanf("%d",&e);S='A',T='Z';tot=1;
	for (int i=1;i<=e;i++){
		char x=fstchar(),y=fstchar();int w;scanf("%d",&w);
		add(x,y,w);
	}
	int ans=0;
	while (bfs()){
		memcpy(pos,lnk,sizeof(pos));
		ans+=dfs(S,INF);
	}
	printf("%d",ans);
	return 0;
}
