#include<cstdio>
#include<algorithm>
using namespace std;
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

const int maxn=500005,maxe=1000005;
int n,q,dep[maxn],f[maxn][20];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
void dfs(int x,int fa){
	f[x][0]=fa;dep[x]=dep[fa]+1;
	for (int j=lnk[x];j;j=nxt[j])
		if (son[j]!=fa) dfs(son[j],x);
}
inline void DP(){
	for (int j=1;j<20;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=19;j>=0;j--)
		if (dep[f[x][j]]>=dep[y]) x=f[x][j];
	if (x==y) return x;
	for (int j=19;j>=0;j--)
		if (f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return f[x][0];
}
int main(){
	n=red(),q=red();
	for (int i=1,x,y;i<n;i++) x=red(),y=red(),add(x,y),add(y,x);
	dfs(1,1);DP();
	while (q--){
		int x=red(),y=red(),z=red();
		int a=LCA(x,y),b=LCA(y,z),c=LCA(z,x);
		if (a==b) printf("%d",c);else
		if (b==c) printf("%d",a);else printf("%d",b);
		printf(" %d\n",dep[x]+dep[y]+dep[z]-dep[a]-dep[b]-dep[c]);
	}
	return 0;
}
