#include<cstdio>
const int maxn=50005,maxs=1000005;
int n,q,a[maxn],lst[maxs];
struct node{
	node *l,*r;
	int L,R,s;
	node () {}
	node (int x,int y):L(x),R(y),s(0) {}
	void pushup() {s=l->s + r->s;}
}nil,base[maxs];
typedef node* P_node;
P_node null,len,rot[maxn];
void Seg_T_init(){
	nil=node(0,0);null=&nil;
	null->l=null->r=null;len=base;
}
P_node newnode(int l,int r,P_node s1,P_node s2){
	*len=node(l,r);len->l=s1;len->r=s2;
	return len++;
}
P_node build(int l,int r){
	P_node x=newnode(l,r,null,null);
	if (l==r) return x;
	int mid=l+r>>1;
	x->l=build(l,mid);x->r=build(mid+1,r);
	x->pushup(); return x;
}
P_node ist(P_node lst,int k){
	P_node x=newnode(lst->L,lst->R,lst->l,lst->r);
	x->s=lst->s;
	if (x->L==x->R) {x->s++;return x;}
	int mid=x->L+x->R>>1;
	if (k<=mid) x->l=ist(lst->l,k);else
	 x->r=ist(lst->r,k);
	x->pushup(); return x;
}
int qry(P_node l,P_node r,int k){
	if (l->L==l->R) return r->s - l->s;
	int mid=l->L+l->R>>1;
	if (k<=mid) return qry(l->l,r->l,k);else return qry(l->r,r->r,k)+ r->l->s - l->l->s;
}
void print(P_node x){
	if (x==null) return;
	print(x->l);
	if (x->L==x->R) printf("%d ",x->s);
	print(x->r);
}
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int main(){
	Seg_T_init();
	n=red();
	rot[0]=build(0,n);
	for (int i=1;i<=n;i++)
	 a[i]=red(),rot[i]=ist(rot[i-1],lst[a[i]]),lst[a[i]]=i;
	q=red();
	while (q--){
		int l=red(),r=red();
		printf("%d\n",qry(rot[l-1],rot[r],l-1));
	}
	return 0;
}
