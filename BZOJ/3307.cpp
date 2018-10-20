#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100005,maxe=200005,maxs=4000005;
int n,m,q,b[maxn],ans[maxn];
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
struct data{
	int x,y,w;
}Q[maxn];
int ls[maxs],rs[maxs],mx[maxs],len,rt[maxn];
void ist(int &x,int l,int r,int k,int w){
	if (!x) {x=++len;ls[x]=rs[x]=mx[x]=0;}
	if (l==r) {mx[x]+=w;return;}
	int mid=l+r>>1;
	if (k<=mid) ist(ls[x],l,mid,k,w);else ist(rs[x],mid+1,r,k,w);
	mx[x]=max(mx[ls[x]],mx[rs[x]]);
}
int qry(int x,int l,int r){
	if (mx[x]==0) return 0;
	if (l==r) return b[l];
	int mid=l+r>>1;
	if (mx[ls[x]]>=mx[rs[x]]) return qry(ls[x],l,mid);else return qry(rs[x],mid+1,r);
}
int merge(int x,int y,int l=1,int r=m){
	if (!x||!y) return x+y;
	if (l==r) {mx[x]+=mx[y];return x;}
	int mid=l+r>>1;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	mx[x]=max(mx[ls[x]],mx[rs[x]]);
	return x;
}
int f[maxn][17],dep[maxn];
void getdep(int x){
	dep[x]=dep[f[x][0]]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (f[x][0]!=son[j]) f[son[j]][0]=x,getdep(son[j]);
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=16;~j;j--)
	 if (dep[f[x][j]]>=dep[y]) x=f[x][j];
	if (x==y) return x;
	for (int j=16;~j;j--)
	 if (f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return f[x][0];
}
vector<int> V[maxn];
#define pb push_back
void dfs(int x){
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=f[x][0]){
	 	dfs(son[j]);
	 	rt[x]=merge(rt[x],rt[son[j]]);
	 }
	for (int i=0;i<V[x].size();i++)
	 if (V[x][i]>0) ist(rt[x],1,m,V[x][i],1);else ist(rt[x],1,m,-V[x][i],-1);
	ans[x]=qry(rt[x],1,m);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for (int i=1;i<=q;i++) scanf("%d%d%d",&Q[i].x,&Q[i].y,&Q[i].w),b[i]=Q[i].w;
	sort(b+1,b+1+q); m=unique(b+1,b+1+q)-b-1;
	for (int i=1;i<=q;i++) Q[i].w=lower_bound(b+1,b+1+m,Q[i].w)-b;
	getdep(1);
	for (int j=1;j<=16;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1];
	for (int i=1;i<=q;i++){
		int lca=LCA(Q[i].x,Q[i].y);
		V[Q[i].x].pb(Q[i].w),V[Q[i].y].pb(Q[i].w);
		V[lca].pb(-Q[i].w);V[f[lca][0]].pb(-Q[i].w);
	}
	dfs(1);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
