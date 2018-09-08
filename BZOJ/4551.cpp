#include<cstdio>

const int maxn=100005,maxe=200005;
int n,q,ans[maxn],tag[maxn],f[maxn],fa[maxn];
int tot,lnk[maxn],nxt[maxe],son[maxe];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
struct data{
	char ty;int x;
}Q[maxn]; char s[25];
void dfs(int x){
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=f[x]) f[son[j]]=x,dfs(son[j]);
}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for (int i=1;i<=q;i++){
		scanf("%s%d",s,&Q[i].x); Q[i].ty=s[0];
		if (Q[i].ty=='C') tag[Q[i].x]++;
	}
	f[1]=1;dfs(1);
	for (int i=1;i<=n;i++)
	 if (tag[i]) fa[i]=i;else fa[i]=f[i];
	for (int i=q;i>=1;i--)
	 if (Q[i].ty=='Q') ans[i]=getfa(Q[i].x);else{
	 	tag[Q[i].x]--;
	 	if (!tag[Q[i].x]) fa[Q[i].x]=f[Q[i].x];
	 }
	for (int i=1;i<=q;i++)
	 if (Q[i].ty=='Q') printf("%d\n",ans[i]);
	return 0;
}
