#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=400005;
int n,m,q,fa[maxn];
int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n+m;i++) fa[i]=i;
	for (int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);y+=n;
		fa[getfa(x)]=getfa(y);
	}
	int ans=-1;
	for (int i=1;i<=n+m;i++) if (fa[i]==i) ans++;
	printf("%d",ans);
	return 0;
}
