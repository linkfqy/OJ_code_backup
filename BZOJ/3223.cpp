#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,q;
struct node{
	node *s[2];
	int x,size;
	bool tag;
	void maintain() {size=s[0]->size+s[1]->size+1;}
	int cmp(int&k){
		if (k<=s[0]->size) return 0;
		if (k>s[0]->size+1) {k-=s[0]->size+1;return 1;}
		return -1;
	}
}base[maxn],nil;
typedef node* P_node;
P_node null,len,rt;
void splay_init(){
	null=&nil;
	null->s[0]=null->s[1]=null;
	null->size=0;len=base;rt=len;
}
P_node newnode(int x){
	len->x=x;len->size=1;len->tag=0;
	len->s[0]=len->s[1]=null;
	return len++;
}
void pushdown(P_node &x){
	if (x->tag){
		x->tag=0;swap(x->s[0],x->s[1]);
		if (x->s[0]!=null) x->s[0]->tag^=1;
		if (x->s[1]!=null) x->s[1]->tag^=1;
	}
}
void rot(P_node &x,int d){
	P_node k=x->s[d^1];x->s[d^1]=k->s[d];k->s[d]=x;
	x->maintain();k->maintain();x=k;
}
void splay(P_node &x,int k){
	pushdown(x);
	int d1=x->cmp(k);
	if (d1!=-1){
		P_node p=x->s[d1];pushdown(p);
		int d2=p->cmp(k);
		if (d2!=-1){
			splay(p->s[d2],k);
			if (d1==d2) rot(x,d1^1),rot(x,d1^1);else
			rot(x->s[d1],d2^1),rot(x,d1^1);
		}else rot(x,d1^1);
	}
}
P_node build(int l,int r){
	if (l>r) return null;
	int mid=l+r>>1;P_node p=newnode(mid);
	p->s[0]=build(l,mid-1);p->s[1]=build(mid+1,r);
	p->maintain();
	return p;
}
void get_sec(P_node &x,int l,int r){
	l--;r++;
	splay(x,l);x->cmp(r);
	splay(x->s[1],r);
}
void print(P_node &x){
	if (x==null) return;
	pushdown(x);
	print(x->s[0]);
	if (x->x>0&&x->x<=n) printf("%d ",x->x);
	print(x->s[1]);
}
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int main(){
	n=red(),q=red();
	splay_init();
	rt=build(0,n+1);
	while (q--){
		int l=red()+1,r=red()+1;
		get_sec(rt,l,r);
		if (rt->s[1]->s[0]!=null) rt->s[1]->s[0]->tag^=1;
	}
	print(rt);
	return 0;
}



/*
Splay的裸题……注意一些细节就可以了 
*/
