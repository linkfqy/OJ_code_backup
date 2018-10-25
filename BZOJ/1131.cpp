#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000005,maxe=2000005;
int n,siz[maxn],dep[maxn]; ll ans[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
void getsiz(int x,int fa){
	siz[x]=1;dep[x]=dep[fa]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa)
	 getsiz(son[j],x),siz[x]+=siz[son[j]];
}
void dfs(int x,int fa,ll now){
	ans[x]=now;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa)
	 dfs(son[j],x,now-siz[son[j]]+n-siz[son[j]]);
}
int main(){
	scanf("%d",&n);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	getsiz(1,1); ll now=0;
	for (int i=1;i<=n;i++) now+=dep[i];
	dfs(1,1,now);
	int ID=1;
	for (int i=2;i<=n;i++)
	 if (ans[i]>ans[ID]) ID=i;
	printf("%d",ID);
	return 0;
}
