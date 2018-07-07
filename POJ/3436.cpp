#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105,maxe=10105,INF=0x3f3f3f3f;
int p,n,nn,s,t,ans,in[maxn][15],ot[maxn][15],Q[maxn];
int que[maxn],id[maxn],fa[maxn];
bool vis[maxn];
struct data{
	int son[maxe],nxt[maxe],lnk[maxn],tot;
	int flw[maxe],cap[maxe],who[maxe];
	void add(int x,int y,int w){
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
		cap[tot]=w;flw[tot]=0;who[tot]=x;
	}
}a;
bool check(int x,int y){
	for (int i=1;i<=p;i++)
	 if (ot[x][i]!=2&&in[y][i]!=2&&ot[x][i]!=in[y][i]) return 0;
	return 1;
}
bool is_s(int x){
	for (int i=1;i<=p;i++)
	 if (in[x][i]==1) return 0;
	return 1;
}
bool is_t(int x){
	for (int i=1;i<=p;i++)
	 if (ot[x][i]==0) return 0;
	return 1;
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	int hed=0,til=1;
	que[1]=s;vis[s]=1;
	while (hed!=til)
	 for (int j=a.lnk[que[++hed]];j;j=a.nxt[j])
	  if (!vis[a.son[j]]&&a.cap[j]>a.flw[j]){
	  	que[++til]=a.son[j];vis[a.son[j]]=1;
	  	fa[a.son[j]]=que[hed];id[a.son[j]]=j;
	  	if (a.son[j]==t) return 1;
	  }
	return 0;
}
void EK(){
	while (bfs()){
		int Min=INF;
		for (int x=t;x!=s;x=fa[x])
		 Min=min(Min,a.cap[id[x]]-a.flw[id[x]]);
		ans+=Min;
		for (int x=t;x!=s;x=fa[x])
		 a.flw[id[x]]+=Min,a.flw[id[x]^1]-=Min;
	}
}
int main(){
	scanf("%d%d",&p,&n);nn=n*2;a.tot=1;
	s=nn+1,t=nn+2;
	for (int i=1;i<=n;i++){
		scanf("%d",&Q[i]);
		a.add(i*2-1,i*2,Q[i]);a.add(i*2,i*2-1,0);
		for (int j=1;j<=p;j++) scanf("%d",&in[i][j]);
		for (int j=1;j<=p;j++) scanf("%d",&ot[i][j]);
		for (int j=1;j<i;j++){
			if (check(i,j)) a.add(i*2,j*2-1,INF),a.add(j*2-1,i*2,0);
			if (check(j,i)) a.add(j*2,i*2-1,INF),a.add(i*2-1,j*2,0);
		}
		if (is_s(i)) a.add(s,i*2-1,INF),a.add(i*2-1,s,0);
		if (is_t(i)) a.add(i*2,t,INF),a.add(t,i*2,0);
	}
	EK();
	int num=0;
	for (int i=1;i<=n;i++)
	 for (int j=a.lnk[i*2];j;j=a.nxt[j])
	  if (a.flw[j]>0&&a.son[j]<=nn) num++;
	printf("%d %d\n",ans,num);
	for (int i=1;i<=n;i++)
	 for (int j=a.lnk[i*2];j;j=a.nxt[j])
	  if (a.flw[j]>0&&a.son[j]<=nn) printf("%d %d %d\n",i,a.son[j]+1>>1,a.flw[j]);
	return 0;
}



/*
这题一看就是典型的最大流，但是没有边权怎么办？
很简单！把一个点拆成两个点，中间连一条边容量为Qi
两个工厂之间的边，容量为无穷大 
*/
