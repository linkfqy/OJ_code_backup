#include<cstdio>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=100005;
int n,q,a[maxn];
struct node{
	node *l,*r;
	int L,R;
	LL mx,mn,s,p;
	node () {}
	node (int x,int y,LL w) {L=x;R=y;mx=mn=s=w;p=0;}
	void pushup() {mx=max(l->mx,r->mx);mn=min(l->mn,r->mn);s=l->s+r->s;}
	void plus(LL w) {mx+=w;mn+=w;s+=w*(R-L+1);p+=w;}
	void pushdown(){
		if (L==R) return;
		if (p) l->plus(p),r->plus(p),p=0;
	}
}nil,base[maxn*2];
typedef node* P_node;
P_node null,Rot,len;
void Seg_T_init(){
	nil=node(0,0,0);Rot=null=&nil;
	null->l=null->r=null;len=base;
}
P_node newnode(int x,int y,LL w){
	*len=node(x,y,w);len->l=len->r=null;
	return len++;
}
P_node buildtree(int l,int r){
	P_node x=newnode(l,r,0);
	if (l==r) {x->mx=x->mn=x->s=a[l];return x;}
	int mid=l+r>>1;
	x->l=buildtree(l,mid);x->r=buildtree(mid+1,r);
	x->pushup(); return x;
}
void ist(P_node x,int l,int r,int w){
	if (r<x->L||x->R<l) return;
	if (l<=x->L&&x->R<=r) {x->plus(w);return;}
	x->pushdown();
	ist(x->l,l,r,w);ist(x->r,l,r,w);
	x->pushup();
}
void srt(P_node x,int l,int r){
	if (r<x->L||x->R<l) return;
	if (l<=x->L&&x->R<=r)
	 if (x->mx==x->mn||x->mx-x->mn==(LL)sqrt(x->mx)-(LL)sqrt(x->mn)){
	 	LL w=(LL)sqrt(x->mx)-x->mx;
	 	x->plus(w); return;
	 }
	x->pushdown();
	srt(x->l,l,r);srt(x->r,l,r);
	x->pushup();
}
LL qry(P_node x,int l,int r){
	if (r<x->L||x->R<l) return 0;
	if (l<=x->L&&x->R<=r) return x->s;
	x->pushdown();
	return qry(x->l,l,r)+qry(x->r,l,r);
}
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
int main(){
	Seg_T_init();
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=red();
	Rot=buildtree(1,n);
	while (q--){
		int c=red();
		if (c==1){
			int l=red(),r=red(),w=red();
			ist(Rot,l,r,w);
		}else
		if (c==2){
			int l=red(),r=red();
			srt(Rot,l,r);
		}else{
			int l=red(),r=red();
			printf("%lld\n",qry(Rot,l,r));
		}
	}
	return 0;
}
