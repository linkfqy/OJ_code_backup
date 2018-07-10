#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
#define nc getchar
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}
const int maxn=100005,maxs=400005;
int n,q,fa[maxn],dep[maxn],top[maxn],H_son[maxn],sum[maxn],in[maxn],out[maxn],times=0;
int tot,lnk[maxn],nxt[maxn],son[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
void mkH(int x){
	H_son[x]=-1;sum[x]=1;
	for (int j=lnk[x];j;j=nxt[j]){
		dep[son[j]]=dep[x]+1;
		mkH(son[j]);
		sum[x]+=sum[son[j]];
		if (H_son[x]<0||sum[H_son[x]]<sum[son[j]]) H_son[x]=son[j];
	}
}
void dfs(int x,int lst){
	top[x]=lst; in[x]=++times;
	if (H_son[x]>=0) dfs(H_son[x],lst);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=H_son[x]) dfs(son[j],son[j]);
	out[x]=times;
}
int s[maxs],tag[maxs];
inline void pushdown(int x,int L,int mid,int R){
	if (L==R||tag[x]<0) return;
	tag[x<<1]=tag[x<<1|1]=tag[x];
	s[x<<1]=tag[x]*(mid-L+1); s[x<<1|1]=tag[x]*(R-mid); tag[x]=-1;
}
void insert(int x,int L,int R,int ql,int qr,int k){
	if (L>R||qr<L||R<ql) return;
	if (ql<=L&&R<=qr) {s[x]=(R-L+1)*k,tag[x]=k;return;}
	int mid=L+R>>1; pushdown(x,L,mid,R);
	insert(x<<1,L,mid,ql,qr,k); insert(x<<1|1,mid+1,R,ql,qr,k);
	s[x]=s[x<<1]+s[x<<1|1];
}
int query(int x,int L,int R,int ql,int qr){
	if (L>R||qr<L||R<ql) return 0;
	if (ql<=L&&R<=qr) return s[x];
	int mid=L+R>>1; pushdown(x,L,mid,R);
	return query(x<<1,L,mid,ql,qr)+query(x<<1|1,mid+1,R,ql,qr);
}
void ist(int x,int y,int k){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		insert(1,1,n,in[top[x]],in[x],k);
		x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	insert(1,1,n,in[x],in[y],k);
}
int qry(int x,int y){
	int res=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res+=query(1,1,n,in[top[x]],in[x]);
		x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	res+=query(1,1,n,in[x],in[y]);
	return res; 
}
char str[20];
int main(){
	n=red();
	for (int i=1;i<n;i++) fa[i]=red(),add(fa[i],i);
	dep[0]=1;mkH(0); dfs(0,0);
	cl(tag,-1);
	q=red();
	while (q--){
		int x; scanf("%s%d",str,&x);
		if (str[0]=='i'){
			printf("%d\n",dep[x]-qry(0,x));
			ist(0,x,1);
		}else{
			printf("%d\n",query(1,1,n,in[x],out[x]));
			insert(1,1,n,in[x],out[x],0);
		}
	}
	return 0;
}
