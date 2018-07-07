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
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=100005,maxs=1000005;
int n,m,q,p[maxs],id[maxs],nxt[maxs];
bool vis[maxs];
void make_prime(){
	for (int i=2;i<=m;i++){
		if (!vis[i]) p[++p[0]]=i,nxt[i]=1,id[i]=p[0];
		for (int j=1;j<=p[0]&&i*p[j]<=m;j++){
			vis[i*p[j]]=1;nxt[i*p[j]]=i;
			if (i%p[j]==0) break;
		}
	}
}
struct node{
	node *l,*r;
	int s;
	node () {}
	node (node* _l,node* _r):l(_l),r(_r),s(0) {}
	void pushup() {s=l->s+r->s;}
}base[35000005],nil;
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
P_node ist(P_node fa,int k,int L,int R){
	P_node x=newnode(fa->l,fa->r);
	if (L==R) {x->s=fa->s+1;return x;}
	int mid=L+R>>1;
	if (k<=mid) x->l=ist(fa->l,k,L,mid);else x->r=ist(fa->r,k,mid+1,R);
	x->pushup(); return x;
}
int qry(P_node l,P_node r,int QL,int QR,int L,int R){
	if (QR<L||R<QL) return 0;
	if (QL<=L&&R<=QR) return r->s - l->s;
	int mid=L+R>>1;
	return qry(l->l,r->l,QL,QR,L,mid)+qry(l->r,r->r,QL,QR,mid+1,R);
}
int main(){
	n=red();m=1000000;
	make_prime();init();Rot[0]=build(1,p[0]);
	for (int i=1;i<=n;i++){
		int x=red();Rot[i]=Rot[i-1];
		for (int j=x;j>1;j=nxt[j])
		 Rot[i]=ist(Rot[i],id[j/nxt[j]],1,p[0]);
	}
	q=red();
	while (q--){
		int l=red(),r=red(),x=red(),y=red();
		int idx=lower_bound(p+1,p+1+p[0],x)-p,idy=upper_bound(p+1,p+1+p[0],y)-1-p;
		printf("%d\n",qry(Rot[l-1],Rot[r],idx,idy,1,p[0]));
	}
	return 0;
} 
