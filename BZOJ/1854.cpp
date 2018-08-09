#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=10005;
int n,fa[maxn];
bool vis[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=10000;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		if (getfa(x)==getfa(y)) vis[getfa(x)]=1;
		else vis[getfa(min(x,y))]=1,fa[getfa(min(x,y))]=getfa(max(x,y));
	}
	for (int i=1;i<=10001;i++)
	 if (!vis[i]) return printf("%d",i-1),0;
	return 0;
}
