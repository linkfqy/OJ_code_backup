#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
#define nc getchar
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=1005,maxe=1000005,INF=0x3f3f3f3f;
int e,S,D;
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int que[maxn],dst[maxn];
bool vis[maxn];
void spfa(){
	cl(dst,63);cl(vis,0);
	int hed=0,til=S;
	for (int i=1;i<=S;i++) que[i]=red(),vis[que[i]]=1,dst[que[i]]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]])
		 	 vis[son[j]]=0,que[til=(til+1)%maxn]=son[j];
		 }
	}
}
int main(){
	while (~scanf("%d%d%d",&e,&S,&D)){
		tot=0;cl(lnk,0);
		for (int i=1,x,y,z;i<=e;i++)
		 x=red(),y=red(),z=red(),add(x,y,z),add(y,x,z);
		spfa();
		int ans=INF;
		while (D--) ans=min(ans,dst[red()]);
		printf("%d\n",ans);
	}
	return 0;
}
