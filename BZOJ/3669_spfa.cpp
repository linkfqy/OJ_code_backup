#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=50005,maxe=200005,maxs=400005;
int n,e;
struct edge{
	int x,y,a,b;
	bool operator<(const edge&b)const {return a<b.a;}
}a[maxe];
int son[maxe],nxt[maxe],lnk[maxn],w[maxe],tot;
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int hed,til,que[maxs],dst[maxn];
bool vis[maxn];
void spfa(){
	while (hed!=til){
		int x=que[hed=(hed+1)%maxs];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]>max(dst[x],w[j])){
		 	dst[son[j]]=max(dst[x],w[j]);
		 	if (!vis[son[j]])
		 	 vis[son[j]]=1,que[til=(til+1)%maxs]=son[j];
		 }
	}
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1;i<=e;i++) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].a,&a[i].b);
	sort(a+1,a+1+e);
	cl(dst,63);dst[1]=0;
	hed=1,til=0; que[++til]=1;vis[1]=1;
	int ans=0x3f3f3f3f;
	for (int i=1;i<=e;i++){
		add(a[i].x,a[i].y,a[i].b); add(a[i].y,a[i].x,a[i].b);
		que[til=(til+1)%maxs]=a[i].x;
		que[til=(til+1)%maxs]=a[i].y; spfa();
		ans=min(ans,dst[n]+a[i].a);
	}
	printf("%d",ans>1e6?-1:ans);
	return 0;
}
