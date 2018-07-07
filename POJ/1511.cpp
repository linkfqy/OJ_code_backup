#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
#define LL long long
using namespace std;
#define nc getchar
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=1000005,maxe=1000005;
int tst,n,e;
int tot,son[maxe],lnk[maxn],nxt[maxe],w[maxe];
struct edge{
	int x,y,z;
	void read() {x=red(),y=red(),z=red();}
}a[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int que[maxn];
LL dst[maxn];
bool vis[maxn];
LL spfa(){
	cl(dst,63);cl(vis,0);
	int hed=0,til=1;
	que[1]=1;dst[1]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]>dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]])
		 	 vis[son[j]]=1,que[til=(til+1)%maxn]=son[j];
		 }
	}
	LL res=0;
	for (int i=1;i<=n;i++) res+=dst[i];
	return res;
}
int main(){
	tst=red();
	while (tst--){
		n=red(),e=red();
		tot=0;cl(lnk,0);
		for (int i=1;i<=e;i++)
		 a[i].read(),add(a[i].x,a[i].y,a[i].z);
		LL ans=spfa();
		tot=0;cl(lnk,0);
		for (int i=1;i<=e;i++)
		 add(a[i].y,a[i].x,a[i].z);
		printf("%lld\n",ans+spfa());
	}
	return 0;
}
