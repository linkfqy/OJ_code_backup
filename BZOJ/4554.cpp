#include<cstdio>
#include<cstring>
inline char fstchar(){
	char ch=getchar();while (ch!='*'&&ch!='#'&&ch!='x') ch=getchar();
	return ch;
}

const int maxn=5005,maxe=2505;
int n,m,h[55][55],z[55][55],Tim=0;
char a[55][55];
int tot,lnk[maxn],son[maxe],nxt[maxe];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int vis[maxn],con[maxn];
bool find(int x){
	if (vis[x]==Tim) return 0;
	vis[x]=Tim;
	for (int j=lnk[x];j;j=nxt[j]){
		int k=con[son[j]];con[son[j]]=x;
		if (!k||find(k)) return 1;
		con[son[j]]=k;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(a,'#',sizeof(a));
	for (int i=1;i<=n;i++){
		a[i][1]=fstchar();
		for (int j=2;j<=m;j++) a[i][j]=getchar();
	}
	int N=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++){
	 	if (a[i][j-1]=='#') N++;
	 	if (a[i][j]=='*') h[i][j]=N;
	 }
	int maxH=N;
	for (int j=1;j<=m;j++)
	 for (int i=1;i<=n;i++){
	 	if (a[i-1][j]=='#') N++;
	 	if (a[i][j]=='*') z[i][j]=N;
	 }
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  if (a[i][j]=='*') add(h[i][j],z[i][j]);
	int ans=0;
	for (int i=1;i<=maxH;i++)
	 Tim++,ans+=find(i);
	printf("%d",ans);
	return 0;
}
