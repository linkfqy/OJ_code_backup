#include<cstdio>
#include<algorithm>
#define mp make_pair
#define X first
#define Y second
using namespace std;

const int maxn=200005,maxe=800005;
int n,e,S,T,ds,dt,fa[maxn],top;
pair<int,int> ans[maxn];
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1,x,y;i<=e;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	scanf("%d%d%d%d",&S,&T,&ds,&dt);
	for (int i=1;i<=n;i++)
	 if (i!=S&&i!=T)
	  for (int j=lnk[i];j;j=nxt[j])
	   if (son[j]!=S&&son[j]!=T)
	    if (getfa(i)!=getfa(son[j])) ans[++top]=mp(i,son[j]),fa[getfa(i)]=getfa(son[j]);
	int fs=0,ft=0;
	for (int i=1;i<=n;i++)
	 if (i!=S&&i!=T)
	  for (int j=lnk[i];j;j=nxt[j])
	   if (son[j]==S){
	   	if (getfa(i)!=getfa(S)&&fs<ds) ans[++top]=mp(i,S),fa[getfa(i)]=getfa(S),fs++;
	   }else
	   if (son[j]==T){
	   	if (getfa(i)!=getfa(T)&&ft<dt) ans[++top]=mp(i,T),fa[getfa(i)]=getfa(T),ft++;
	   }
	for (int j=lnk[S];j;j=nxt[j])
	 if (son[j]==T&&getfa(S)!=getfa(T)) ans[++top]=mp(S,T),fs++,ft++;
	if (fs>ds||ft>dt||top!=n-1) return puts("No"),0;
	puts("Yes");
	for (int i=1;i<n;i++) printf("%d %d\n",ans[i].X,ans[i].Y);
	return 0;
}
