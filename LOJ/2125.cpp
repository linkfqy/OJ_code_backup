#include<cstdio>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
typedef long long ll;
using namespace std;
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

const int maxn=100005,maxe=200005;
int n,q,w[maxn];
int tot,son[maxe],lnk[maxn],nxt[maxe];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

ll c[maxn],cc[maxn];
void ist(ll *BIT,int x,ll w){
	for (int i=x;i<=n;i+=lowbit(i))
	 BIT[i]+=w;
}
ll qry(ll *BIT,int x){
	ll res=0;
	for (int i=x;i;i-=lowbit(i))
	 res+=BIT[i];
	return res;
}
void insert(int l,int r,ll w){
	ist(c,r+1,-w);ist(c,l,w);
	ist(cc,r+1,-w*r);ist(cc,l,w*(l-1));
}
ll query(int l,int r){
	l--;
	return qry(c,r)*r-qry(cc,r)-(qry(c,l)*l-qry(cc,l));
}

int dep[maxn],H_son[maxn],siz[maxn],fa[maxn],tim;
void dfs1(int x){
	dep[x]=dep[fa[x]]+1;siz[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]){
		fa[son[j]]=x;dfs1(son[j]);
		siz[x]+=siz[son[j]];
		if (siz[H_son[x]]<siz[son[j]]) H_son[x]=son[j];
	 }
}
int top[maxn],in[maxn],out[maxn];
void dfs2(int x,int tp){
	top[x]=tp;in[x]=++tim;
	if (H_son[x]) dfs2(H_son[x],tp);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa[x]&&son[j]!=H_son[x])
	  dfs2(son[j],son[j]);
	out[x]=tim;
}
ll query_path(int x,int y){
	ll res=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res+=query(in[top[x]],in[x]);
		x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	res+=query(in[x],in[y]);
	return res;
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) w[i]=red();
	for (int i=1,x,y;i<n;i++) x=red(),y=red(),add(x,y),add(y,x);
	fa[1]=1;dfs1(1);dfs2(1,1);
	for (int i=1;i<=n;i++) insert(in[i],in[i],w[i]);
	while (q--){
		int t=red();
		if (t==1){
			int x=red(),a=red();
			insert(in[x],in[x],a);
		}else
		if (t==2){
			int x=red(),a=red();
			insert(in[x],out[x],a);
		}else{
			int x=red();
			printf("%lld\n",query_path(1,x));
		}
	}
	return 0;
}
