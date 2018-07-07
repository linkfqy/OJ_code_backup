#include<cstdio>
#include<algorithm>
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=(res<<3)+(res<<1)+ch-48,ch=nc();
	return res*f;
}

const int maxn=50005,maxs=900000;
int n,m,q,a[maxn],b[maxn];
inline int ID(int x){
	return lower_bound(b+1,b+1+m,x)-b;
}
struct node{
	node *l,*r;
	int s;
	node () {}
	node (node *_l,node *_r):l(_l),r(_r),s(0) {}
	void pushup() {s=l->s+r->s;}
}nil,base[maxs];
typedef node* P_node;
P_node null,len,Rot[maxn];
void init(){
	nil=node(null,null);null=&nil;
	len=base;
}
inline P_node newnode(node *l,node *r){
	*len=node(l,r);return len++;
}
P_node build(int L,int R){
	P_node x=newnode(null,null);
	if (L==R) return x;
	int mid=L+R>>1;
	x->l=build(L,mid);x->r=build(mid+1,R);
	return x;
}
P_node insert(P_node fa,int k,int L,int R){
	P_node x=newnode(fa->l,fa->r);
	if (L==R) {x->s=fa->s+1;return x;}
	int mid=L+R>>1;
	if (k<=mid) x->l=insert(fa->l,k,L,mid);else x->r=insert(fa->r,k,mid+1,R);
	x->pushup(); return x;
}
int query(P_node l,P_node r,int k,int L,int R){
	if (L==R) return L;
	int mid=L+R>>1;
	if (k<= r->l->s - l->l->s) return query(l->l,r->l,k,L,mid);else
	 return query(l->r,r->r,k- (r->l->s - l->l->s),mid+1,R);
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) a[i]=b[i]=red();
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	init();Rot[0]=build(1,m);
	for (int i=1;i<=n;i++) Rot[i]=insert(Rot[i-1],ID(a[i]),1,m);//,printf("%d ",ID(a[i]));putchar('\n');
	q=red();
	while (q--){
		int l=red()+1,r=red()+1,k=red();k=r-l+1-k+1;
		printf("%d\n",b[query(Rot[l-1],Rot[r],k,1,m)]);
	}
	return 0;
}
