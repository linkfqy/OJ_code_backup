#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005,maxe=maxn,maxs=2000005;
int n,m,a[maxn],b[maxn],ans[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int tre[maxs],ls[maxs],rs[maxs],len,Rot[maxn];
inline void pushup(int x) {tre[x]=tre[ls[x]]+tre[rs[x]];}
void ist(int &x,int l,int r,int k){
	if (!x) x=++len;
	if (l==r) {tre[x]++;return;}
	int mid=l+r>>1;
	if (k<=mid) ist(ls[x],l,mid,k);else ist(rs[x],mid+1,r,k);
	pushup(x);
}
int qry(int x,int l,int r,int k){
	if (l==r) return 0;
	int mid=l+r>>1;
	if (k<=mid) return qry(ls[x],l,mid,k)+tre[rs[x]];
	 else return qry(rs[x],mid+1,r,k);
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	tre[x]+=tre[y];
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	return x;
}
void dfs(int x){
	ist(Rot[x],1,m,a[x]);
	for (int j=lnk[x];j;j=nxt[j])
	 dfs(son[j]),Rot[x]=merge(Rot[x],Rot[son[j]]);
	ans[x]=qry(Rot[x],1,m,a[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n); m=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	for (int i=2,x;i<=n;i++) scanf("%d",&x),add(x,i);
	dfs(1);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
