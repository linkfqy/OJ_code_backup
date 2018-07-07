#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005,maxq=50005;
struct node{
	node *s[2];
	int k,f,size,cnt;
	void maintain(){size=s[0]->size+s[1]->size+cnt;}
}treap[maxn],nil;
typedef node* P_node;
P_node len,null,rt;
void clear(){
	null=&nil;null->s[0]=null->s[1]=null;
	null->size=null->cnt=0;
	len=treap;rt=null;
}
P_node newnode(int key){
	len->s[0]=len->s[1]=null;
	len->size=len->cnt=1;
	len->k=key;len->f=rand();
	return len++;
}
void rot(P_node &x,int d){
	P_node k=x->s[d^1];x->s[d^1]=k->s[d];k->s[d]=x;
	x->maintain();k->maintain();x=k;
}
void ist(P_node &x,int key){
	if (x==null) x=newnode(key);else
	if (key==x->k) x->cnt++;else{
		int d=key>x->k;
		ist(x->s[d],key);if (x->s[d]->f > x->f) rot(x,d^1);
	}
	x->maintain();
}
void del(P_node &x,int key){
	if (x==null) return;
	if (key==x->k){
		if (x->cnt>1) x->cnt--;else
		if (x->s[0]==null) x=x->s[1];else
		if (x->s[1]==null) x=x->s[0];else{
			int d=x->s[0]->f < x->s[1]->f;
			rot(x,d^1);del(x->s[d^1],key);
		}
	}else del(x->s[key>x->k],key);
	x->maintain();
}
int kth(P_node x,int k){
	if (k<=x->s[0]->size) return kth(x->s[0],k);
	if (k>x->s[0]->size+x->cnt) return kth(x->s[1],k-x->s[0]->size-x->cnt);
	return x->k;
}
int n,q,a[maxn],id[maxq],ans[maxq];
struct ha{
	int s,t,k;
	bool operator<(const ha&b)const{
		return s<b.s||s==b.s&&t<b.t;
	}
}que[maxq];
bool mycomp(const int&i,const int&j){
	return que[i]<que[j];
}
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
int main(){
	clear();
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=red();
	for (int i=1;i<=q;i++) que[i].s=red(),que[i].t=red(),que[i].k=red(),id[i]=i;
	sort(id+1,id+1+q,mycomp);
	int l=que[id[1]].s,r=que[id[1]].t;
	for (int i=l;i<=r;i++) ist(rt,a[i]);ans[id[1]]=kth(rt,que[id[1]].k);
	for (int i=2;i<=q;i++){
		while (l<que[id[i]].s) del(rt,a[l++]);
		while (r<que[id[i]].t) ist(rt,a[++r]);
		ans[id[i]]=kth(rt,que[id[i]].k);
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}







/*
离线处理……
把所有询问都读进来排序，用毛毛虫算法使Treap符合每个区间
由于任意区间不覆盖，所以每个点都最多被加入/删除1次，复杂度就稳定在O(nlogn) 
*/
