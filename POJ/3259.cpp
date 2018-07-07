#include<cstdio>
#include<cstring>
const int maxn=505,maxe=6005;
int tst,n,e,c,dst[maxn],times[maxn],que[maxn];
int son[maxe],nxt[maxe],lnk[maxn],w[maxe],tot;
bool vis[maxn];
void add(int x,int y,int wi){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=wi;
}
bool spfa(){
	memset(dst,63,sizeof(dst));
	memset(vis,0,sizeof(vis));
	memset(times,0,sizeof(times));
	int hed=0,til=1;
	que[1]=0;dst[0]=0;times[0]++;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]]){
		 		vis[son[j]]=1;que[til=(til+1)%maxn]=son[j];
		 		times[son[j]]++;
		 		if (times[son[j]]==n) return 1;
		 	}
		 }
	}
	return 0;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		memset(lnk,0,sizeof(lnk));tot=0;
		scanf("%d%d%d",&n,&e,&c);
		for (int i=1;i<=n;i++) add(0,i,0);
		for (int i=1;i<=e;i++){
			int x,y,wi;scanf("%d%d%d",&x,&y,&wi);
			add(x,y,wi);add(y,x,wi);
		}
		for (int i=1;i<=c;i++){
			int x,y,wi;scanf("%d%d%d",&x,&y,&wi);
			add(x,y,-wi);
		}
		if (spfa()) printf("YES\n");else printf("NO\n");
	}
	return 0;
}
