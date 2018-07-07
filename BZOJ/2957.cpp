#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,q;
struct node{
	node *l,*r;
	int t,L,R;double mx;
	node () {}
	node (int _L,int _R,int _t,double _mx):L(_L),R(_R),t(_t),mx(_mx) {}
	int find(double a){
		if (L==R) return a<mx;
		if (a> l->mx) return r->find(a);
		return l->find(a)+t - l->t;
	}
	void updata(){
		mx=max(l->mx,r->mx);
		t=l->t+ r->find(l->mx);
	}
}nil,base[maxn*2];
typedef node* P_node;
P_node null,len,Rot;
void init(){
	nil=node(0,0,0,0);Rot=null=&nil;
	null->l=null->r=null;len=base;
}
P_node newnode(int L,int R,int t,double mx){
	*len=node(L,R,t,mx);
	len->l=len->r=null;
	return len++;
}
P_node build(int L,int R){
	P_node x=newnode(L,R,1,0);
	if (L==R) return x;
	int mid=L+R>>1;
	x->l=build(L,mid);x->r=build(mid+1,R);
	x->updata();return x;
}
void insert(P_node &x,int k,double w){
	if (x->L==x->R) {x->mx=w;x->t=1;return;}
	int mid=x->L+x->R>>1;
	if (k<=mid) insert(x->l,k,w);else insert(x->r,k,w);
	x->updata();
}
int main(){
	init();scanf("%d%d",&n,&q);
	Rot=build(1,n);
	while (q--){
		int x,y;scanf("%d%d",&x,&y);
		insert(Rot,x,(double)y/x);
		printf("%d\n",Rot->find(0));
	}
	return 0;
}
