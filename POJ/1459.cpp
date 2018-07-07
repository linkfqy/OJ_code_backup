#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105,maxe=21005;
int n,np,nc,e,s,t,que[maxn],fa[maxn],id[maxn];
bool vis[maxn];
struct data{
	int son[maxe],lnk[maxn],nxt[maxe],tot;
	int flw[maxe],cap[maxe];
	void clear() {memset(lnk,0,sizeof(lnk));tot=1;}
	void add(int x,int y,int w){
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
		cap[tot]=w;flw[tot]=0;
	}
}a;
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
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
int main(){
	while (scanf("%d%d%d%d",&n,&np,&nc,&e)==4){
		a.clear();
		for (int i=1,x,y,w;i<=e;i++)
		 x=red(),y=red(),w=red(),
		 a.add(x,y,w),a.add(y,x,0);
		s=n,t=s+1;
		for (int i=1,x,w;i<=np;i++)
		 x=red(),w=red(),a.add(s,x,w),a.add(x,s,0);
		for (int i=1,x,w;i<=nc;i++)
		 x=red(),w=red(),a.add(x,t,w),a.add(t,x,0);
		int ans=0;
		while (bfs()){
			int Min=0x3f3f3f3f;
			for (int x=t;x!=s;x=fa[x])
			 Min=min(Min,a.cap[id[x]]-a.flw[id[x]]);
			ans+=Min;
			for (int x=t;x!=s;x=fa[x])
			 a.flw[id[x]]+=Min,a.flw[id[x]^1]-=Min;
		}
		printf("%d\n",ans);
	}
	return 0;
}






/*
典型的网络最大流……没啥好说的 
*/
