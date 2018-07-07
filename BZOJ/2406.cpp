#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=405,maxe=200005,INF=0x3f3f3f3f;
int n,m,s_i[maxn],s_j[maxn],l,r,S,T,SS,TT;
int tot,lnk[maxn],son[maxe],nxt[maxe],cap[maxe],flw[maxe];
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
int d[maxn],pos[maxn],que[maxn],tmp[maxn];
bool bfs(int S,int T){
	memset(d,63,sizeof(d));
	int hed=0,til=1;
	que[1]=S;d[S]=0;
	while (hed!=til)
	 for (int j=lnk[que[++hed]];j;j=nxt[j])
	  if (d[son[j]]==INF&&flw[j]<cap[j])
	   que[++til]=son[j],d[son[j]]=d[que[hed]]+1;
	return d[T]!=INF;
}
int dfs(int x,int flow,int T){
	if (x==T||flow==0) return flow;
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
bool check(int mid){
	memset(lnk,0,sizeof(lnk));
	memset(tmp,0,sizeof(tmp));
	tot=1;
	int N=n+m;S=N+1;T=N+2;SS=N+3;TT=N+4;
	for (int i=1;i<=n;i++){
		int L=max(0,s_i[i]-mid),R=s_i[i]+mid;
		add(S,i,R-L);tmp[S]-=L;tmp[i]+=L;
	}
	for (int j=1;j<=m;j++){
		int L=max(0,s_j[j]-mid),R=s_j[j]+mid;
		add(j+n,T,R-L);tmp[j+n]-=L;tmp[T]+=L;
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  add(i,j+n,r-l),tmp[i]-=l,tmp[j+n]+=l;
	int blc=0;
	for (int i=1;i<=N+2;i++)
	 if (tmp[i]>0) add(SS,i,tmp[i]),blc+=tmp[i];else add(i,TT,-tmp[i]);
	add(T,S,INF);
	return blc==Dinic(SS,TT);
}
int main(){
	n=red(),m=red();
	for (int i=1;i<=n;i++)
	 for (int j=1,x;j<=m;j++)
	  x=red(),s_i[i]+=x,s_j[j]+=x;
	l=red(),r=red();
	int L=0,R=2e5,ans;
	while (L<=R){
		int mid=L+R>>1;
		if (check(mid)) R=mid-1,ans=mid;else L=mid+1;
	}
	printf("%d",ans);
	return 0;
}
