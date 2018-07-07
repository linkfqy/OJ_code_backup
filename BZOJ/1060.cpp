#include<cstdio>
#include<algorithm>
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

const int maxn=500005,maxe=1000005;
int n,Root;
ll ans,f[maxn];
int son[maxe],nxt[maxe],lnk[maxn],w[maxe],tot;
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
void mf(int x,int fa,ll dst){
	f[x]=dst;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) mf(son[j],x,dst+w[j]),f[x]=max(f[x],f[son[j]]);
}
void dfs(int x,int fa,ll c){
	ans+=f[Root]-f[x]-c;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) dfs(son[j],x,f[Root]-f[x]);
}
int main(){
	n=red();Root=red();
	for (int i=1,x,y,z;i<n;i++) x=red(),y=red(),z=red(),add(x,y,z),add(y,x,z);
	mf(Root,0,0);
	dfs(Root,0,0);
	printf("%lld",ans);
	return 0;
}
