#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=5005,maxe=20005;
int n,e,BCC,id[maxn],du[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int dfn[maxn],low[maxn],stk[maxn],times=0;
void Tarjan(int x,int fa){
	dfn[x]=low[x]=++times;stk[++stk[0]]=x;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!dfn[son[j]]){
	 	Tarjan(son[j],x); low[x]=min(low[x],low[son[j]]);
	 	if (low[son[j]]>dfn[x]){
	 		BCC++;
	 		while (stk[stk[0]]!=son[j]) id[stk[stk[0]--]]=BCC;
	 		id[stk[stk[0]--]]=BCC;
		}
	 }else if (son[j]!=fa) low[x]=min(low[x],dfn[son[j]]);
}
bool vis[maxn][maxn];
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1,x,y;i<=e;i++){
		scanf("%d%d",&x,&y);
		if (!vis[x][y]) add(x,y),add(y,x);
		vis[x][y]=vis[y][x]=1;
	}
	Tarjan(1,0); BCC++;while (stk[0]) id[stk[stk[0]--]]=BCC;
	for (int i=1;i<=n;i++)
	 for (int j=lnk[i];j;j=nxt[j])
	  if (id[i]!=id[son[j]]) du[id[i]]++,du[id[son[j]]]++;
	int leaf=0;
	for (int i=1;i<=BCC;i++) if (du[i]==2) leaf++;
	printf("%d",leaf+1>>1);
	return 0;
}
