#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long ll;
using namespace std;

const int maxn=1005,maxe=1005;
int tst,n,e; ll ans1,ans2;
int tot,lnk[maxn],son[maxe],nxt[maxe];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int dfn[maxn],low[maxn],times;
bool g[maxn];
void Tarjan(int x,int fa){
	dfn[x]=low[x]=++times;int sum=0;bool suc=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!dfn[son[j]]){
	 	Tarjan(son[j],x);low[x]=min(low[x],low[son[j]]);
	 	if (low[son[j]]>=dfn[x]) suc=1;sum++;
	 }else if (son[j]!=fa) low[x]=min(low[x],dfn[son[j]]);
	g[x]=(fa&&suc||!fa&&sum>1);
}
int num,ge,vis[maxn],tag;
void dfs(int x){
	num++;ge+=g[x];vis[x]=tag;
	if (g[x]) {num--;return;}
	for (int j=lnk[x];j;j=nxt[j])
	 if (vis[son[j]]!=tag) dfs(son[j]);
}
int main(){
	for (scanf("%d",&e);e;scanf("%d",&e)){
		cl(lnk,0);tot=0;n=0;
		for (int i=1,x,y;i<=e;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x),n=max(n,max(x,y));
		cl(dfn,0);times=0;cl(g,0);
		for (int i=1;i<=n;i++) if (!dfn[i]) Tarjan(i,0);
		ans1=0;ans2=1;cl(vis,0);
		for (int i=1;i<=n;i++)
		 if (!vis[i]&&!g[i]){
		 	tag++;num=ge=0;dfs(i);
		 	if (ge==0) ans1+=2,ans2*=num*(num-1)/2;else
		 	if (ge==1) ans1+=1,ans2*=num;
		 }
		printf("Case %d: %lld %lld\n",++tst,ans1,ans2);
	}
	return 0;
}
