#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=32770,INF=0x3f3f3f3f;
struct node{
	node* s[2];
	int k,f,size,cnt;
	void maintain(){size=s[0]->size+s[1]->size+cnt;}
}treap[maxn],nil;
typedef node* P_node;
P_node null,len,rt;
void clear(){
	null=&nil;
	null->s[0]=null->s[1]=null;
	null->size=null->cnt=0;
	len=treap;
}
P_node newnode(int key){
	len->s[0]=len->s[1]=null;
	len->k=key;len->f=rand();
	len->size=len->cnt=1;
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
int pred(P_node x,int key){
	if (x==null) return -INF;
	if (key<=x->k) return pred(x->s[0],key);
	return max(x->k,pred(x->s[1],key));
}
int succ(P_node x,int key){
	if (x==null) return INF;
	if (key>=x->k) return succ(x->s[1],key);
	return min(x->k,succ(x->s[0],key));
}
void print(P_node x){
	if (x==null) return;
	print(x->s[0]);
	for (int i=1;i<=x->cnt;i++) printf("%d ",x->k);
	print(x->s[1]);
}
int n,ans;
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
inline int abs_(int x){
	if (x<0) return -x;return x;
}
int main(){
	clear();
	n=red();rt=null;ist(rt,INF);ist(rt,-INF);
	ans=red();ist(rt,ans);
	for (int i=1;i<n;i++){
		int x=red(),t=pred(rt,x);
		ans+=min(abs(x-t),abs(x-succ(rt,t)));
		ist(rt,x);
	}
	printf("%d",ans);
	return 0;
}




/*
µäÐÍTreap 
*/
