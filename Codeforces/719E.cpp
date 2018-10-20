#include<cstdio>
typedef long long ll;

const int maxn=100005,maxs=400005,MOD=1e9+7;
int n,q;
struct matrix{
	int n,m;
	ll s[2][2];
	matrix () {n=m=0;s[0][0]=s[0][1]=s[1][0]=s[1][1]=0;}
}a[maxn],t,one;
inline matrix operator*(const matrix&a,const matrix&b){
	matrix c;
	c.n=a.n;c.m=b.m;
	for (int i=0;i<c.n;i++)
	 for (int j=0;j<c.m;j++)
	  for (int k=0;k<a.m;k++)
	   (c.s[i][j]+=a.s[i][k]*b.s[k][j]%MOD)%=MOD;
	return c;
}
inline matrix operator+(const matrix&a,const matrix&b){
	matrix c;
	c.n=a.n;c.m=b.m;
	for (int i=0;i<c.n;i++)
	 for (int j=0;j<c.m;j++)
	  c.s[i][j]=(a.s[i][j]+b.s[i][j])%MOD;
	return c;
}
inline bool operator==(const matrix&a,const matrix&b){
	for (int i=0;i<2;i++)
	 for (int j=0;j<2;j++)
	  if (a.s[i][j]!=b.s[i][j]) return 0;
	return 1;
}
inline matrix power(matrix a,int b){
	matrix w=a,res=one;
	while (b){
		if (b&1) res=res*w;
		w=w*w;
		b>>=1;
	}
	return res;
}
matrix m[maxs],tg[maxs];
#define ls x<<1
#define rs x<<1|1
inline void pushup(int x) {m[x]=m[ls]+m[rs];}
inline void addtg(int x,matrix w) {m[x]=w*m[x];tg[x]=w*tg[x];}
inline void pushdown(int x){
	if (!(tg[x]==one)) addtg(ls,tg[x]),addtg(rs,tg[x]),tg[x]=one;
}
void build(int x,int l,int r){
	tg[x]=one;
	if (l==r) {m[x]=a[l];return;}
	int mid=l+r>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int ql,int qr,matrix w){
	if (ql<=l&&r<=qr) {addtg(x,w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	ist(ls,l,mid,ql,qr,w); ist(rs,mid+1,r,ql,qr,w);
	pushup(x);
}
ll qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return m[x].s[1][0];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x);
	return (qry(ls,l,mid,ql,qr)+qry(rs,mid+1,r,ql,qr))%MOD;
}
int main(){
	scanf("%d%d",&n,&q);
	t.n=t.m=2; t.s[0][0]=t.s[0][1]=t.s[1][0]=1;
	one.n=one.m=2; one.s[0][0]=one.s[1][1]=1;
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a[i].n=2;a[i].m=1;a[i].s[0][0]=a[i].s[1][0]=1;
		a[i]=power(t,x-1)*a[i];
	}
	build(1,1,n);
	while (q--){
		int c;scanf("%d",&c);
		if (c==1){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			ist(1,1,n,l,r,power(t,x));
		}else{
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",qry(1,1,n,l,r));
		}
	}
	return 0;
}
