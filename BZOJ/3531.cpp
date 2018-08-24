#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005,maxe=200005,maxs=4000005;
int n,q,w[maxn],c[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int dep[maxn],siz[maxn],fa[maxn],H_son[maxn],dfn[maxn],top[maxn],times;
void getdep(int x){
	dep[x]=dep[fa[x]]+1;siz[x]=1;H_son[x]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]){
	 	fa[son[j]]=x; getdep(son[j]); siz[x]+=siz[son[j]];
	 	if (!H_son[x]||siz[H_son[x]]<siz[son[j]]) H_son[x]=son[j];
	 }
}
void dfs(int x,int lst){
	top[x]=lst; dfn[x]=++times;
	if (H_son[x]) dfs(H_son[x],lst);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]&&son[j]!=H_son[x]) dfs(son[j],son[j]);
}
int sum[maxs],mx[maxs],ls[maxs],rs[maxs],Rot[maxn],len=1;
inline void pushup(int x) {sum[x]=sum[ls[x]]+sum[rs[x]];mx[x]=max(mx[ls[x]],mx[rs[x]]);}
#define newnode() (mx[len]=sum[len]=ls[len]=rs[len]=0,len++)
void ist(int &x,int l,int r,int k,int w){
	if (!x) x=newnode();
	if (l==r) return (void)(sum[x]=mx[x]=w);
	int mid=l+r>>1;
	if (k<=mid) ist(ls[x],l,mid,k,w);else ist(rs[x],mid+1,r,k,w);
	pushup(x);
}
int qrymx(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mx[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1;
	return max(qrymx(ls[x],l,mid,ql,qr),qrymx(rs[x],mid+1,r,ql,qr));
}
int qrys(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return sum[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1;
	return qrys(ls[x],l,mid,ql,qr)+qrys(rs[x],mid+1,r,ql,qr);
}
int querymx(int x,int y,int c){
	int res=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res=max(res,qrymx(Rot[c],1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if (dfn[x]>dfn[y]) swap(x,y);
	return max(res,qrymx(Rot[c],1,n,dfn[x],dfn[y]));
}
int querys(int x,int y,int c){
	int res=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res+=qrys(Rot[c],1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if (dfn[x]>dfn[y]) swap(x,y);
	return res+qrys(Rot[c],1,n,dfn[x],dfn[y]);
}
char s[20];
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d%d",&w[i],&c[i]);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	fa[1]=1;getdep(1);dfs(1,1);
	for (int i=1;i<=n;i++) ist(Rot[c[i]],1,n,dfn[i],w[i]);
	while (q--){
		scanf("%s",s);
		if (s[1]=='C'){
			int x,cc;scanf("%d%d",&x,&cc);
			ist(Rot[c[x]],1,n,dfn[x],0);
			c[x]=cc;
			ist(Rot[c[x]],1,n,dfn[x],w[x]);
		}else
		if (s[1]=='W'){
			int x,ww;scanf("%d%d",&x,&ww);
			ist(Rot[c[x]],1,n,dfn[x],w[x]=ww);
		}else
		if (s[1]=='S'){
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",querys(x,y,c[x]));
		}else{
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",querymx(x,y,c[x]));
		}
	}
	return 0;
}
