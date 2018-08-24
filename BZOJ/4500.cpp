#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=2005,maxe=2005;
int tst,n,m,e;
int son[maxe],lnk[maxn],nxt[maxe],w[maxe],tot;
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int que[maxn],dst[maxn],num[maxn];
bool vis[maxn];
bool spfa(){
	cl(vis,0);cl(dst,63);cl(num,0);
	int hed=0,til=n+m;
	for (int i=1;i<=n+m;i++) que[i]=i,dst[i]=0,vis[i]=1;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]]){
		 		vis[son[j]]=1;que[til=(til+1)%maxn]=son[j];
		 		if (++num[son[j]]>n) return 0;
			}
		 }
	}
	return 1;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d%d",&n,&m,&e);
		cl(lnk,0);tot=0;
		for (int i=1,x,y,z;i<=e;i++) scanf("%d%d%d",&x,&y,&z),add(y+n,x,z),add(x,y+n,-z);
		puts(spfa()?"Yes":"No");
	}
	return 0;
}
