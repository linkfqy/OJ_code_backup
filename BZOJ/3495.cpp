#include<cstdio>
#include<algorithm>
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=4000010,maxe=8000005;
int n,e,m,pre[maxn];
int tot,lnk[maxn],son[maxe],nxt[maxe];
inline void add(int x,int y){// printf("%d %d\n",x,y); 
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int dfn[maxn],low[maxn],stk[maxn],scc[maxn],Tim;
bool instk[maxn];
void tarjan(int x){
	stk[++stk[0]]=x;instk[x]=1;
	dfn[x]=low[x]=++Tim;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!dfn[son[j]]) tarjan(son[j]),low[x]=min(low[x],low[son[j]]);else
	 if (instk[son[j]]) low[x]=min(low[x],dfn[son[j]]);
	if (low[x]==dfn[x]){
		scc[0]++;
		while (stk[stk[0]+1]!=x)
		 instk[stk[stk[0]]]=0,scc[stk[stk[0]--]]=scc[0];
	}
}
int main(){
	n=red();e=red(),m=red();
	for (int i=1,x,y;i<=e;i++)
	 x=red(),y=red(),add(4*x+1,4*y),add(4*y+1,4*x);
	for (int i=1;i<=m;i++){
		int k=red(),lst=red();
		for (int j=1,x;j<k;j++) x=red(),pre[x]=lst,lst=x;
	}
	for (int i=1;i<=n;i++){
		add(4*i,4*i+2),add(4*i+3,4*i+1);
		if (pre[i]){
			int j=pre[i];
			add(4*j+2,4*i+2);add(4*i+3,4*j+3);
			add(4*j+2,4*i+1);add(4*i,4*j+3);
		}
	}
	Tim=0;int N=4*n+3;
	for (int i=4;i<=N;i++)
	 if (!dfn[i]) tarjan(i);
	for (int i=4;i<=N;i++)
	 if (scc[i]==scc[i^1]) return printf("NIE"),0;
	printf("TAK");
	return 0;
}
