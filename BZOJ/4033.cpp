#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=2005,maxe=4005;
int n,K,s[maxn];
ll f[maxn][maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
void dfs(int x,int fa){
	s[x]=1;
	for (int i=lnk[x];i;i=nxt[i])if (son[i]!=fa){
		int y=son[i]; dfs(y,x);
		for (int j=min(K,s[x]);j>=0;j--)
		 for (int k=min(K,s[y]);k>=0;k--) if (j+k<=K)
		  f[x][j+k]=max(f[x][j+k],f[x][j]+f[y][k]+(ll)w[i]*(k*(K-k)+(s[y]-k)*(n-K-(s[y]-k))));
		s[x]+=s[y];
	}
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	dfs(1,1);
	printf("%lld",f[1][K]);
	return 0;
}
