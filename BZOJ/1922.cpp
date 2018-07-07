#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;
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

const int maxn=3005,maxe=70005;
int n,e,f[maxn];
ll dst[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
bool vis[maxn];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
namespace A{
	int tot,son[maxe],nxt[maxe],lnk[maxn];
	inline void add(int x,int y){
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
	}
}
namespace B{
	int tot,son[maxe],nxt[maxe],lnk[maxn];
	inline void add(int x,int y){
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
	}
}
int main(){
	n=red(),e=red();
	for (int i=1,x,y,z;i<=e;i++) x=red(),y=red(),z=red(),add(x,y,z);
	for (int i=1;i<=n;i++){
		int k=f[i]=red();
		for (int j=1,x;j<=k;j++)
		 x=red(),A::add(x,i),B::add(i,x);
	}
	cl(dst,63);cl(vis,0);
	dst[1]=0;
	for (int i=1;i<=n;i++){
		ll Min=1ll<<62;int k;
		for (int j=1;j<=n;j++)
		 if (!vis[j]&&f[j]==0&&Min>dst[j]) Min=dst[k=j];
		vis[k]=1;
		for (int j=A::lnk[k];j;j=A::nxt[j]) f[A::son[j]]--;
		for (int j=B::lnk[k];j;j=B::nxt[j]) dst[k]=max(dst[k],dst[B::son[j]]);
		if (k==n) {printf("%lld",dst[k]);return 0;}
		for (int j=lnk[k];j;j=nxt[j])
		 if (dst[son[j]]>dst[k]+w[j]) dst[son[j]]=dst[k]+w[j];
	}
	return 0;
}
