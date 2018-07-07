#include<cstdio>
#include<cstring>
const int maxn=1005;
int tst,n,e,fa[maxn];
bool vis[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int getfa(int x){
	if (fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
int main(){
	tst=red();
	while (tst--){
		n=red(),e=red();
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1,x,y;i<=e;i++)
		 x=red(),y=red(),fa[getfa(x)]=getfa(y);
		for (int i=1;i<=n;i++) vis[getfa(i)]=1;
		int res=0;
		for (int i=1;i<=n;i++) res+=vis[i];
		printf("%d\n",res);
	}
	return 0;
}