#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105,maxm=25,maxe=405,INF=0x3f3f3f3f;
int n,m,k,e,S,T,f[maxn];
bool cl[maxn][maxm],go[maxm],vis[maxm];
int tot,lnk[maxm],nxt[maxe],w[maxe],son[maxe];
void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int que[maxm],dst[maxm];
int g(int l,int r){
	memset(dst,63,sizeof(dst));
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=m;i++){
		go[i]=1;
		for (int j=l;j<=r;j++)
		 if (cl[j][i]) go[i]=0;
	}
	int hed=0,til=1;
	que[1]=S;dst[S]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxm];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (go[son[j]]&&dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]])
		 	 vis[son[j]]=0,que[til=(til+1)%maxm]=son[j];
		 }
	}
	return dst[T]==INF?INF:dst[T]*(r-l+1);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&e);S=1,T=m;
	for (int i=1,x,y,z;i<=e;i++)
	 scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	int d;scanf("%d",&d);
	while (d--){
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		for (int i=l;i<=r;i++) cl[i][x]=1;
	}
	memset(f,63,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=i;j++)
	  f[i]=min(f[i],f[j-1]+k+g(j,i));
	printf("%d",f[n]-k);
	return 0;
}
