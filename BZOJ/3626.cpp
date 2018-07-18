#include<cstdio>
#include<algorithm>
#define nc getchar
#include<vector>
#define pb push_back
#define mp make_pair
using namespace std;
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=50005,maxe=maxn,maxs=maxn*4,MOD=201314;
int n,q,ans[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int fa[maxn],H_son[maxn],dep[maxn],siz[maxn],top[maxn],id[maxn],times;
void mkdep(int x,int f){
	dep[x]=dep[f]+1;fa[x]=f;siz[x]=1;
	for (int j=lnk[x];j;j=nxt[j]){
		mkdep(son[j],x);siz[x]+=siz[son[j]];
		if (!H_son[x]||siz[H_son[x]]<siz[son[j]]) H_son[x]=son[j];
	}
}
void dfs(int x,int lst){
	top[x]=lst;id[x]=++times;
	if (H_son[x]) dfs(H_son[x],lst);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=H_son[x]) dfs(son[j],son[j]);
}
int tre[maxs],tag[maxs];
inline void pushdown(int x,int L,int R){
	if (tag[x]==0||L==R) return;
	int mid=L+R>>1;
	(tre[x<<1]+=(mid-L+1)*tag[x])%=MOD; (tag[x<<1]+=tag[x])%=MOD;
	(tre[x<<1|1]+=(R-mid)*tag[x])%=MOD; (tag[x<<1|1]+=tag[x])%=MOD;
	tag[x]=0;
}
void insert(int x,int L,int R,int ql,int qr,int w){
	if (qr<L||R<ql) return;
	if (ql<=L&&R<=qr) {(tre[x]+=(R-L+1)*w)%=MOD;(tag[x]+=w)%=MOD;return;}
	int mid=L+R>>1; pushdown(x,L,R);
	insert(x<<1,L,mid,ql,qr,w);insert(x<<1|1,mid+1,R,ql,qr,w);
	tre[x]=(tre[x<<1]+tre[x<<1|1])%MOD;
}
int query(int x,int L,int R,int ql,int qr){
	if (qr<L||R<ql) return 0;
	if (ql<=L&&R<=qr) return tre[x];
	int mid=L+R>>1; pushdown(x,L,R);
	return (query(x<<1,L,mid,ql,qr)+query(x<<1|1,mid+1,R,ql,qr))%MOD;
}
void ist(int x,int y,int w){
	if (!y) return;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		insert(1,1,n,id[top[x]],id[x],w);
		x=fa[top[x]];
	}
	if (id[x]>id[y]) swap(x,y);
	insert(1,1,n,id[x],id[y],w);
}
int qry(int x,int y){
	int res=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		(res+=query(1,1,n,id[top[x]],id[x]))%=MOD;
		x=fa[top[x]];
	}
	if (id[x]>id[y]) swap(x,y);
	return (res+query(1,1,n,id[x],id[y]))%MOD;
}
vector<pair<int,int> > Ql[maxn],Qr[maxn];
int main(){
	n=red(),q=red();
	for (int i=2,fa;i<=n;i++) fa=red()+1,add(fa,i);
	mkdep(1,1);dfs(1,1);
	for (int i=1;i<=q;i++){
		int l=red()+1,r=red()+1,x=red()+1;
		Ql[l-1].pb(mp(i,x));
		Qr[r].pb(mp(i,x));
	}
	for (int i=1;i<=n;i++){
		ist(1,i,1);
		for (int j=0;j<Ql[i].size();j++)
		 (ans[Ql[i][j].first]-=qry(1,Ql[i][j].second))%=MOD;
		for (int j=0;j<Qr[i].size();j++)
		 (ans[Qr[i][j].first]+=qry(1,Qr[i][j].second))%=MOD;
	}
	for (int i=1;i<=q;i++) printf("%d\n",(ans[i]+MOD)%MOD);
	return 0;
}
