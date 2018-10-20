#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=1505,maxe=15005,MOD=1e9+7;
int n,e,S,ans[maxe];
int son[maxe],nxt[maxe],lnk[maxn],lnk1[maxn],lnk2[maxn],w[maxe],tot;
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
inline void add(int x,int y,int z,int *lnk){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int que[maxn],dst[maxn];
bool vis[maxn];
void spfa(){
	cl(dst,63);cl(vis,0);
	int hed=0,til=1;
	que[1]=S;dst[S]=0;vis[S]=1;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]])
		 	 vis[que[til=(til+1)%maxn]=son[j]]=1;
		 }
	}
}
int f[maxn],g[maxn],f1[maxn],f2[maxn],hed,til;
void topo(int *lnk,int *f){
	hed=0,til=0;
	for (int i=1;i<=n;i++)
	 if (!f[i]) que[++til]=i;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j]){
			f[son[j]]--;
			if (f[son[j]]==0) que[++til]=son[j];
		}
	}
}
void DP(){
	cl(lnk1,0);cl(lnk2,0);tot=e;cl(f1,0);cl(f2,0);
	for (int i=1;i<=n;i++)
	 for (int j=lnk[i];j;j=nxt[j])
	  if (dst[son[j]]==dst[i]+w[j]) add(i,son[j],0,lnk1),add(son[j],i,0,lnk2),f1[son[j]]++,f2[i]++;
	topo(lnk1,f1);
	cl(f,0);cl(g,0);
	f[S]=1;
	for (int i=1;i<=til;i++){
		int x=que[i];
		for (int j=lnk1[x];j;j=nxt[j])
		 (f[son[j]]+=f[x])%=MOD;
	}
	topo(lnk2,f2);
	for (int i=1;i<=til;i++) g[que[i]]=1;
	for (int i=1;i<=til;i++){
		int x=que[i];
		for (int j=lnk2[x];j;j=nxt[j])
		 (g[son[j]]+=g[x])%=MOD;
	}
	
	for (int i=1;i<=n;i++)
	 for (int j=lnk[i];j;j=nxt[j])
	  if (dst[son[j]]==dst[i]+w[j])
	   (ans[j]+=(ll)f[i]*g[son[j]])%=MOD;
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1,x,y,z;i<=e;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z);
	for (S=1;S<=n;S++){
		spfa();DP();
	}
	for (int i=1;i<=e;i++) printf("%d\n",ans[i]);
	return 0;
}
