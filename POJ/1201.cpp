#include<cstdio>
#include<cstring>
#define nc getchar
#define cl(x,y) memset(x,y,sizeof(x))
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=50005,maxe=150005,INF=0x3f3f3f3f;
int n;
int tot,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int que[maxn],dst[maxn];
bool vis[maxn];
void spfa(){
	cl(vis,0);cl(dst,192);
	int hed=0,til=1;
	que[1]=0;dst[0]=0;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]<dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]])
		 	 vis[son[j]]=1,que[til=(til+1)%maxn]=son[j];
		 }
	}
}
int main(){
	n=red();
	for (int i=0;i<=50000;i++) add(i,i+1,0),add(i+1,i,-1);
	for (int i=1,l,r,c;i<=n;i++)
	 l=red()+1,r=red()+1,c=red(),add(l-1,r,c);
	spfa();
	printf("%d",dst[50001]);
	return 0;
} 
