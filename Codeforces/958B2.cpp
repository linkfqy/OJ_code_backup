#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005,maxe=200005;
int n,v,ans,num,fa[maxn],dep[maxn],id[maxn],farson[maxn];
int lnk[maxn],son[maxe],nxt[maxe],tot;
bool vis[maxn];
void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
void dfs(int x){
	dep[x]=0;farson[x]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]){
	 	fa[son[j]]=x,dfs(son[j]);
		if (dep[son[j]]+1>dep[x]) dep[x]=dep[son[j]]+1,farson[x]=farson[son[j]];
	 }
	if (dep[x]==0) farson[x]=x;
}
bool cmp(const int &i,const int &j){
	return dep[i]>dep[j];
}
int main(){
	scanf("%d",&n);
	for (int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1);
	 v=farson[1];fa[v]=0;dfs(v);
	for (int i=1;i<=n;i++) id[i]=i;sort(id+1,id+1+n,cmp);
	vis[v]=1;printf("%d",ans=1),num=1;
	for (int t=1,i=id[t];t<=n;t++,i=id[t])
	 if (!vis[i]){
	 	for (int j=farson[i];j!=fa[i];j=fa[j])
	 	 vis[j]=1,ans++;
	 	printf(" %d",ans);num++;
	 }
	for (int i=num+1;i<=n;i++) printf(" %d",ans);
	return 0;
}
