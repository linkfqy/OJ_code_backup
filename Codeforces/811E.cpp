#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxn=100005,maxs=400005;
int n,m,q,A[11][maxn];
struct node{
	int s,l[11],r[11];
}T[maxs];
int fa[45],id[45];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
inline node merge(const node&a,const node&b,int m){
	node c; c.s=a.s+b.s;
	for (int i=1;i<=n;i++){
		fa[i]=a.l[i];
		fa[i+n]=a.r[i];
		fa[i+n*2]=b.l[i]+2*n;
		fa[i+n*3]=b.r[i]+2*n;
	}
	for (int i=1;i<=n;i++)
	 if (A[i][m]==A[i][m+1]&&getfa(i+n)!=getfa(i+2*n)) fa[getfa(i+n)]=getfa(i+2*n),c.s--;
	cl(id,0);
	for (int i=1;i<=n;i++){
		if (!id[getfa(i)]) id[getfa(i)]=i;
		if (!id[getfa(i+3*n)]) id[getfa(i+3*n)]=i+n;
		c.l[i]=id[getfa(i)]; c.r[i]=id[getfa(i+3*n)];
	}
	return c;
}
void build(int x,int l,int r){
	if (l==r){
		for (int i=1;i<=n;i++)
		 T[x].l[i]=T[x].r[i]=(A[i][l]!=A[i-1][l])?T[x].s++,i:T[x].l[i-1];
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	T[x]=merge(T[x<<1],T[x<<1|1],mid);
}
node qry(int x,int l,int r,int ql,int qr){
	if (ql==l&&r==qr) return T[x];
	int mid=l+r>>1;
	if (qr<=mid) return qry(x<<1,l,mid,ql,qr);else
	if (ql> mid) return qry(x<<1|1,mid+1,r,ql,qr);else
	return merge(qry(x<<1,l,mid,ql,mid),qry(x<<1|1,mid+1,r,mid+1,qr),mid);
}
int main(){
	n=red(),m=red(),q=red();
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++) A[i][j]=red();
	build(1,1,m);
	while (q--){
		int l=red(),r=red();
		printf("%d\n",qry(1,1,m,l,r).s);
	}
}
