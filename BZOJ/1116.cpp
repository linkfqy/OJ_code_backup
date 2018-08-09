#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,m,fa[maxn];
bool vis[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if (getfa(x)==getfa(y)) vis[getfa(x)]=1;
		else vis[getfa(y)]=(vis[getfa(x)]|vis[getfa(y)]),fa[getfa(x)]=getfa(y);
	}
	for (int i=1;i<=n;i++)
	 if (!vis[getfa(i)]) return puts("NIE"),0;
	puts("TAK");
	return 0;
}
