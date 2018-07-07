#include<cstdio>
#define LL long long
const int maxn=100005;
int n,q;
LL a[maxn];
struct node{
	node *l,*r;
	int L,R;
	LL s,tag;
	node () {}
	node (int x,int y):L(x),R(y),s(0),tag(0) {}
	void pushup() {s=l->s + r->s;}
	void add_tag(LL w) {s+=w*(R-L+1);tag+=w;}
	void pushdown(){
		if (L==R) return;
		if (tag!=0) l->add_tag(tag),r->add_tag(tag),tag=0;
	}
}nil,base[maxn*2];
typedef node* P_node;
P_node null,len,Root;
void Seg_T_init(){
	nil=node(0,0);null=&nil;
	null->l=null->r=null;Root=null;len=base;
}
P_node newnode(int l,int r){
	*len=node(l,r); return len++;
}
P_node build(int l,int r){
	P_node x=newnode(l,r);
	x->l=x->r=null;
	if (l==r) {x->s=a[l];return x;}
	int mid=l+r>>1;
	x->l=build(l,mid);x->r=build(mid+1,r);
	x->pushup(); return x;
}
void ist(P_node x,int l,int r,LL w){
	if (x==null||r<x->L||x->R<l) return;
	if (l<=x->L&&x->R<=r) {x->add_tag(w);return;}
	x->pushdown();
	ist(x->l,l,r,w);ist(x->r,l,r,w);
	x->pushup();
}
LL qry(P_node x,int l,int r){
	if (x==null||r<x->L||x->R<l) return 0;
	x->pushdown();
	if (l<=x->L&&x->R<=r) return x->s;
	return qry(x->l,l,r)+qry(x->r,l,r);
}
inline LL red(){
	LL tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
inline char fstchar(){
	char ch=getchar();
	while (ch<'A'||'Z'<ch) ch=getchar();
	return ch;
}
int main(){
	Seg_T_init();
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=red();
	Root=build(1,n);
	while (q--)
	 if (fstchar()=='Q'){
	 	int l=red(),r=red();
	 	printf("%lld\n",qry(Root,l,r));
	 }else{
	 	int l=red(),r=red();LL c=red();
	 	ist(Root,l,r,c);
	 }
	return 0;
}
