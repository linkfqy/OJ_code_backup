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

const int maxn=40005,maxe=80005,maxs=2000005;
int n,m,q,w[maxn],b[maxn],f[maxn][18],dep[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int ls[maxs],rs[maxs],s[maxs],len,Rot[maxn];
inline void pushup(int x) {s[x]=s[ls[x]]+s[rs[x]];}
int build(int l,int r){
	int x=++len; ls[x]=rs[x]=s[x]=0;
	if (l==r) return x;
	int mid=l+r>>1;
	ls[x]=build(l,mid); rs[x]=build(mid+1,r);
	return x;
}
int ist(int lst,int l,int r,int k){
	int x=++len; ls[x]=ls[lst]; rs[x]=rs[lst]; s[x]=s[lst];
	if (l==r) return s[x]++,x;
	int mid=l+r>>1;
	if (k<=mid) ls[x]=ist(ls[lst],l,mid,k);else rs[x]=ist(rs[lst],mid+1,r,k);
	pushup(x); return x;
}
int qry(int a,int b,int c,int d,int l,int r,int k){
	if (l==r) return l;
	int tem=s[ls[a]]+s[ls[b]]-s[ls[c]]-s[ls[d]],mid=l+r>>1;
	if (k<=tem) return qry(ls[a],ls[b],ls[c],ls[d],l,mid,k);
	 else return qry(rs[a],rs[b],rs[c],rs[d],mid+1,r,k-tem);
}
void dfs(int x,int fa){
	f[x][0]=fa; dep[x]=dep[fa]+1;
	Rot[x]=ist(Rot[fa],1,m,w[x]);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) dfs(son[j],x);
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=17;~j;j--)
	 if (dep[f[x][j]]>=dep[y]) x=f[x][j];
	if (x==y) return x;
	for (int j=17;~j;j--)
	 if (f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return f[x][0];
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) b[i]=w[i]=red();
	sort(b+1,b+1+n); m=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) w[i]=lower_bound(b+1,b+1+m,w[i])-b;
	for (int i=1,x,y;i<n;i++) x=red(),y=red(),add(x,y),add(y,x);
	Rot[0]=build(1,m);dfs(1,0);
	for (int j=1;j<=17;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1];
	int lastans=0;
	while (q--){
		int x=lastans^red(),y=red(),k=red(),lca=LCA(x,y),fl=f[lca][0];
		printf("%d\n",lastans=b[qry(Rot[x],Rot[y],Rot[lca],Rot[fl],1,m,k)]);
	}
	return 0;
}
