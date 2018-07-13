#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define cl(x,y) memset(x,y,sizeof(x))
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=1005,maxe=6005;
int tst,n,e;
namespace A{
	int tot,son[maxe],nxt[maxe],lnk[maxn];
	inline void add(int x,int y){
//		printf("A: %d %d\n",x,y);
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
	}
}
namespace B{
	int tot,son[maxe],nxt[maxe],lnk[maxn],f[maxn];
	inline void add(int x,int y){
//		printf("B: %d %d\n",x,y);
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;f[y]++;
	}
}
int times,dfn[maxn],low[maxn],stk[maxn],to[maxn];
bool instk[maxn];
void Tarjan(int x){
	using namespace A;
	dfn[x]=low[x]=++times;stk[++stk[0]]=x;instk[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!dfn[son[j]]) Tarjan(son[j]),low[x]=min(low[x],low[son[j]]);else
	 if (instk[son[j]]) low[x]=min(low[x],dfn[son[j]]);
	if (dfn[x]==low[x]){
		while (stk[stk[0]+1]!=x){
			instk[stk[stk[0]]]=0;to[stk[stk[0]--]]=x;
		}
	}
}
int que[maxn];
bool topo(){
	using namespace B;
	int hed=0,til=0;
	for (int i=1;i<=n;i++)
	 if (!f[i]&&to[i]==i) que[++til]=i;
	while (hed!=til){
		if (til-hed>=2) return 0;
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j]){
			f[son[j]]--;
			if (!f[son[j]]) que[++til]=son[j];
		}
	}
	return 1;
}
int main(){
	tst=red();
	while (tst--){
		n=red(),e=red();
		A::tot=0;cl(A::lnk,0); B::tot=0;cl(B::lnk,0);cl(B::f,0);
		for (int i=1,x,y;i<=e;i++) x=red(),y=red(),A::add(x,y);
		times=0,cl(dfn,0);cl(stk,0);cl(low,0);cl(instk,0);cl(to,0);
		for (int i=1;i<=n;i++)
		 if (!dfn[i]) Tarjan(i);
		{
			using namespace A;
			for (int i=1;i<=n;i++)
			 for (int j=lnk[i];j;j=nxt[j])
			  if (to[i]!=to[son[j]]) B::add(to[i],to[son[j]]);
		}
		if (topo()) puts("I love you my love and our love save us!");else puts("Light my fire!");
	}
	return 0;
}
