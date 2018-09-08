#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long ll;

const int maxn=100005,maxe=200005;
int n,e,fa[maxn],siz[maxn],f[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
inline bool fd(int x,int y) {for (int j=lnk[x];j;j=nxt[j]) if (son[j]==y) return 1;return 0;}
int que[maxn];
bool vis[maxn];
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1,x,y;i<=e;i++) scanf("%d%d",&x,&y),add(x,y),f[x]++;
	for (int i=1;i<=n;i++)
	 for (int j=lnk[i];j;j=nxt[j])
	  if (fd(son[j],i)) fa[getfa(i)]=getfa(son[j]);
	for (int i=1;i<=n;i++){
		int lst=-1;
		for (int j=lnk[i];j;lst=son[j],j=nxt[j])
		 if (lst>0) fa[getfa(lst)]=getfa(son[j]);
	}
	for (int i=1;i<=n;i++) siz[getfa(i)]++;
	int hed=0,til=0;
	for (int i=1;i<=n;i++)
	 if (siz[getfa(i)]>1) que[++til]=i,vis[i]=1;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j]){
			fa[getfa(son[j])]=getfa(x);
			if (!vis[son[j]]) vis[que[++til]=son[j]]=1;
		}
	}
	cl(siz,0);for (int i=1;i<=n;i++) siz[getfa(i)]++;
	ll ans=0;
	for (int i=1;i<=n;i++)
	 if (getfa(i)==i) ans+=siz[i]>1?(ll)siz[i]*(siz[i]-1):f[i];
	printf("%lld",ans);
	return 0;
}
