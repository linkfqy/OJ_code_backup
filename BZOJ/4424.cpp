#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=1000005,maxe=2000005;
int n,e,tag[maxn],dep[maxn],ans[maxe];
int son[maxe],nxt[maxe],lnk[maxn],tot,id[maxe];
bool vis[maxn];
inline void add(int x,int y,int ID){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;id[tot]=ID;
}
int ji,zi,nji,nzi;
void dfs(int x,int pre){
	vis[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (id[j]!=pre)
	  if (!vis[son[j]])
	   dep[son[j]]=dep[x]+1,dfs(son[j],id[j]),tag[x]+=tag[son[j]];
	  else if (dep[son[j]]<dep[x])
	   if ((dep[x]-dep[son[j]]+1)&1)
	    tag[x]++,tag[son[j]]--,nji++,ji=id[j];else tag[x]--,tag[son[j]]++;
}
void getans(int x,int pre){
	vis[x]=1;
	if (tag[x]==nji) ans[++ans[0]]=pre;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]) getans(son[j],id[j]);
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1,x,y;i<=e;i++){
		scanf("%d%d",&x,&y);
		if (x==y) nzi++,zi=i; else
		add(x,y,i),add(y,x,i);
	}
	for (int i=1;i<=n;i++)
	 if (!vis[i]) dep[i]=1,dfs(i,0);
	if (nji==0)
	 if (nzi)
	  if (nzi==1) return printf("1\n%d",zi),0;
	  else return puts("0"),0;
	 else{
	 	printf("%d\n",e);
	 	for (int i=1;i<=e;i++) printf("%d ",i);
	 	return 0;
	 }
	if (nzi) return puts("0"),0;
	if (nji==1) ans[++ans[0]]=ji;
	cl(vis,0);
	for (int i=1;i<=n;i++)
	 if (!vis[i]) getans(i,0);
	sort(ans+1,ans+1+ans[0]);
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
	return 0;
}
