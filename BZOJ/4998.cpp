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

const int maxn=200005,maxe=400005;
int n,e,q,qx[maxe],qy[maxe],fa[maxn],f[maxn],s[maxn],dep[maxn];
bool tedge[maxe];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
//inline int getF(int x) {return F[x]==x?x:F[x]=getF(F[x]);}
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]) fa[son[j]]=x,dfs(son[j]);
}
inline void merge(int x,int y){
	x=getf(x);y=getf(y);
	while (x!=y){
		if (dep[x]<dep[y]) swap(x,y);
		int fx=getf(fa[x]);
		f[x]=fx;s[fx]+=s[x];
		x=fx;
	}
}
int main(){
	n=red(),e=red(),q=red();int E=e+q;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=E;i++){
		qx[i]=red(),qy[i]=red();
		if (getf(qx[i])!=getf(qy[i])) f[getf(qx[i])]=getf(qy[i]),tedge[i]=1,add(qx[i],qy[i]),add(qy[i],qx[i]);
	}
	for (int i=1;i<=n;i++) if (!fa[i]) fa[i]=i,dfs(i);
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1;
	for (int i=1;i<=e;i++) if (!tedge[i]) merge(qx[i],qy[i]);
	for (int i=e+1;i<=E;i++)
	 if (tedge[i]) puts("No");else{
	 	merge(qx[i],qy[i]);
	 	printf("%d\n",s[getf(qx[i])]);
	 }
	return 0;
}
