#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=55;
int n,a[maxn],ans=0;
bool vis[maxn],d[maxn][maxn];
void work(){
	random_shuffle(a+1,a+1+n);
	cl(vis,0);int s=0;
	for (int i=1;i<=n;i++)
	 if (!vis[a[i]]){
	 	s++;
	 	for (int j=1;j<=n;j++)
	 	 if (!d[a[i]][a[j]]) vis[a[j]]=1;
	 }
	ans=max(ans,s);
}
int main(){
	scanf("%d",&n);int x,y;
	while (~scanf("%d%d",&x,&y)) d[x][y]=d[y][x]=1;
	for (int i=1;i<=n;i++) a[i]=i;
	for (int i=1;i<=10000;i++) work();
	printf("%d",ans);
	return 0;
}
