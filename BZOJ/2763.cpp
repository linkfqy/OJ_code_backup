#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=10005,maxe=100005,maxs=maxn*12;
int n,e,K,S,T;
int tot,son[maxe],lnk[maxn],nxt[maxe],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
struct p{
	int x,t;
	p() {}
	p(int _x,int _t):x(_x),t(_t) {}
}que[maxs];
int dst[maxn][12];
bool vis[maxn][12];
void spfa(){
	cl(dst,63);cl(vis,0);
	int hed=0,til=1; que[1]=p(S,0);dst[S][0]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxs].x,t=que[hed].t;
		vis[x][t]=0;
		for (int j=lnk[x];j;j=nxt[j]){
			if (dst[son[j]][t]>dst[x][t]+w[j]){
				dst[son[j]][t]=dst[x][t]+w[j];
				if (!vis[son[j]][t]) vis[son[j]][t]=1,que[til=(til+1)%maxs]=p(son[j],t);
			}
			if (t<K&&dst[son[j]][t+1]>dst[x][t]){
				dst[son[j]][t+1]=dst[x][t];
				if (!vis[son[j]][t+1]) vis[son[j]][t+1]=1,que[til=(til+1)%maxs]=p(son[j],t+1);
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&e,&K,&S,&T);S++,T++;
	for (int i=1,x,y,z;i<=e;i++) scanf("%d%d%d",&x,&y,&z),x++,y++,add(x,y,z),add(y,x,z);
	spfa(); int ans=0x3f3f3f3f;
	for (int i=0;i<=K;i++) ans=min(ans,dst[T][i]);
	printf("%d",ans);
	return 0;
}
