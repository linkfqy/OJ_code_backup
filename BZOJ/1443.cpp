#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))

const int maxn=20005,maxe=80005,p[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,N,id[105][105];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
char a[105][105]; bool ed[maxn],pi[maxn];
int times,vis[maxn],con[maxn];
bool find(int x){
	if (vis[x]==times) return 0;
	vis[x]=times;
	for (int j=lnk[x];j;j=nxt[j]){
		int k=con[son[j]];con[son[j]]=x;
		if (!k||find(k)) return 1;
		con[son[j]]=k;
	}
	return 0;
}
void dfs(int x){
	vis[x]=times;
	if (x<=N){
		ed[x]=1;
		for (int j=lnk[x];j;j=nxt[j])
		 if (vis[son[j]]!=times) dfs(son[j]);
	}else if (con[x]&&vis[con[x]]!=times) dfs(con[x]);
}
int main(){
	scanf("%d%d",&n,&m); N=0;
	for (int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for (int j=1;j<=m;j++)
		 if (a[i][j]=='.') id[i][j]=++N;
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++) if (a[i][j]=='.')
	  for (int t=0;t<4;t++){
	  	int x=i+p[t][0],y=j+p[t][1];
	  	if (x<1||x>n||y<1||y>m) continue;
	  	if (a[x][y]=='#') continue;
	  	add(id[i][j],id[x][y]+N);add(id[x][y]+N,id[i][j]);
	  }
	int ans=0;
	for (int i=1;i<=N;i++)
	 times++,ans+=find(i);
	if (ans==N) puts("LOSE");else{
		puts("WIN"); times++;
		for (int i=1;i<=N;i++)
		 pi[con[i+N]]=1;
		for (int i=1;i<=N;i++)
		 if (!pi[i]&&vis[i]!=times) dfs(i);
		for (int i=1;i<=N;i++) if (ed[i]){
			for (int x=1;x<=n;x++)
			 for (int y=1;y<=m;y++)
			  if (id[x][y]==i) printf("%d %d\n",x,y);
		}
	}
	return 0;
}
