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

const int maxn=200005,maxe=500005,maxs=7000005;
int n,N,m,e,q,h[maxn],b[maxn],val[maxn],fa[maxn];
struct edge{
	int x,y,w;
	bool operator<(const edge&b)const {return w<b.w;}
}a[maxe];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int tot,son[maxe],nxt[maxn],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int times,in[maxn],out[maxn],id[maxn],f[maxn][20];
void dfs(int x){
	in[x]=++times;id[times]=x;
	for (int j=lnk[x];j;j=nxt[j]) f[son[j]][0]=x,dfs(son[j]);
	out[x]=times;
}
int Rot[maxn],tre[maxs],s[maxs][2],len;
inline void pushup(int x) {tre[x]=tre[s[x][0]]+tre[s[x][1]];}
int build(int l,int r){
	int x=++len; tre[x]=0;
	if (l==r) {s[x][0]=s[x][1]=0;return x;}
	int mid=l+r>>1;
	s[x][0]=build(l,mid); s[x][1]=build(mid+1,r);
	return x;
}
int ist(int fa,int l,int r,int k){
	int x=++len; tre[x]=tre[fa];s[x][0]=s[fa][0];s[x][1]=s[fa][1];
	if (l==r) return tre[x]++,x;
	int mid=l+r>>1;
	if (k<=mid) s[x][0]=ist(s[fa][0],l,mid,k);
	 else s[x][1]=ist(s[fa][1],mid+1,r,k);
	return pushup(x),x;
}
int qry(int x,int y,int l,int r,int k){
	if (tre[y]-tre[x]<k) return -1;
	if (l==r) return -b[l];
	int mid=l+r>>1,tem;
	if ((tem=tre[s[y][0]]-tre[s[x][0]])>=k) return qry(s[x][0],s[y][0],l,mid,k);
	 else return qry(s[x][1],s[y][1],mid+1,r,k-tem);
}
int main(){
	N=n=red(),e=red(),q=red();
	for (int i=1;i<=n;i++) b[i]=h[i]=-red();
	sort(b+1,b+1+n); m=unique(b+1,b+1+n)-b-1;
	for (int i=1,x,y,z;i<=e;i++) a[i].x=red(),a[i].y=red(),a[i].w=red();
	sort(a+1,a+1+e);
	for (int i=1;i<=(n<<1);i++) fa[i]=i;
	for (int i=1;i<=e;i++)
	 if (getfa(a[i].x)!=getfa(a[i].y)){
	 	val[++N]=a[i].w;
	 	add(N,getfa(a[i].x)); add(N,getfa(a[i].y));
	 	fa[getfa(a[i].x)]=N; fa[getfa(a[i].y)]=N;
	 }
	f[N][0]=N;dfs(N);
	for (int j=1;j<20;j++)
	 for (int i=1;i<=N;i++)
	  f[i][j]=f[f[i][j-1]][j-1];
	Rot[0]=build(1,m);
	for (int i=1;i<=N;i++)
	 if (id[i]<=n) Rot[i]=ist(Rot[i-1],1,m,lower_bound(b+1,b+1+m,h[id[i]])-b);
	 else Rot[i]=Rot[i-1];
	for (int i=1;i<=q;i++){
		int v=red(),x=red(),k=red();
		for (int j=19;j>=0;j--)
		 if (val[f[v][j]]<=x) v=f[v][j];
		printf("%d\n",qry(Rot[in[v]-1],Rot[out[v]],1,m,k));
	}
	return 0;
}
