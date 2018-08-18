#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005,maxs=4*maxn,maxe=maxn,INF=0x3f3f3f3f;
int n,q,Root,id[maxn],in[maxn],out[maxn],w[maxn],times,dep[maxn],f[maxn][18];
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
void dfs(int x){
	in[x]=++times;id[times]=x; dep[x]=dep[f[x][0]]+1;
	for (int j=lnk[x];j;j=nxt[j])
	 f[son[j]][0]=x,dfs(son[j]);
	out[x]=times;
}
int mn[maxs];
inline void pushup(int x) {mn[x]=min(mn[x<<1],mn[x<<1|1]);}
void build(int x,int l,int r){
	if (l==r) {mn[x]=w[id[l]];return;}
	int mid=l+r>>1;
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int k,int w){
	if (l==r) {mn[x]=w;return;}
	int mid=l+r>>1;
	if (k<=mid) ist(x<<1,l,mid,k,w);else ist(x<<1|1,mid+1,r,k,w);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mn[x];
	if (qr<l||r<ql) return INF;
	int mid=l+r>>1;
	return min(qry(x<<1,l,mid,ql,qr),qry(x<<1|1,mid+1,r,ql,qr));
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1,x;i<=n;i++) scanf("%d%d",&x,&w[i]),add(x,i);
	f[1][0]=1;dfs(1); Root=1;
	build(1,1,n);
	for (int j=1;j<=17;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1];
	while (q--){
		char s[20];scanf("%s",s);
		if (s[0]=='V'){
			int x,w;scanf("%d%d",&x,&w);
			ist(1,1,n,in[x],w);
		}else
		if (s[0]=='E') scanf("%d",&Root);else{
			int x,res;scanf("%d",&x);
			if (x==Root) res=mn[1];else
			if (in[x]<=in[Root]&&out[Root]<=out[x]){
				int v=Root;
				for (int j=17;~j;j--)
				 if (dep[f[v][j]]>dep[x]) v=f[v][j];
				res=min(qry(1,1,n,1,in[v]-1),qry(1,1,n,out[v]+1,n));
			}else res=qry(1,1,n,in[x],out[x]);
			printf("%d\n",res);
		}
	}
	return 0;
}
