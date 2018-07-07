#include<cstdio>
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

const int maxn=100005,maxs=4*maxn;
int n,q,a[maxn],op[maxn],l[maxn],r[maxn],K;
struct node{
	node *l,*r;
	int s,tag;
	node () {}
	node (node *_l,node *_r,int _s):l(_l),r(_r),s(_s),tag(-1) {}
	inline void pushup() {s=l->s+r->s;}
	inline void pushdown(int L,int R){
		if (L==R||tag<0) return;
		int mid=L+R>>1;
		l->s=(mid-L+1)*tag;l->tag=tag;
		r->s=(R-mid)*tag;r->tag=tag;
		tag=-1;
	}
}base[maxs],nil;
typedef node* P_node;
P_node null,Rot,len;
void init(){
	nil=node(null,null,0);null=&nil;len=base;
}
P_node build(int L,int R){
	*len=node(null,null,0);
	P_node x=len++;
	if (L==R) return x;
	int mid=L+R>>1;
	x->l=build(L,mid);x->r=build(mid+1,R);
	x->pushup(); return x;
}
void insert(P_node x,int L,int R,int QL,int QR,int w){
	if (QR<L||R<QL) return;
	if (QL<=L&&R<=QR) {x->s=(R-L+1)*w;x->tag=w;return;}
	x->pushdown(L,R);
	int mid=L+R>>1;
	insert(x->l,L,mid,QL,QR,w);insert(x->r,mid+1,R,QL,QR,w);
	x->pushup();
}
int query(P_node x,int L,int R,int QL,int QR){
	if (QR<L||R<QL) return 0;
	if (QL<=L&&R<=QR) return x->s;
	x->pushdown(L,R);
	int mid=L+R>>1;
	return query(x->l,L,mid,QL,QR)+query(x->r,mid+1,R,QL,QR);
}
bool check(int mid){
	for (int i=1;i<=n;i++)
	 insert(Rot,1,n,i,i,a[i]>=mid);
	for (int i=1;i<=q;i++)
	 if (op[i]){
	 	int x=query(Rot,1,n,l[i],r[i]);
	 	insert(Rot,1,n,l[i],l[i]+x-1,1); insert(Rot,1,n,l[i]+x,r[i],0);
	 }else{
	 	int x=query(Rot,1,n,l[i],r[i]);
	 	insert(Rot,1,n,r[i]-x+1,r[i],1); insert(Rot,1,n,l[i],r[i]-x,0);
	 }
	return query(Rot,1,n,K,K);
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=red();
	for (int i=1;i<=q;i++) op[i]=red(),l[i]=red(),r[i]=red();
	K=red();
	init();Rot=build(1,n);
	int L=1,R=n,ans=1;
	while (L<=R){
		int mid=L+R>>1;
		if (check(mid)) ans=mid,L=mid+1;else R=mid-1;
	}
	printf("%d",ans);
	return 0;
}
