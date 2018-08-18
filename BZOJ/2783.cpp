#include<cstdio>

const int maxn=100005,maxe=maxn;
int n,S,a[maxn],f[maxn][18],s[maxn][18],dep[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
void dfs(int x){
	for (int j=lnk[x];j;j=nxt[j])
	 dep[son[j]]=dep[x]+1,f[son[j]][0]=x,s[son[j]][0]=a[x],
	 dfs(son[j]);
}
int calc(int x){
	int res=a[x];
	for (int j=17;j>=0;j--)
	 if (res+s[x][j]<=S) res+=s[x][j],x=f[x][j];
	return res==S;
}
int main(){
	scanf("%d%d",&n,&S);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y);
	f[1][0]=1;s[1][0]=0; dfs(1);
	for (int j=1;j<=17;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1],
	  s[i][j]=s[i][j-1]+s[f[i][j-1]][j-1];
	int ans=0;
	for (int i=1;i<=n;i++) ans+=calc(i);
	printf("%d",ans);
	return 0;
}
