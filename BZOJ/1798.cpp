#include<cstdio>
#define LL long long
const int maxn=100005,INF=0x3f3f3f3f;
int n,tt,q,a[maxn];
struct node{
	node *l,*r;
	int L,R,s,add,mul;
	node(node *son=NULL,int x=0,int y=0) {l=r=son;L=x;R=y;add=0;mul=1;}
	void pushup() {s=(l->s+r->s)%tt;}
	void tag_add(LL w) {s=((R-L+1)*w%tt+s)%tt; add=(add+w)%tt;}
	void tag_mul(LL w) {s=s*w%tt; add=add*w%tt; mul=mul*w%tt;}
	void pushdown(){
		if (L==R) return;
		if (mul!=1) {l->tag_mul(mul); r->tag_mul(mul); mul=1;}
		if (add!=0) {l->tag_add(add); r->tag_add(add); add=0;}
	}
}nil;
typedef node* P_node;
P_node null,rot;
void Seg_T_init(){
	rot=null=&nil;
	null->l=null->r=null;null->s=0;
}
P_node buildtree(int l,int r){
	P_node x=new node(null,l,r);
	if (l==r) {x->s=a[l]; return x;}
	int mid=l+r>>1;
	x->l=buildtree(l,mid);x->r=buildtree(mid+1,r);
	x->pushup();return x;
}
void ist_add(P_node x,int l,int r,int w){
	if (r<x->L||x->R<l) return;
	x->pushdown();
	if (l<=x->L&&x->R<=r) {x->tag_add(w);return;}
	ist_add(x->l,l,r,w);ist_add(x->r,l,r,w);
	x->pushup();
}
void ist_mul(P_node x,int l,int r,int w){
	if (r<x->L||x->R<l) return;
	x->pushdown();
	if (l<=x->L&&x->R<=r) {x->tag_mul(w);return;}
	ist_mul(x->l,l,r,w);ist_mul(x->r,l,r,w);
	x->pushup();
}
int qry(P_node x,int l,int r){
	if (r<x->L||x->R<l) return 0;
	x->pushdown();
	if (l<=x->L&&x->R<=r) return x->s;
	return (qry(x->l,l,r)+qry(x->r,l,r))%tt;
}
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
int main(){
	Seg_T_init();
	n=red(),tt=red();
	for (int i=1;i<=n;i++) a[i]=red();
	rot=buildtree(1,n);q=red();
	while (q--){
		int c=red();
		if (c==1){
			int l=red(),r=red(),w=red();
			ist_mul(rot,l,r,w);
		}else
		if (c==2){
			int l=red(),r=red(),w=red();
			ist_add(rot,l,r,w);
		}else{
			int l=red(),r=red();
			printf("%d\n",qry(rot,l,r));
		}
	}
	return 0;
}
