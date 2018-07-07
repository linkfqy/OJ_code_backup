#include<cstdio>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
#define fnd(x) (lower_bound(b+1,b+1+m,x)-b)
using namespace std;
const int maxn=10005,maxq=10005;
int tst,n,q,m,a[maxn],b[maxn+maxq],c[maxn];
struct Que{
	int t,l,r,k,bf;
}que[maxq];
struct node{
	node *l,*r;
	int s,L,R;
	node () {}
	node (int x,int y,int w): L(x),R(y),s(w) {}
	void pushup() {s=l->s+r->s;}
}nil,base[2000005];
typedef node* P_node;
P_node null,len,rot[maxn],Rot[maxn];
void Seg_T_init(){
	nil=node(0,0,0);null=&nil;
	null->l=null->r=null;len=base;
}
P_node newnode(int l,int r,int w){
	*len=node(l,r,w);return len++;
}
P_node build(int l,int r){
	P_node x=newnode(l,r,0);
	x->l=x->r=null;
	if (l==r) return x;
	int mid=l+r>>1;
	x->l=build(l,mid);x->r=build(mid+1,r);
	x->pushup(); return x;
}
P_node ist(P_node lst,int k,int d){
	P_node x=newnode(lst->L,lst->R,lst->s);
	x->l=lst->l; x->r=lst->r;
	if (x->L==x->R) {x->s+=d;return x;}
	int mid=x->L+x->R>>1;
	if (k<=mid) x->l=ist(lst->l,k,d);else
	 x->r=ist(lst->r,k,d);
	x->pushup(); return x;
}
void add(int x,int w,int d){
	for (int i=x;i<=n;i+=lowbit(i))
	 rot[i]=ist(rot[i],w,d);
}
P_node use[maxn];
int qry(P_node x,P_node y,int l,int r,int k){
	if (x->L==x->R) return b[x->L];
	int tem=y->l->s - x->l->s;
	for (int i=l;i;i-=lowbit(i)) tem-=use[i]->l->s;
	for (int i=r;i;i-=lowbit(i)) tem+=use[i]->l->s;
	if (k<=tem){
		for (int i=l;i;i-=lowbit(i)) use[i]=use[i]->l;
		for (int i=r;i;i-=lowbit(i)) use[i]=use[i]->l;
		return qry(x->l,y->l,l,r,k);
	}else{
		for (int i=l;i;i-=lowbit(i)) use[i]=use[i]->r;
		for (int i=r;i;i-=lowbit(i)) use[i]=use[i]->r;
		return qry(x->r,y->r,l,r,k-tem);
	}
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
	return tot*f;
}
int main(){
	tst=1;
	while (tst--){
		Seg_T_init();
		n=red(),q=red();
		for (int i=1;i<=n;i++) a[i]=b[i]=c[i]=red();
		b[0]=n;
		for (int i=1;i<=q;i++){
			char ch=getchar();while (ch<'A'||'Z'<ch) ch=getchar();
			if (ch=='Q'){
				que[i].t=0;que[i].l=red(),que[i].r=red(),que[i].k=red();
			}else{
				que[i].t=1;que[i].l=red(),que[i].k=red();
				que[i].bf=c[que[i].l]; c[que[i].l]=que[i].k;
				b[++b[0]]=que[i].k;
			}
		}
		sort(b+1,b+1+b[0]);
		m=unique(b+1,b+1+b[0])-b-1;
		rot[0]=Rot[0]=build(1,m);
		for (int i=1;i<=n;i++) rot[i]=rot[0],Rot[i]=ist(Rot[i-1],fnd(a[i]),1);
		for (int i=1;i<=q;i++)
		 if (que[i].t) add(que[i].l,fnd(que[i].bf),-1),add(que[i].l,fnd(que[i].k),1);else{
		 	int l=que[i].l-1,r=que[i].r,k=que[i].k;
		 	for (int j=l;j;j-=lowbit(j)) use[j]=rot[j];
			for (int j=r;j;j-=lowbit(j)) use[j]=rot[j];
		 	printf("%d\n",qry(Rot[l],Rot[r],l,r,k));
		 }
	}
	return 0;
}
