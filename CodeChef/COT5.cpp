#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned int uint;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline uint red(){
	uint res=0;char ch=nc();
	while (ch<'0'||'9'<ch) ch=nc();
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res;
}

const int maxn=200005;
int q,m;
uint a[maxn],b[maxn];
struct data{
	uint t,a,b;
}Q[maxn];
inline int ID(uint x){
	return lower_bound(b+1,b+1+m,x)-b;
}
#define Max(x) a[x->pos_max]
struct node{
	node *l,*r;
	int L,R,pos_max,lt,rt;
	node () {}
	node (int _L,int _R):L(_L),R(_R),pos_max(_L),lt(1),rt(1) {}
	int lfind(uint o){
		if (L==R) return o<a[L];
		if (o>Max(l)) return r->lfind(o);
		return l->lfind(o)+ lt - l->lt;
	}
	int rfind(uint o){
		if (L==R) return o<a[R];
		if (o>Max(r)) return l->rfind(o);
		return r->rfind(o)+ rt - r->rt;
	}
	void pushup(){
		pos_max=(Max(l)>Max(r)?l->pos_max:r->pos_max);
		lt=l->lt + r->lfind(Max(l));
		rt=r->rt + l->rfind(Max(r));
	}
}base[maxn<<1],nil;
typedef node* P_node;
P_node null,len,Rot;
void init(){
	nil=node(0,0);Rot=null=&nil;
	null->l=null->r=null;len=base;
}
P_node newnode(int L,int R){
	*len=node(L,R);
	len->l=len->r=null;
	return len++;
}
P_node build(int L,int R){
	P_node x=newnode(L,R);
	if (L==R) return x;
	int mid=L+R>>1;
	x->l=build(L,mid);x->r=build(mid+1,R);
	return x;
}
void insert(P_node x,int k){
	if (x->L==x->R) {x->pos_max=x->L;return;}
	int mid=x->L + x->R >>1;
	if (k<=mid) insert(x->l,k);else insert(x->r,k);
	x->pushup();
}
int query_max(P_node x,int L,int R){
	if (R<x->L||x->R<L) return 0;
	if (L<=x->L&&x->R<=R) return x->pos_max;
	int l=query_max(x->l,L,R),r=query_max(x->r,L,R);
	return a[l]>a[r]?l:r;
}
int res;uint lst;
void query_L(P_node x,int L,int R){
	if (R<x->L||x->R<L) return;
	if (L<=x->L&&x->R<=R){
		res+=x->lfind(lst);lst=max(lst,Max(x));
		return;
	}
	query_L(x->l,L,R);query_L(x->r,L,R);
}
void query_R(P_node x,int L,int R){
	if (R<x->L||x->R<L) return;
	if (L<=x->L&&x->R<=R){
		res+=x->rfind(lst);lst=max(lst,Max(x));
		return;
	}
	query_R(x->r,L,R);query_R(x->l,L,R);
}
int getdep(int x){
	int ans=0;
	res=lst=0;query_L(Rot,x,m);
	ans=res;res=lst=0;query_R(Rot,1,x);
	return ans+res-2;
}
int main(){
	q=red();
	for (int i=1;i<=q;i++){
		Q[i].t=red();
		if (Q[i].t==0){
			b[++m]=Q[i].a=red();Q[i].b=red();
		}else
		if (Q[i].t==1){
			Q[i].a=red();
		}else{
			Q[i].a=red(),Q[i].b=red();
		}
	}
	sort(b+1,b+1+m);
	m=unique(b+1,b+1+m)-b-1;
	init();Rot=build(1,m);
	for (int i=1;i<=q;i++)
	 if (Q[i].t==0){
	 	int id=ID(Q[i].a);
	 	a[id]=Q[i].b;insert(Rot,id);
	 }else
	 if (Q[i].t==1){
	 	int id=ID(Q[i].a);
	 	a[id]=0;insert(Rot,id);
	 }else{
	 	int u=ID(Q[i].a),v=ID(Q[i].b);
	 	if (u>v) swap(u,v);
		int LCA=query_max(Rot,u,v);
	 	printf("%d\n",getdep(u)+getdep(v)-getdep(LCA)*2);
	 }
	 return 0;
}
