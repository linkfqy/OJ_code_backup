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
�����������ѵ㣺
1.Q:��α�ʾ��Ʒ�Ĺ�����һ���
A:��ÿ����Ʒ�����㣬����0�㣬��������Ʒ�ľ����Ϊ�۸�(p[i])
Ȼ��һ��͵����һ����뱻�һ���֮��Ľ��ߣ���ʵˢ0~1�����·����
2.Q:������Ƶȼ��������⣿
A:һʱû�и��õİ취������ö��һ����i����level[i]Ϊ��׼���ȼ�������level[i]+M�Ķ�����·�� 
*/
