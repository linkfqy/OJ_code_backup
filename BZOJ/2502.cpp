#include<cstdio>
#include<cstring>
#include<algorithm>
#define del_e(x) cap[x]=flw[x]=cap[x^1]=flw[x^1]=0
using namespace std;
const int maxn=105,maxe=40005,INF=0x3f3f3f3f;
int n,ans,S,T,SS,TT;
int lnk[maxn],nxt[maxe],son[maxe],tot,flw[maxe],cap[maxe];
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;cap[tot]=z;flw[tot]=0;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;cap[tot]=0;flw[tot]=0;
}
int tmp[maxn],pos[maxn],que[maxn],d[maxn];
bool bfs(int S,int T){
	memset(d,63,sizeof(d));
	int hed=0,til=1;
	que[1]=S;d[S]=0;
	while (hed!=til)
	 for (int j=lnk[que[++hed]];j;j=nxt[j])
	  if (d[son[j]]==INF&&cap[j]>flw[j])
	   que[++til]=son[j],d[son[j]]=d[que[hed]]+1;
	return d[T]!=INF;
}
int dfs(int x,int flow,int T){
	if (flow==0||x==T) return flow;
	int res=0,f;
	for (int &j=pos[x];j;j=nxt[j])
	 if (d[son[j]]==d[x]+1&&(f=dfs(son[j],min(flow,cap[j]-flw[j]),T))>0){
	 	flw[j]+=f;flw[j^1]-=f;
	 	res+=f;flow-=f;
	 	if (flow==0) break;
	 }
	return res;
}
int Dinic(int S,int T){
	int res=0;
	while (bfs(S,T)){
		memcpy(pos,lnk,sizeof(lnk));
		res+=dfs(S,INF,T);
	}
	return res;
}
inline void Del(int x){
	for (int j=lnk[x];j;j=nxt[j]) del_e(j);
}
int main(){
	n=red();S=n+1;T=n+2;SS=n+3;TT=n+4;tot=1;
	for (int i=1;i<=n;i++){
		add(S,i,INF);add(i,T,INF);
		for (int j=1,k=red(),x;j<=k;j++)
		 x=red(),add(i,x,INF),tmp[i]-=1,tmp[x]+=1;
	}
	for (int i=1;i<=n;i++)
	 if (tmp[i]>0) add(SS,i,tmp[i]);else add(i,TT,-tmp[i]);
	add(T,S,INF);
	Dinic(SS,TT);ans=flw[tot^1];
	del_e(tot);Del(SS);Del(TT);
	ans-=Dinic(T,S);
	printf("%d",ans);
	return 0;
}
