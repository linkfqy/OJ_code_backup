#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105,maxe=10005;
int n,m,ans=0x3f3f3f3f,dst[maxn],que[maxn];
int son[maxe],lnk[maxn],nxt[maxe],w[maxe],lvl[maxn],tot;
bool vis[maxn];
void add(int x,int y,int wi){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=wi;
}
void spfa(int L,int R){
	memset(dst,63,sizeof(dst));
	int hed=0,til=1;
	que[1]=0;dst[0]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (L<=lvl[son[j]]&&lvl[son[j]]<=R&&dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]]) vis[son[j]]=1,que[til=(til+1)%maxn]=son[j];
		 }
	}
	ans=min(ans,dst[1]);
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++){
		int p,k;scanf("%d%d%d",&p,&lvl[i],&k);
		add(0,i,p);
		while (k--){
			int x,wi;scanf("%d%d",&x,&wi);
			add(x,i,wi);
		}
	}
	for (int i=1;i<=n;i++) spfa(lvl[i],lvl[i]+m);
	printf("%d",ans);
	return 0;
}





















/*
本题有两个难点：
1.Q:如何表示物品的购买与兑换？
A:把每个物品看做点，建立0点，与所有物品的距离均为价格(p[i])
然后兑换就当做兑换物与被兑换物之间的建边，其实刷0~1的最短路即可
2.Q:如何限制等级差异问题？
A:一时没有更好的办法……，枚举一个点i，以level[i]为基准，等级不超过level[i]+M的都可以路过 
*/
