#include<cstdio>
const int maxn=25;
int n,n2,cst[maxn][maxn],a[maxn],b[maxn],ans=0;
bool vis[maxn];
inline void renew(int p){
	b[0]=0;
	for (int i=1;i<=n;i++)
	 if (!vis[i]) b[++b[0]]=i;
	int sum=0;
	for (int i=1;i<=p;i++)
	 for (int j=1;j<=b[0];j++)
	  sum+=cst[a[i]][b[j]];
	if (sum>ans) ans=sum;
}
void dfs(int stp,int lst){
	if (stp>n2) return;
	for (int i=lst+1;i<=n;i++)
	 if (!vis[i])
	  vis[i]=1,a[stp]=i,renew(stp),dfs(stp+1,i),vis[i]=0;
}
int main(){
	scanf("%d",&n);n2=n/2;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++) scanf("%d",&cst[i][j]);
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
